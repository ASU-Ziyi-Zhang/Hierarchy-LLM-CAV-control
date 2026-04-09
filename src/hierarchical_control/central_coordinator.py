from __future__ import annotations

from typing import Any

from .llm_client import AIMLClient, AIMLClientError
from .prompt_builder import build_central_coordinator_prompt
from .response_parser import extract_json_object, parse_coordination_intents
from .types import CoordinationIntent, CorridorSummary, LocalSignalState


class RuleBasedCoordinatorPolicy:
    """Fallback policy until a live LLM backend is attached."""

    def __init__(self, corridor_priority: str = "MAIN_CORRIDOR"):
        self.default_corridor_priority = corridor_priority

    def select_network_mode(
        self, states: dict[str, LocalSignalState], corridor_summary: CorridorSummary
    ) -> tuple[str, str, list[str]]:
        rationales: list[str] = []
        if corridor_summary.spillback_critical_count > 0:
            rationales.append("Spillback-critical intersections exist in the corridor.")
            return "SPILLBACK_PROTECTION", self.default_corridor_priority, rationales
        if corridor_summary.high_saturation_count > 0 or (
            corridor_summary.average_delay_seconds is not None and corridor_summary.average_delay_seconds >= 55.0
        ):
            rationales.append("Corridor shows high saturation or high average delay.")
            return "MAINLINE_PRIORITY", self.default_corridor_priority, rationales
        if corridor_summary.platoon_relevant_count > 0:
            rationales.append("At least one intersection is relevant for CAV platoon support.")
            return "PLATOON_SUPPORT", self.default_corridor_priority, rationales
        rationales.append("No critical corridor-wide issue detected.")
        return "BALANCED", "NONE", rationales

    def build_intents(
        self,
        states: dict[str, LocalSignalState],
        corridor_summary: CorridorSummary,
    ) -> dict[str, CoordinationIntent]:
        network_mode, corridor_priority, base_rationale = self.select_network_mode(states, corridor_summary)
        intents: dict[str, CoordinationIntent] = {}
        for intersection_id, state in states.items():
            role = "NEUTRAL"
            level = 0
            rationale = list(base_rationale)
            if network_mode == "SPILLBACK_PROTECTION":
                if state.spillback_level == "SPILLBACK_CRITICAL" or state.downstream_blocking_flag:
                    role = "PROTECT_DOWNSTREAM"
                    level = 2
                elif state.spillback_level == "SPILLBACK_WARNING":
                    role = "PROTECT_DOWNSTREAM"
                    level = 1
            elif network_mode == "MAINLINE_PRIORITY":
                if state.queue_mainline >= state.queue_side_street:
                    role = "FAVOR_MAINLINE"
                    level = 2 if state.saturation_level in {"HIGH_SATURATION", "OVERSATURATED"} else 1
                else:
                    role = "SERVE_SIDE_STREET"
                    level = 1
            elif network_mode == "PLATOON_SUPPORT":
                if state.platoon_status == "PLATOON_IMMEDIATE":
                    role = "PREPARE_PLATOON"
                    level = 2
                elif state.platoon_status == "PLATOON_CANDIDATE":
                    role = "PREPARE_PLATOON"
                    level = 1
            intents[intersection_id] = CoordinationIntent(
                intersection_id=intersection_id,
                network_mode=network_mode,
                corridor_priority=corridor_priority,
                intersection_role=role,
                adjustment_level=level,
                rationale=rationale,
            )
        return intents


class CentralCoordinator:
    """Central corridor brain with live LLM support and safe fallback behavior."""

    def __init__(
        self,
        llm_backend: Any | None = None,
        corridor_priority: str = "MAIN_CORRIDOR",
        llm_mode: str = "shadow",
        llm_model: str | None = None,
    ):
        self.rule_policy = RuleBasedCoordinatorPolicy(corridor_priority=corridor_priority)
        self.llm_mode = llm_mode
        self.llm_model = llm_model
        self.llm_backend = llm_backend if llm_backend is not None else self._build_default_backend(llm_model)

    def _build_default_backend(self, llm_model: str | None) -> AIMLClient | None:
        try:
            return AIMLClient(default_model=llm_model)
        except AIMLClientError:
            return None

    @property
    def uses_live_llm(self) -> bool:
        return self.llm_backend is not None

    def build_llm_payload(
        self,
        reports: dict[str, dict[str, Any]],
        corridor_summary: CorridorSummary,
    ) -> dict[str, Any]:
        return {
            "coordinator_type": "live_llm" if self.uses_live_llm else "rule_based_placeholder",
            "llm_mode": self.llm_mode,
            "intersection_reports": reports,
            "corridor_summary": corridor_summary.as_dict(),
        }

    def build_prompt(
        self,
        reports: dict[str, dict[str, Any]],
        corridor_summary: CorridorSummary,
    ) -> str:
        return build_central_coordinator_prompt(reports, corridor_summary)

    def _query_live_llm(
        self,
        reports: dict[str, dict[str, Any]],
        corridor_summary: CorridorSummary,
    ) -> tuple[dict[str, CoordinationIntent] | None, dict[str, Any] | None, str | None]:
        if not self.uses_live_llm:
            return None, None, "llm backend unavailable"
        prompt = self.build_prompt(reports, corridor_summary)
        try:
            response = self.llm_backend.query(prompt, model=self.llm_model)
            llm_raw = response.data if isinstance(response.data, dict) else extract_json_object(response.text)
            intents = parse_coordination_intents(llm_raw, list(reports.keys()))
            context = {
                "request_payload": response.payload,
                "response": llm_raw,
                "status_code": response.status_code,
            }
            return intents, context, None
        except Exception as exc:
            return None, None, str(exc)

    def build_intents(
        self,
        states: dict[str, LocalSignalState],
        reports: dict[str, dict[str, Any]],
        corridor_summary: CorridorSummary,
    ) -> tuple[dict[str, CoordinationIntent], dict[str, Any]]:
        payload = self.build_llm_payload(reports, corridor_summary)
        fallback_intents = self.rule_policy.build_intents(states, corridor_summary)
        chosen_intents = fallback_intents
        payload["decision_source"] = "rule_based_fallback"
        payload["fallback_intents"] = {tl_id: intent.as_dict() for tl_id, intent in fallback_intents.items()}

        llm_intents = None
        llm_context = None
        llm_error = None
        if self.uses_live_llm:
            llm_intents, llm_context, llm_error = self._query_live_llm(reports, corridor_summary)
            if llm_intents is not None:
                payload["llm_intents"] = {tl_id: intent.as_dict() for tl_id, intent in llm_intents.items()}
                payload["llm_context"] = llm_context
                if self.llm_mode == "live":
                    chosen_intents = llm_intents
                    payload["decision_source"] = "live_llm"
                else:
                    payload["decision_source"] = "shadow_llm_with_rule_execution"
            else:
                payload["llm_error"] = llm_error

        payload["network_mode"] = next(iter(chosen_intents.values())).network_mode if chosen_intents else "BALANCED"
        payload["corridor_priority"] = next(iter(chosen_intents.values())).corridor_priority if chosen_intents else "NONE"
        return chosen_intents, payload
