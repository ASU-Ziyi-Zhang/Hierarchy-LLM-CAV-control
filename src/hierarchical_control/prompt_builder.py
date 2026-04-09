from __future__ import annotations

import json
from typing import Any

from .types import CorridorSummary


def build_compact_reports(reports: dict[str, dict[str, Any]]) -> dict[str, dict[str, Any]]:
    return {
        tl_id: {
            "current_phase_group": report.get("current_phase_group"),
            "delay_level": report.get("delay_level"),
            "saturation_level": report.get("saturation_level"),
            "spillback_level": report.get("spillback_level"),
            "platoon_status": report.get("platoon_status"),
            "queue_mainline": report.get("queue_mainline"),
            "queue_side_street": report.get("queue_side_street"),
            "downstream_blocking_flag": report.get("downstream_blocking_flag"),
        }
        for tl_id, report in reports.items()
    }


def build_output_schema() -> dict[str, Any]:
    return {
        "network_mode": "BALANCED | MAINLINE_PRIORITY | SPILLBACK_PROTECTION | PLATOON_SUPPORT",
        "corridor_priority": "NONE | MAIN_CORRIDOR | SUB_CORRIDOR_A | SUB_CORRIDOR_B",
        "intersection_intents": {
            "<intersection_id>": {
                "intersection_role": "NEUTRAL | FAVOR_MAINLINE | SERVE_SIDE_STREET | PROTECT_DOWNSTREAM | PREPARE_PLATOON",
                "adjustment_level": 0,
                "rationale": ["short explanation"],
            }
        },
        "global_rationale": ["short explanation"],
    }


def build_central_coordinator_prompt(
    reports: dict[str, dict[str, Any]],
    corridor_summary: CorridorSummary,
) -> str:
    compact_reports = build_compact_reports(reports)
    schema = build_output_schema()
    return f"""You are the central coordinator for a signalized urban corridor. Return only valid JSON with no markdown and no extra text. Use bounded supervisory coordination only. Do not invent new fields.

Allowed schema:
{json.dumps(schema, indent=2)}

Corridor summary:
{json.dumps(corridor_summary.as_dict(), indent=2)}

Intersection reports:
{json.dumps(compact_reports, indent=2)}
"""
