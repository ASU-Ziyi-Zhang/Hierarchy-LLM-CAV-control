from __future__ import annotations

import json
import re
from typing import Any

from .types import CoordinationIntent


ALLOWED_NETWORK_MODES = {
    "BALANCED",
    "MAINLINE_PRIORITY",
    "SPILLBACK_PROTECTION",
    "PLATOON_SUPPORT",
}
ALLOWED_CORRIDOR_PRIORITIES = {
    "NONE",
    "MAIN_CORRIDOR",
    "SUB_CORRIDOR_A",
    "SUB_CORRIDOR_B",
}
ALLOWED_INTERSECTION_ROLES = {
    "NEUTRAL",
    "FAVOR_MAINLINE",
    "SERVE_SIDE_STREET",
    "PROTECT_DOWNSTREAM",
    "PREPARE_PLATOON",
}


def extract_json_object(text: str) -> dict[str, Any]:
    match = re.search(r"```json\s*(\{.*?\})\s*```", text, flags=re.DOTALL)
    candidate = match.group(1) if match else text.strip()
    try:
        return json.loads(candidate)
    except json.JSONDecodeError:
        start = candidate.find("{")
        end = candidate.rfind("}")
        if start != -1 and end != -1 and end > start:
            return json.loads(candidate[start : end + 1])
        raise


def parse_coordination_intents(
    llm_data: dict[str, Any],
    intersection_ids: list[str],
) -> dict[str, CoordinationIntent]:
    network_mode = llm_data.get("network_mode", "BALANCED")
    corridor_priority = llm_data.get("corridor_priority", "NONE")
    if network_mode not in ALLOWED_NETWORK_MODES:
        raise ValueError(f"invalid network_mode: {network_mode}")
    if corridor_priority not in ALLOWED_CORRIDOR_PRIORITIES:
        raise ValueError(f"invalid corridor_priority: {corridor_priority}")

    intents_block = llm_data.get("intersection_intents", {})
    global_rationale = llm_data.get("global_rationale", [])
    if not isinstance(intents_block, dict):
        raise ValueError("intersection_intents must be an object")

    intents: dict[str, CoordinationIntent] = {}
    for intersection_id in intersection_ids:
        item = intents_block.get(intersection_id, {})
        role = item.get("intersection_role", "NEUTRAL")
        level = item.get("adjustment_level", 0)
        rationale = item.get("rationale", [])

        if role not in ALLOWED_INTERSECTION_ROLES:
            raise ValueError(f"invalid intersection_role for {intersection_id}: {role}")
        if not isinstance(level, int):
            raise ValueError(f"adjustment_level must be int for {intersection_id}")

        level = max(0, min(2, level))
        if not isinstance(rationale, list):
            rationale = []

        merged_rationale = [str(x) for x in global_rationale][:2] + [str(x) for x in rationale][:2]
        intents[intersection_id] = CoordinationIntent(
            intersection_id=intersection_id,
            network_mode=network_mode,
            corridor_priority=corridor_priority,
            intersection_role=role,
            adjustment_level=level,
            rationale=merged_rationale,
        )
    return intents
