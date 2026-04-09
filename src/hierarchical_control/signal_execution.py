from __future__ import annotations

from typing import Any

from .types import LocalSignalState, SignalAgentDecision


class SignalExecutionPlanner:
    """Project and apply bounded timing biases to the active SUMO signal plan."""

    def __init__(self):
        self.phase_tracker: dict[str, dict[str, Any]] = {}
        self.pending_biases: dict[str, dict[str, Any]] = {}
        self.last_execution_status: dict[str, dict[str, Any]] = {}

    def project(self, decision: SignalAgentDecision) -> dict:
        return {
            "intersection_id": decision.intersection_id,
            "action": decision.action,
            "bias_seconds": decision.bias_seconds,
            "target_phase": decision.target_phase,
            "constrained_by_base_plan": decision.constrained_by_base_plan,
        }

    def _target_group(self, target_phase: str) -> str:
        if target_phase in {"THROUGH", "mainline"}:
            return "THROUGH"
        if target_phase in {"TURN", "side_street"}:
            return "TURN"
        return "OTHER"

    def _ensure_tracker(self, tl_id: str, current_phase: int):
        tracker = self.phase_tracker.setdefault(
            tl_id,
            {
                "current_phase": current_phase,
                "applied_in_phase": False,
            },
        )
        if tracker["current_phase"] != current_phase:
            tracker["current_phase"] = current_phase
            tracker["applied_in_phase"] = False
        return tracker

    def _compute_new_remaining(self, tl_info: dict, tl_id: str, current_phase: int, current_remaining: float, bias_seconds: float) -> float:
        timing_table = tl_info.get(tl_id, {}).get("timingTable", [])
        if 1 <= current_phase <= len(timing_table):
            phase_row = timing_table[current_phase - 1]
            max_duration = float(phase_row[5]) if phase_row[5] is not None else current_remaining
        else:
            max_duration = current_remaining

        upper = max(max_duration, current_remaining)
        proposed = current_remaining + bias_seconds
        return max(1.0, min(proposed, upper))

    def _apply_bias(self, traci_module, tl_info: dict, tl_id: str, state: LocalSignalState, bias_seconds: float, sim_time: float) -> dict:
        current_remaining = max(0.0, traci_module.trafficlight.getNextSwitch(tl_id) - sim_time)
        if current_remaining <= 0.0:
            current_remaining = max(0.0, state.remaining_green)

        new_remaining = self._compute_new_remaining(tl_info, tl_id, state.current_phase, current_remaining, bias_seconds)
        traci_module.trafficlight.setPhaseDuration(tl_id, new_remaining)
        return {
            "status": "applied",
            "applied_bias_seconds": bias_seconds,
            "new_remaining_green": new_remaining,
        }

    def apply(self, traci_module, tl_info: dict, states: dict[str, LocalSignalState], snapshot: dict, sim_time: float) -> dict[str, dict[str, Any]]:
        execution_status: dict[str, dict[str, Any]] = {}
        decisions = snapshot.get("decisions", {}) if snapshot else {}

        for tl_id, state in states.items():
            tracker = self._ensure_tracker(tl_id, state.current_phase)
            status = {"status": "idle"}

            pending = self.pending_biases.get(tl_id)
            if pending and not tracker["applied_in_phase"] and state.current_phase_group == pending["target_phase_group"]:
                applied = self._apply_bias(traci_module, tl_info, tl_id, state, pending["bias_seconds"], sim_time)
                tracker["applied_in_phase"] = True
                status = {
                    **applied,
                    "source": "pending_next_cycle",
                    "target_phase_group": pending["target_phase_group"],
                }
                del self.pending_biases[tl_id]

            decision = decisions.get(tl_id)
            if decision is None:
                execution_status[tl_id] = status
                continue

            action = decision.get("action", "NO_CHANGE")
            bias_seconds = float(decision.get("bias_seconds", 0.0))
            target_phase = self._target_group(decision.get("target_phase", "OTHER"))

            if action in {"EXTEND_CURRENT", "TRUNCATE_CURRENT"} and not tracker["applied_in_phase"]:
                applied = self._apply_bias(traci_module, tl_info, tl_id, state, bias_seconds, sim_time)
                tracker["applied_in_phase"] = True
                status = {
                    **applied,
                    "source": "current_phase_action",
                    "target_phase_group": state.current_phase_group,
                }
            elif action == "NEXT_CYCLE_BIAS":
                self.pending_biases[tl_id] = {
                    "bias_seconds": bias_seconds,
                    "target_phase_group": target_phase,
                    "queued_at": sim_time,
                }
                status = {
                    "status": "queued",
                    "queued_bias_seconds": bias_seconds,
                    "target_phase_group": target_phase,
                }
            elif status["status"] == "idle":
                status = {
                    "status": "no_change",
                    "target_phase_group": target_phase,
                }

            execution_status[tl_id] = status

        self.last_execution_status = execution_status
        return execution_status
