from __future__ import annotations

from statistics import mean
from typing import Any

from .types import CorridorSummary, LocalSignalState


LOW_DELAY_THRESHOLD = 20.0
HIGH_DELAY_THRESHOLD = 55.0
LOW_SATURATION_THRESHOLD = 0.85
MEDIUM_SATURATION_THRESHOLD = 0.95
HIGH_SATURATION_THRESHOLD = 1.00
SPILLBACK_WARNING_THRESHOLD = 0.60
SPILLBACK_CRITICAL_THRESHOLD = 0.85
PLATOON_MIN_COUNT = 3
PLATOON_IMMEDIATE_ETA = 30.0
PLATOON_CANDIDATE_ETA = 60.0


def summarize_delay(waiting_times: list[float]) -> float | None:
    valid = [value for value in waiting_times if value is not None]
    return mean(valid) if valid else None


def classify_delay(delay_seconds: float | None) -> str:
    if delay_seconds is None:
        return "UNKNOWN_DELAY"
    if delay_seconds < LOW_DELAY_THRESHOLD:
        return "LOW_DELAY"
    if delay_seconds < HIGH_DELAY_THRESHOLD:
        return "MODERATE_DELAY"
    return "HIGH_DELAY"


def classify_saturation(vc_ratio: float | None, queue_pressure: float) -> str:
    if vc_ratio is None:
        if queue_pressure < 5:
            return "LOW_SATURATION"
        if queue_pressure < 10:
            return "MEDIUM_SATURATION"
        if queue_pressure < 20:
            return "HIGH_SATURATION"
        return "OVERSATURATED"
    if vc_ratio < LOW_SATURATION_THRESHOLD:
        return "LOW_SATURATION"
    if vc_ratio < MEDIUM_SATURATION_THRESHOLD:
        return "MEDIUM_SATURATION"
    if vc_ratio < HIGH_SATURATION_THRESHOLD:
        return "HIGH_SATURATION"
    return "OVERSATURATED"


def classify_spillback(storage_ratio: float) -> str:
    if storage_ratio < SPILLBACK_WARNING_THRESHOLD:
        return "NO_SPILLBACK"
    if storage_ratio < SPILLBACK_CRITICAL_THRESHOLD:
        return "SPILLBACK_WARNING"
    return "SPILLBACK_CRITICAL"


def classify_platoon(cav_count: int, cav_eta: float | None) -> str:
    if cav_count < PLATOON_MIN_COUNT or cav_eta is None or cav_eta > PLATOON_CANDIDATE_ETA:
        return "NO_PLATOON"
    if cav_eta <= PLATOON_IMMEDIATE_ETA:
        return "PLATOON_IMMEDIATE"
    return "PLATOON_CANDIDATE"


class SignalStateBuilder:
    """Build local intersection summaries and corridor-level aggregates."""

    def infer_phase_group(self, current_phase: int) -> str:
        if current_phase in (2, 6):
            return "THROUGH"
        if current_phase in (1, 3, 5, 7):
            return "TURN"
        return "OTHER"

    def build_local_state(
        self,
        *,
        intersection_id: str,
        current_phase: int,
        remaining_green: float,
        next_phase: int,
        queue_mainline: float,
        queue_side_street: float,
        avg_delay_seconds: float | None,
        mainline_storage_ratio: float,
        side_storage_ratio: float,
        downstream_blocking_flag: bool,
        cav_count_approach: int,
        cav_platoon_eta: float | None,
        base_spat_plan: dict[str, Any],
        vc_ratio_mainline: float | None = None,
        vc_ratio_side: float | None = None,
    ) -> LocalSignalState:
        queue_pressure = queue_mainline + queue_side_street
        delay_level = classify_delay(avg_delay_seconds)
        vc_proxy = vc_ratio_mainline if vc_ratio_mainline is not None else vc_ratio_side
        saturation_level = classify_saturation(vc_proxy, queue_pressure)
        spillback_level = classify_spillback(max(mainline_storage_ratio, side_storage_ratio))
        platoon_status = classify_platoon(cav_count_approach, cav_platoon_eta)
        return LocalSignalState(
            intersection_id=intersection_id,
            current_phase=current_phase,
            current_phase_group=self.infer_phase_group(current_phase),
            remaining_green=remaining_green,
            next_phase=next_phase,
            queue_mainline=queue_mainline,
            queue_side_street=queue_side_street,
            avg_delay_seconds=avg_delay_seconds,
            queue_pressure=queue_pressure,
            mainline_storage_ratio=mainline_storage_ratio,
            side_storage_ratio=side_storage_ratio,
            downstream_blocking_flag=downstream_blocking_flag,
            cav_count_approach=cav_count_approach,
            cav_platoon_eta=cav_platoon_eta,
            delay_level=delay_level,
            saturation_level=saturation_level,
            spillback_level=spillback_level,
            platoon_status=platoon_status,
            base_spat_plan=base_spat_plan,
        )

    def build_corridor_summary(self, states: dict[str, LocalSignalState]) -> CorridorSummary:
        delays = [state.avg_delay_seconds for state in states.values() if state.avg_delay_seconds is not None]
        high_saturation_count = sum(
            state.saturation_level in {"HIGH_SATURATION", "OVERSATURATED"} for state in states.values()
        )
        spillback_critical_count = sum(state.spillback_level == "SPILLBACK_CRITICAL" for state in states.values())
        platoon_relevant_count = sum(
            state.platoon_status in {"PLATOON_CANDIDATE", "PLATOON_IMMEDIATE"} for state in states.values()
        )
        dominant_congestion_region = max(
            states.items(),
            key=lambda item: item[1].queue_pressure,
            default=("NONE", None),
        )[0]
        return CorridorSummary(
            average_delay_seconds=summarize_delay(delays),
            high_saturation_count=high_saturation_count,
            spillback_critical_count=spillback_critical_count,
            platoon_relevant_count=platoon_relevant_count,
            dominant_congestion_region=dominant_congestion_region,
            available_mode_candidates=[
                "BALANCED",
                "MAINLINE_PRIORITY",
                "SPILLBACK_PROTECTION",
                "PLATOON_SUPPORT",
            ],
        )
