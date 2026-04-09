from __future__ import annotations

from .types import CoordinationIntent, LocalSignalState, SignalAgentDecision


LEVEL_TO_SECONDS = {
    0: 0.0,
    1: 2.0,
    2: 4.0,
}


class SignalAgent:
    """Per-intersection local agent."""

    def __init__(self, intersection_id: str, base_spat_plan: dict):
        self.intersection_id = intersection_id
        self.base_spat_plan = base_spat_plan

    def report_state(self, state: LocalSignalState) -> dict:
        return {
            "intersection_id": state.intersection_id,
            "current_phase_group": state.current_phase_group,
            "remaining_green": state.remaining_green,
            "delay_level": state.delay_level,
            "saturation_level": state.saturation_level,
            "spillback_level": state.spillback_level,
            "downstream_blocking_flag": state.downstream_blocking_flag,
            "platoon_status": state.platoon_status,
            "queue_mainline": state.queue_mainline,
            "queue_side_street": state.queue_side_street,
        }

    def decide(self, state: LocalSignalState, intent: CoordinationIntent) -> SignalAgentDecision:
        action = "NO_CHANGE"
        target_phase = "current"
        rationale = list(intent.rationale)

        if intent.adjustment_level <= 0:
            rationale.append("Adjustment level is zero, preserving base timing plan.")
            return SignalAgentDecision(
                intersection_id=self.intersection_id,
                role=intent.intersection_role,
                action=action,
                adjustment_level=0,
                bias_seconds=0.0,
                target_phase=target_phase,
                rationale=rationale,
            )

        if intent.intersection_role == "PROTECT_DOWNSTREAM":
            action = "TRUNCATE_CURRENT"
            rationale.append("Protect downstream storage and reduce spillback pressure.")
        elif intent.intersection_role == "FAVOR_MAINLINE":
            action = "EXTEND_CURRENT" if state.queue_mainline >= state.queue_side_street else "NEXT_CYCLE_BIAS"
            target_phase = "THROUGH"
            rationale.append("Provide limited preference to coordinated corridor movements.")
        elif intent.intersection_role == "PREPARE_PLATOON":
            action = "EXTEND_CURRENT" if state.platoon_status == "PLATOON_IMMEDIATE" else "NEXT_CYCLE_BIAS"
            target_phase = "THROUGH"
            rationale.append("Prepare service for approaching CAV platoon without reordering phases.")
        elif intent.intersection_role == "SERVE_SIDE_STREET":
            action = "NEXT_CYCLE_BIAS"
            target_phase = "TURN"
            rationale.append("Increase next-cycle side-street service using bounded bias only.")
        else:
            rationale.append("No strong local need detected; keep base timing plan.")
            intent.adjustment_level = 0

        bias_seconds = LEVEL_TO_SECONDS.get(intent.adjustment_level, 0.0)
        if action == "TRUNCATE_CURRENT":
            bias_seconds *= -1.0

        return SignalAgentDecision(
            intersection_id=self.intersection_id,
            role=intent.intersection_role,
            action=action,
            adjustment_level=intent.adjustment_level,
            bias_seconds=bias_seconds,
            target_phase=target_phase,
            rationale=rationale,
        )
