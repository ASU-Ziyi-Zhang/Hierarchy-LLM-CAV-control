from dataclasses import dataclass, field
from typing import Dict, List, Optional


@dataclass
class ScenarioConfig:
    """
    All scenario-specific constraints and defaults for one SUMO scenario.

    To add a new corridor, append one entry to _REGISTRY below — no changes
    to main.py are required.
    """
    name: str
    is_traffic_light: bool = False
    is_merging: bool = False

    # ── Onramp / merging lane detection ──────────────────────────────────────
    onramp_lanes: List[str] = field(default_factory=list)
    # Explicit set of lane IDs that belong to the onramp area (onramp scenario).

    onramp_lane_keyword: Optional[str] = None
    # If set, any lane whose ID *contains* this substring is treated as an
    # onramp lane (used by i24 which names its ramp lanes with 'onramp').

    ending_lanes: List[str] = field(default_factory=list)
    # Lane IDs that terminate at the network boundary (vehicle must merge off).

    merging_lane: Optional[str] = None
    # The single lane for which end-of-lane distance is tracked (onramp 'E2_0').

    # ── Simulation defaults ───────────────────────────────────────────────────
    default_time_to_teleport: float = -1.0
    # Seconds; -1 disables teleport.  Traffic-light scenarios use 60 s so that
    # a stuck CAV is rescued within one green phase.

    speed_engine: float = 60.0
    # Physical engine speed cap [m/s].

    speed_limit_default: float = 30.0
    # Fallback road speed limit used when SUMO cannot return a lane value [m/s].

    default_route_id: str = 'mainlane'
    # Default SUMO route ID used when a caller does not specify one explicitly.

    replay_route_map: Dict[str, str] = field(default_factory=dict)
    # Ordered substring->route mapping used for replay/ext vehicle injection.

    replay_default_route_id: Optional[str] = None
    # Fallback route for replay/ext vehicle injection. Defaults to default_route_id.

    # ── Signal timing overrides ─────────────────────────────────────────────
    signal_timing_overrides: Dict[str, dict] = field(default_factory=dict)
    # Per-intersection signal timing data for traffic-light scenarios.
    # Key = TL ID string, value = {"veh_ext": [8], "yellow": [8], "red_clearance": [8]}.

    # ── Debug ─────────────────────────────────────────────────────────────────
    debug_vehicle_ids: List[str] = field(default_factory=list)
    # Vehicle IDs to print controller state for when --debug is enabled.

    def resolve_route_id(self, route_id: Optional[str] = None) -> str:
        """Return an explicit route_id or the scenario default."""
        return route_id or self.default_route_id

    def resolve_replay_route_id(self, veh_id: str) -> str:
        """Resolve replay/ext route selection using configured substring rules."""
        veh_id_lower = veh_id.lower()
        for needle, route_id in self.replay_route_map.items():
            if needle.lower() in veh_id_lower:
                return route_id
        return self.replay_default_route_id or self.default_route_id


# ── Roosevelt signal timing data ──────────────────────────────────────────────
# Pre-computed per-intersection arrays (nPhase=8) for veh_ext, yellow,
# and red_clearance.  Shared by roosevelt and roosevelt_simple.

_STANDARD_TL = {  # Canal, Clark, Clinton, Wabash, J1 share the same pattern
    "veh_ext":       [0, 0, 0, 0, 0, 0, 0, 0],
    "yellow":        [3, 3, 3, 3, 3, 3, 3, 3],
    "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
}

_ROOSEVELT_SIGNAL_TIMING: Dict[str, dict] = {
    "Canal":    _STANDARD_TL,
    "Clark":    _STANDARD_TL,
    "Clinton":  _STANDARD_TL,
    "Wabash":   _STANDARD_TL,
    "J1":       _STANDARD_TL,
    "Delano": {
        "veh_ext":       [0, 0, 0, 0, 0, 5, 0, 0],
        "yellow":        [0, 3, 0, 3, 0, 3, 3, 3],
        "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
    },
    "Michigan": {
        "veh_ext":       [3, 0, 0, 0, 3, 0, 3, 0],
        "yellow":        [3, 3, 3, 3, 3, 3, 3, 3],
        "red_clearance": [1, 2, 1, 2, 1, 2, 1, 2],
    },
    "State": {
        "veh_ext":       [0, 0, 0, 0, 0, 0, 3, 0],
        "yellow":        [3, 3, 3, 3, 3, 3, 3, 3],
        "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
    },
}


# ── Scenario registry ─────────────────────────────────────────────────────────

_REGISTRY: dict = {
    'onramp': ScenarioConfig(
        name='onramp',
        is_merging=True,
        onramp_lanes=['ramp_0', 'E2_0', 'E1_0', 'E3_0', 'E4_0', 'E6_0', 'E7_0'],
        ending_lanes=['E2_0'],
        merging_lane='E2_0',
        default_route_id='mainlane',
        replay_route_map={'east': 'r_east', 'west': 'r_west'},
        replay_default_route_id='mainlane',
        debug_vehicle_ids=['east_cav.8', 'ramp_0_cav.2'],
    ),
    'i24': ScenarioConfig(
        name='i24',
        is_merging=True,
        onramp_lane_keyword='onramp',
        ending_lanes=['E1_0', 'E7_0'],
        default_route_id='mainlane',
        replay_route_map={'east': 'r_east', 'west': 'r_west'},
        replay_default_route_id='mainlane',
    ),
    'roosevelt': ScenarioConfig(
        name='roosevelt',
        is_traffic_light=True,
        default_time_to_teleport=60.0,
        default_route_id='mainlane',
        replay_route_map={'east': 'r_east', 'west': 'r_west'},
        replay_default_route_id='mainlane',
        signal_timing_overrides=_ROOSEVELT_SIGNAL_TIMING,
    ),
    'roosevelt_simple': ScenarioConfig(
        name='roosevelt_simple',
        is_traffic_light=True,
        default_time_to_teleport=60.0,
        default_route_id='mainlane',
        replay_route_map={'east': 'r_east', 'west': 'r_west'},
        replay_default_route_id='mainlane',
        signal_timing_overrides=_ROOSEVELT_SIGNAL_TIMING,
    ),
    'chi_clinton_canal': ScenarioConfig(
        name='chi_clinton_canal',
        is_traffic_light=True,
        default_time_to_teleport=60.0,
        default_route_id='mainlane',
        replay_route_map={'east': 'r_east', 'west': 'r_west'},
        replay_default_route_id='mainlane',
    ),
}


def get_scenario_config(name: str) -> ScenarioConfig:
    """Return the ScenarioConfig for *name*, or raise ValueError if unknown."""
    if name not in _REGISTRY:
        raise ValueError(
            f"Unknown scenario '{name}'. "
            f"Known scenarios: {list(_REGISTRY)}"
        )
    return _REGISTRY[name]


def list_scenarios() -> List[str]:
    """Return all registered scenario names in stable order."""
    return list(_REGISTRY.keys())
