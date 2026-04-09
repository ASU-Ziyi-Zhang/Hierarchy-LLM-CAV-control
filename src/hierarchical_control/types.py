from __future__ import annotations

from dataclasses import asdict, dataclass, field
from typing import Any


@dataclass
class LocalSignalState:
    intersection_id: str
    current_phase: int
    current_phase_group: str
    remaining_green: float
    next_phase: int
    queue_mainline: float
    queue_side_street: float
    avg_delay_seconds: float | None
    queue_pressure: float
    mainline_storage_ratio: float
    side_storage_ratio: float
    downstream_blocking_flag: bool
    cav_count_approach: int
    cav_platoon_eta: float | None
    delay_level: str
    saturation_level: str
    spillback_level: str
    platoon_status: str
    base_spat_plan: dict[str, Any]

    def as_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass
class CorridorSummary:
    average_delay_seconds: float | None
    high_saturation_count: int
    spillback_critical_count: int
    platoon_relevant_count: int
    dominant_congestion_region: str
    available_mode_candidates: list[str]

    def as_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass
class CoordinationIntent:
    intersection_id: str
    network_mode: str
    corridor_priority: str
    intersection_role: str
    adjustment_level: int
    rationale: list[str] = field(default_factory=list)

    def as_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass
class SignalAgentDecision:
    intersection_id: str
    role: str
    action: str
    adjustment_level: int
    bias_seconds: float
    target_phase: str
    constrained_by_base_plan: bool = True
    rationale: list[str] = field(default_factory=list)

    def as_dict(self) -> dict[str, Any]:
        return asdict(self)
