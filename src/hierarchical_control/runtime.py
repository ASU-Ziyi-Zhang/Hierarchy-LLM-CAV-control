from __future__ import annotations

from .central_coordinator import CentralCoordinator
from .local_signal_agent import SignalAgent
from .signal_execution import SignalExecutionPlanner
from .state_builder import SignalStateBuilder
from .traci_state_extractor import TraCISignalStateExtractor


class HierarchyRuntime:
    """Owns the hierarchy lifecycle and per-step orchestration."""

    def __init__(self, traci_module, conn_range: float, eval_interval: float = 30.0, llm_mode: str = "shadow", llm_model: str | None = None):
        self.traci = traci_module
        self.conn_range = conn_range
        self.eval_interval = eval_interval
        self.state_builder = SignalStateBuilder()
        self.execution_planner = SignalExecutionPlanner()
        self.state_extractor = TraCISignalStateExtractor(traci_module, self.state_builder, conn_range)
        self.coordinator = CentralCoordinator(llm_mode=llm_mode, llm_model=llm_model)
        self.signal_agents = {}
        self.log = []
        self.current_snapshot = {}
        self.last_eval_time = None

    def initialize(self, tl_info: dict):
        self.signal_agents = {
            tl_id: SignalAgent(tl_id, tl_info.get(tl_id, {}))
            for tl_id in tl_info.keys()
        }

    def ready(self) -> bool:
        return bool(self.signal_agents)

    def step(self, tl_info: dict, spat_msg: dict, sim_time: float):
        if not self.ready():
            self.initialize(tl_info)

        states = self.state_extractor.build_local_signal_states(tl_info, spat_msg, sim_time)

        should_recompute = self.last_eval_time is None or sim_time - self.last_eval_time >= self.eval_interval
        if should_recompute:
            reports = {tl_id: self.signal_agents[tl_id].report_state(state) for tl_id, state in states.items()}
            corridor_summary = self.state_builder.build_corridor_summary(states)
            intents, coordinator_context = self.coordinator.build_intents(states, reports, corridor_summary)

            decisions = {}
            execution_plan = {}
            for tl_id, state in states.items():
                agent = self.signal_agents[tl_id]
                decision = agent.decide(state, intents[tl_id])
                decisions[tl_id] = decision.as_dict()
                execution_plan[tl_id] = self.execution_planner.project(decision)

            network_mode = next(iter(intents.values())).network_mode if intents else "BALANCED"
            self.current_snapshot = {
                "sim_time": sim_time,
                "network_mode": network_mode,
                "coordinator": coordinator_context,
                "corridor_summary": corridor_summary.as_dict(),
                "states": {tl_id: state.as_dict() for tl_id, state in states.items()},
                "reports": reports,
                "intents": {tl_id: intent.as_dict() for tl_id, intent in intents.items()},
                "decisions": decisions,
                "execution_plan": execution_plan,
            }
            self.log.append(self.current_snapshot)
            self.last_eval_time = sim_time

        if self.current_snapshot:
            if self.coordinator.llm_mode == "live":
                execution_status = self.execution_planner.apply(self.traci, tl_info, states, self.current_snapshot, sim_time)
            else:
                execution_status = {
                    tl_id: {
                        "status": "shadow_noop",
                        "reason": "llm_mode=shadow",
                    }
                    for tl_id in states.keys()
                }
            self.current_snapshot["execution_status"] = execution_status
            self.current_snapshot["sim_time"] = sim_time

        return self.current_snapshot

    def describe_snapshot(self, snapshot: dict | None = None) -> list[str]:
        if snapshot is None:
            snapshot = self.current_snapshot
        if not snapshot:
            return ["[HIER] no hierarchy snapshot available yet"]

        corridor = snapshot.get("corridor_summary", {})
        coordinator = snapshot.get("coordinator", {})
        lines = [
            "[HIER] mode={mode} source={source} avg_delay={delay} high_sat={high_sat} spillback_critical={spill} platoon_relevant={platoon}".format(
                mode=snapshot.get("network_mode", "BALANCED"),
                source=coordinator.get("decision_source", coordinator.get("coordinator_type", "unknown")),
                delay="n/a" if corridor.get("average_delay_seconds") is None else f"{corridor.get('average_delay_seconds'):.1f}s",
                high_sat=corridor.get("high_saturation_count", 0),
                spill=corridor.get("spillback_critical_count", 0),
                platoon=corridor.get("platoon_relevant_count", 0),
            )
        ]

        decisions = snapshot.get("decisions", {})
        highlighted = []
        for tl_id, decision in decisions.items():
            if decision.get("adjustment_level", 0) > 0 or decision.get("action") != "NO_CHANGE":
                highlighted.append(
                    f"{tl_id}:{decision.get('role','NEUTRAL')}/{decision.get('action','NO_CHANGE')}/{decision.get('bias_seconds', 0.0):+.1f}s"
                )
        if highlighted:
            lines.append("[HIER-ACTS] " + " | ".join(highlighted[:4]))
        else:
            lines.append("[HIER-ACTS] all intersections currently remain on NO_CHANGE")

        if coordinator.get("llm_error"):
            lines.append(f"[HIER-LLM] fallback due to error: {coordinator.get('llm_error')}")
        elif coordinator.get("llm_intents") and coordinator.get("decision_source") == "shadow_llm_with_rule_execution":
            lines.append("[HIER-LLM] live LLM responded in shadow mode; base vehicle-level control remains active")
        elif coordinator.get("decision_source") == "live_llm":
            lines.append("[HIER-LLM] live LLM intents are active")

        execution_status = snapshot.get("execution_status", {})
        if execution_status and all(status.get("status") == "shadow_noop" for status in execution_status.values()):
            lines.append("[HIER-EXEC] shadow mode active; no timing bias applied")
            return lines

        executed = []
        queued = []
        for tl_id, status in execution_status.items():
            if status.get("status") == "applied":
                executed.append(f"{tl_id}:{status.get('source','apply')}:{status.get('applied_bias_seconds', 0.0):+.1f}s")
            elif status.get("status") == "queued":
                queued.append(f"{tl_id}:{status.get('target_phase_group','OTHER')}:{status.get('queued_bias_seconds', 0.0):+.1f}s")

        if executed:
            lines.append("[HIER-EXEC] " + " | ".join(executed[:4]))
        elif queued:
            lines.append("[HIER-EXEC] queued " + " | ".join(queued[:4]))
        else:
            lines.append("[HIER-EXEC] no executable timing bias applied in the current step")

        return lines
