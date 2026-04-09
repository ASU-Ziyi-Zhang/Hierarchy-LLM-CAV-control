from collections import defaultdict
from dataclasses import dataclass, field, replace
import os
from typing import Dict, List, Optional, Tuple
import xml.etree.ElementTree as ET


@dataclass
class ScenarioConfig:
    """
    All scenario-specific constraints and defaults for one SUMO scenario.

    Add one static entry to _REGISTRY for a new corridor. At runtime, those
    defaults are normalized against the scenario's current net/route files so
    stale lane or route names do not silently leak into behavior.
    """

    name: str
    is_traffic_light: bool = False
    is_merging: bool = False

    # Merge-area detection
    onramp_lanes: List[str] = field(default_factory=list)
    # Seed list of lane IDs that belong to the merge area.

    onramp_lane_keyword: Optional[str] = None
    # Optional fallback substring match for older scenarios that used a
    # consistent onramp naming convention.

    ending_lanes: List[str] = field(default_factory=list)
    # Lane IDs that terminate at the network boundary and require a merge.

    merging_lane: Optional[str] = None
    # Optional lane for which end-of-lane distance is tracked explicitly.

    # Simulation defaults
    default_time_to_teleport: float = -1.0
    # Seconds. -1 disables teleport. Traffic-light scenarios use 60 s so that
    # a stuck CAV is rescued within one green phase.

    speed_engine: float = 60.0
    # Physical engine speed cap [m/s].

    speed_limit_default: float = 30.0
    # Fallback road speed limit used when SUMO cannot return a lane value [m/s].

    default_route_id: str = "mainlane"
    # Default SUMO route ID used when a caller does not specify one explicitly.

    replay_route_map: Dict[str, str] = field(default_factory=dict)
    # Ordered substring->route mapping used for replay/ext vehicle injection.

    replay_default_route_id: Optional[str] = None
    # Fallback route for replay/ext vehicle injection. Defaults to default_route_id.

    # Signal timing overrides
    signal_timing_overrides: Dict[str, dict] = field(default_factory=dict)
    # Per-intersection signal timing data for traffic-light scenarios.

    # Debug
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


def _unique_preserve_order(values: List[str]) -> List[str]:
    seen = set()
    ordered = []
    for value in values:
        if value and value not in seen:
            seen.add(value)
            ordered.append(value)
    return ordered


def _load_lane_ids_and_connections(
    net_path: str,
) -> Tuple[set[str], Dict[str, List[str]], List[Tuple[str, int, str, int]]]:
    lane_ids: set[str] = set()
    edge_lanes: Dict[str, List[str]] = {}
    connections: List[Tuple[str, int, str, int]] = []

    if not os.path.isfile(net_path):
        return lane_ids, edge_lanes, connections

    root = ET.parse(net_path).getroot()

    for edge in root.iter("edge"):
        edge_id = edge.get("id", "")
        if not edge_id or edge_id.startswith(":"):
            continue
        lanes = []
        for lane in edge.iter("lane"):
            lane_id = lane.get("id")
            if not lane_id:
                continue
            lane_ids.add(lane_id)
            lanes.append(lane_id)
        edge_lanes[edge_id] = lanes

    for connection in root.iter("connection"):
        from_edge = connection.get("from", "")
        to_edge = connection.get("to", "")
        if (
            not from_edge
            or not to_edge
            or from_edge.startswith(":")
            or to_edge.startswith(":")
        ):
            continue
        from_lane = connection.get("fromLane")
        to_lane = connection.get("toLane")
        if from_lane is None or to_lane is None:
            continue
        connections.append((from_edge, int(from_lane), to_edge, int(to_lane)))

    return lane_ids, edge_lanes, connections


def _infer_merging_lanes_from_net(net_path: str) -> Tuple[List[str], List[str]]:
    lane_ids, edge_lanes, connections = _load_lane_ids_and_connections(net_path)
    if not lane_ids or not edge_lanes or not connections:
        return [], []

    incoming_by_dest: Dict[str, Dict[str, List[Tuple[int, int]]]] = defaultdict(
        lambda: defaultdict(list)
    )
    for from_edge, from_lane, to_edge, to_lane in connections:
        incoming_by_dest[to_edge][from_edge].append((from_lane, to_lane))

    onramp_lanes: List[str] = []
    ending_lanes: List[str] = []

    for to_edge, source_map in incoming_by_dest.items():
        if len(source_map) < 2:
            continue

        for from_edge, lane_pairs in source_map.items():
            source_lane_ids = edge_lanes.get(from_edge, [])
            if len(source_lane_ids) != 1:
                continue

            other_sources = [
                other_edge
                for other_edge in source_map.keys()
                if other_edge != from_edge
                and len(edge_lanes.get(other_edge, [])) > len(source_lane_ids)
            ]
            if not other_sources:
                continue

            onramp_lanes.extend(source_lane_ids)

            dest_lane_ids = edge_lanes.get(to_edge, [])
            for _, to_lane in lane_pairs:
                if 0 <= to_lane < len(dest_lane_ids):
                    ending_lanes.append(dest_lane_ids[to_lane])

    ending_lanes = _unique_preserve_order(ending_lanes)
    onramp_lanes = _unique_preserve_order(onramp_lanes + ending_lanes)
    return onramp_lanes, ending_lanes


def _load_route_ids(route_path: str) -> List[str]:
    if not os.path.isfile(route_path):
        return []

    root = ET.parse(route_path).getroot()
    route_ids = [route.get("id", "") for route in root.iter("route")]
    return [route_id for route_id in route_ids if route_id]


