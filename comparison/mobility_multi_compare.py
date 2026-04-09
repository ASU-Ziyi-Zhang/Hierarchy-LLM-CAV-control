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
    summarize_histogram,
    summarize_vehicle_count_ts,
    write_tables,
)


def multi_penetration_compare_mobility(
    input_dir: str,
    output_dir: str,
    xlims=None,
    average_seeds: bool = False,
    also_write_csv: bool = True,
):
    """
    Aggregate mobility metrics from the current dashboard-export workbooks.
    """
    del xlims  # backward-compatible signature

    files = discover_dataset_files(input_dir, include_all_runs=average_seeds)
    inventory_rows = []
    speed_frames = []
    accel_frames = []
    tt_frames = []
    veh_count_frames = []
    delay_frames = []

    for path in files:
        meta = parse_run_identity(path)
        inventory_rows.append(meta)

        speed = summarize_histogram(
            read_sheet(path, "mobility_Speed_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"])
        )
        speed_frames.append(append_run_metadata(speed, meta))

        accel = summarize_histogram(
            read_sheet(path, "mobility_Accel_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"])
        )
        accel_frames.append(append_run_metadata(accel, meta))

        tt = summarize_histogram(
            read_sheet(path, "mobility_TT_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"])
        )
        tt_frames.append(append_run_metadata(tt, meta))

        veh_count = summarize_vehicle_count_ts(
            read_sheet(path, "mobility_VehCount_ts", required=["Time(s)", "HDV", "CAV"])
        )
        veh_count_frames.append(append_run_metadata(veh_count, meta))

        delay = read_sheet(
            path,
            "mobility_Delay_compare",
            required=["Vehicle Type", "Delay per Mile (s/mile)", "Total Delay (s)", "Miles Traveled"],
        ).rename(columns={"Vehicle Type": "vehicle_type"})
        delay["vehicle_type"] = delay["vehicle_type"].astype(str).str.upper()

        total_delay = float(delay["Total Delay (s)"].sum())
        total_miles = float(delay["Miles Traveled"].sum())
        mixed = pd.DataFrame(
            [
                {
                    "vehicle_type": "MIXED",
                    "Delay per Mile (s/mile)": total_delay / total_miles if total_miles > 0 else float("nan"),
                    "Total Delay (s)": total_delay,
                    "Miles Traveled": total_miles,
                }
            ]
        )
        delay_frames.append(append_run_metadata(pd.concat([delay, mixed], ignore_index=True), meta))

    tables = {
        "inventory": pd.DataFrame(inventory_rows).sort_values("penetration_rate").reset_index(drop=True),
        "mobility_Speed": concat_and_sort(speed_frames),
        "mobility_Accel": concat_and_sort(accel_frames),
        "mobility_TT": concat_and_sort(tt_frames),
        "mobility_VehCount": concat_and_sort(veh_count_frames),
        "mobility_Delay": concat_and_sort(delay_frames),
    }

    if average_seeds:
        tables["inventory_runs"] = tables["inventory"].copy()
        pen_group = ["penetration_rate", "penetration_pct", "requested_penetration_rate", "rounded_penetration_pct", "penetration_source"]
        pen_vehicle_group = pen_group + ["vehicle_type"]
        tables["inventory"] = aggregate_mean_table(tables["inventory"], pen_group)
        tables["mobility_Speed"] = aggregate_mean_table(tables["mobility_Speed"], pen_vehicle_group)
        tables["mobility_Accel"] = aggregate_mean_table(tables["mobility_Accel"], pen_vehicle_group)
        tables["mobility_TT"] = aggregate_mean_table(tables["mobility_TT"], pen_vehicle_group)
        tables["mobility_VehCount"] = aggregate_mean_table(tables["mobility_VehCount"], pen_vehicle_group)
        tables["mobility_Delay"] = aggregate_mean_table(tables["mobility_Delay"], pen_vehicle_group)

    out_path = Path(output_dir) / "mobility_comparison.xlsx"
    write_tables(out_path, tables, also_write_csv=also_write_csv)

    plots_dir = Path(output_dir) / "plots"
    plot_penetration_trend(
        tables["mobility_Speed"],
        value_col="mean",
        out_png=plots_dir / "mobility_speed_mean_trend.png",
        ylabel="Mean Speed (m/s)",
        title="Mean Speed vs Penetration",
    )
    plot_penetration_trend(
        tables["mobility_Accel"],
        value_col="std",
        out_png=plots_dir / "mobility_accel_std_trend.png",
        ylabel="Acceleration Std (m/s^2)",
        title="Acceleration Variability vs Penetration",
    )
    plot_penetration_trend(
        tables["mobility_TT"],
        value_col="mean",
        out_png=plots_dir / "mobility_tt_mean_trend.png",
        ylabel="Mean Travel Time (s)",
        title="Mean Travel Time vs Penetration",
    )
    plot_penetration_trend(
        tables["mobility_Delay"],
        value_col="Delay per Mile (s/mile)",
        out_png=plots_dir / "mobility_delay_per_mile_trend.png",
        ylabel="Delay per Mile (s/mile)",
        title="Delay per Mile vs Penetration",
    )
    plot_penetration_trend(
        tables["mobility_VehCount"],
        value_col="avg_count",
        out_png=plots_dir / "mobility_avg_vehicle_count_trend.png",
        ylabel="Average Vehicle Count",
        title="Average In-Network Vehicle Count vs Penetration",
    )

    return out_path
