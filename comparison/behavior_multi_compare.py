from __future__ import annotations

from pathlib import Path

import pandas as pd

from common import (
    aggregate_mean_table,
    append_run_metadata,
    concat_and_sort,
    discover_dataset_files,
    parse_run_identity,
    plot_penetration_trend,
    read_sheet,
    summarize_discrete_counts,
    summarize_histogram,
    write_tables,
)


def multi_penetration_compare_behavior(
    input_dir: str,
    output_dir: str,
    xlims=None,
    average_seeds: bool = False,
    also_write_csv: bool = True,
    lc_threshold: int = 3,
):
    """
    Aggregate driving-behavior metrics from the current dashboard-export workbooks.
    """
    del xlims  # backward-compatible signature

    files = discover_dataset_files(input_dir, include_all_runs=average_seeds)
    inventory_rows = []
    lc_frames = []
    gap_frames = []
    space_gap_frames = []

    for path in files:
        meta = parse_run_identity(path)
        inventory_rows.append(meta)

        lc = summarize_discrete_counts(
            read_sheet(path, "behav_LC_hist", required=["Lane Changes", "HDV", "CAV"]),
            value_col="Lane Changes",
            risk_threshold=lc_threshold,
            risk_direction="above",
        ).rename(columns={"risk_share": f"share_gt_{lc_threshold:d}_lane_changes"})
        lc_frames.append(append_run_metadata(lc, meta))

        gap = summarize_histogram(
            read_sheet(path, "behav_Gap_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"])
        )
        gap_frames.append(append_run_metadata(gap, meta))

        space_gap = summarize_histogram(
            read_sheet(path, "behav_SpaceGap_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"])
        )
        space_gap_frames.append(append_run_metadata(space_gap, meta))

    tables = {
        "inventory": pd.DataFrame(inventory_rows).sort_values("penetration_rate").reset_index(drop=True),
        "behavior_LaneChange": concat_and_sort(lc_frames),
        "behavior_GapAcceptance": concat_and_sort(gap_frames),
        "behavior_SpaceGap": concat_and_sort(space_gap_frames),
    }

    if average_seeds:
        tables["inventory_runs"] = tables["inventory"].copy()
        pen_group = ["penetration_rate", "penetration_pct", "requested_penetration_rate", "rounded_penetration_pct", "penetration_source"]
        pen_vehicle_group = pen_group + ["vehicle_type"]
        tables["inventory"] = aggregate_mean_table(tables["inventory"], pen_group)
        tables["behavior_LaneChange"] = aggregate_mean_table(tables["behavior_LaneChange"], pen_vehicle_group)
        tables["behavior_GapAcceptance"] = aggregate_mean_table(tables["behavior_GapAcceptance"], pen_vehicle_group)
        tables["behavior_SpaceGap"] = aggregate_mean_table(tables["behavior_SpaceGap"], pen_vehicle_group)

    out_path = Path(output_dir) / "behavior_comparison.xlsx"
    write_tables(out_path, tables, also_write_csv=also_write_csv)

    plots_dir = Path(output_dir) / "plots"
    plot_penetration_trend(
        tables["behavior_LaneChange"],
        value_col="mean",
        out_png=plots_dir / "behavior_lane_change_mean_trend.png",
        ylabel="Mean Lane Changes",
        title="Mean Lane Changes vs Penetration",
    )
    lc_risk_col = f"share_gt_{lc_threshold:d}_lane_changes"
    plot_penetration_trend(
        tables["behavior_LaneChange"],
        value_col=lc_risk_col,
        out_png=plots_dir / "behavior_lane_change_high_share_trend.png",
        ylabel=f"Share > {lc_threshold:d} Lane Changes",
        title="High Lane-Change Share vs Penetration",
    )
    plot_penetration_trend(
        tables["behavior_GapAcceptance"],
        value_col="mean",
        out_png=plots_dir / "behavior_gap_mean_trend.png",
        ylabel="Mean Accepted Gap (s)",
        title="Mean Accepted Gap vs Penetration",
    )
    plot_penetration_trend(
        tables["behavior_SpaceGap"],
        value_col="mean",
        out_png=plots_dir / "behavior_space_gap_mean_trend.png",
        ylabel="Mean Space Gap (m)",
        title="Mean Space Gap vs Penetration",
    )

    return out_path