def _find_route_file(scenario_dir: str, scenario_name: str) -> Optional[str]:
    candidates = [
        os.path.join(scenario_dir, f"{scenario_name}.rou.xml"),
        os.path.join(scenario_dir, f"{scenario_name}_template.rou.xml"),
    ]
    for path in candidates:
        if os.path.isfile(path):
            return path
    return None


def _normalize_config_against_assets(
    cfg: ScenarioConfig, scenario_dir: str
) -> ScenarioConfig:
    normalized = replace(
        cfg,
        onramp_lanes=list(cfg.onramp_lanes),
        ending_lanes=list(cfg.ending_lanes),
        debug_vehicle_ids=list(cfg.debug_vehicle_ids),
        replay_route_map=dict(cfg.replay_route_map),
        signal_timing_overrides=dict(cfg.signal_timing_overrides),
    )

    net_path = os.path.join(scenario_dir, f"{cfg.name}.net.xml")
    lane_ids, _, _ = _load_lane_ids_and_connections(net_path)
    inferred_onramp_lanes: List[str] = []
    inferred_ending_lanes: List[str] = []
    if cfg.is_merging:
        inferred_onramp_lanes, inferred_ending_lanes = _infer_merging_lanes_from_net(
            net_path
        )

    if lane_ids:
        normalized.onramp_lanes = [
            lane for lane in normalized.onramp_lanes if lane in lane_ids
        ]
        normalized.ending_lanes = [
            lane for lane in normalized.ending_lanes if lane in lane_ids
        ]

        if inferred_onramp_lanes:
            normalized.onramp_lanes = inferred_onramp_lanes
            normalized.onramp_lane_keyword = None

        if inferred_ending_lanes:
            normalized.ending_lanes = inferred_ending_lanes

        if normalized.merging_lane not in lane_ids or not cfg.is_merging:
            normalized.merging_lane = None
        if (
            cfg.is_merging
            and not normalized.merging_lane
            and len(normalized.ending_lanes) == 1
        ):
            normalized.merging_lane = normalized.ending_lanes[0]

    route_path = _find_route_file(scenario_dir, cfg.name)
    route_ids = _load_route_ids(route_path) if route_path else []
    if route_ids:
        if normalized.default_route_id not in route_ids:
            normalized.default_route_id = route_ids[0]

        normalized.replay_route_map = {
            needle: route_id
            for needle, route_id in normalized.replay_route_map.items()
            if route_id in route_ids
        }

        if normalized.replay_default_route_id not in route_ids:
            normalized.replay_default_route_id = normalized.default_route_id

    return normalized


# Roosevelt signal timing data
_STANDARD_TL = {
    "veh_ext": [0, 0, 0, 0, 0, 0, 0, 0],
    "yellow": [3, 3, 3, 3, 3, 3, 3, 3],
    "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
}

_ROOSEVELT_SIGNAL_TIMING: Dict[str, dict] = {
    "Canal": _STANDARD_TL,
    "Clark": _STANDARD_TL,
    "Clinton": _STANDARD_TL,
    "Wabash": _STANDARD_TL,
    "J1": _STANDARD_TL,
    "Delano": {
        "veh_ext": [0, 0, 0, 0, 0, 5, 0, 0],
        "yellow": [0, 3, 0, 3, 0, 3, 3, 3],
        "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
    },
    "Michigan": {
        "veh_ext": [3, 0, 0, 0, 3, 0, 3, 0],
        "yellow": [3, 3, 3, 3, 3, 3, 3, 3],
        "red_clearance": [1, 2, 1, 2, 1, 2, 1, 2],
    },
    "State": {
        "veh_ext": [0, 0, 0, 0, 0, 0, 3, 0],
        "yellow": [3, 3, 3, 3, 3, 3, 3, 3],
        "red_clearance": [0, 2, 0, 2, 0, 2, 0, 2],
    },
}


_REGISTRY: Dict[str, ScenarioConfig] = {
    "onramp": ScenarioConfig(
        name="onramp",
        is_merging=True,
        onramp_lanes=["ramp_0", "E2_0"],
        ending_lanes=["E2_0"],
        merging_lane="E2_0",
        default_route_id="mainlane",
        replay_route_map={},
        replay_default_route_id="mainlane",
        debug_vehicle_ids=["mainlane_cav.8", "ramp_0_cav.2"],
    ),
    "i24": ScenarioConfig(
        name="i24",
        is_merging=True,
        onramp_lanes=["E2_0", "E6_0", "E1_0", "E7_0"],
        ending_lanes=["E1_0", "E7_0"],
        default_route_id="r_0",
        replay_route_map={},
        replay_default_route_id="r_0",
    ),
    "roosevelt": ScenarioConfig(
        name="roosevelt",
        is_traffic_light=True,
        default_time_to_teleport=60.0,
        default_route_id="r_east",
        replay_route_map={"east": "r_east", "west": "r_west"},
        replay_default_route_id="r_east",
        signal_timing_overrides=_ROOSEVELT_SIGNAL_TIMING,
    ),
}


def get_scenario_config(
    name: str, scenario_dir: Optional[str] = None
) -> ScenarioConfig:
    """Return the ScenarioConfig for name, or raise ValueError if unknown."""
    if name not in _REGISTRY:
        raise ValueError(
            f"Unknown scenario '{name}'. "
            f"Known scenarios: {list(_REGISTRY)}"
        )

    cfg = _REGISTRY[name]
    if scenario_dir:
        return _normalize_config_against_assets(cfg, scenario_dir)
    return cfg


def list_scenarios() -> List[str]:
    """Return all registered scenario names in stable order."""
    return list(_REGISTRY.keys())
