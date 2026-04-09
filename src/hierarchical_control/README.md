# Hierarchical Control Package

This package hosts the optional corridor-level hierarchy that sits above the
existing vehicle-level CAV controller.

## Modules
- `types.py`: shared dataclasses for local state, corridor summary, intent, and decision
- `state_builder.py`: converts raw simulation measurements into local/corridor summaries
- `local_signal_agent.py`: per-intersection reporting and local action projection
- `central_coordinator.py`: central brain interface and rule-based fallback policy
- `signal_execution.py`: bounded projection of timing bias into SUMO
- `traci_state_extractor.py`: runtime adapter that pulls local states from TraCI
- `runtime.py`: hierarchy lifecycle/orchestration service used by `main.py`

## Runtime Modes
- `shadow`: compute hierarchy state, intents, and logs without modifying active signal timing
- `live`: execute bounded timing bias through the signal execution planner
