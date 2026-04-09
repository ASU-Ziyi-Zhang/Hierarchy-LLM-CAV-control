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
    write_tables,
)


def multi_penetration_compare_v2(
    input_dir: str,
    output_dir: str,
    threshold_ttc: float = 1.5,
    xlabels=None,
    xlims=None,
    drac_threshold: float = 2.0,
    do_drac_share: bool = True,
    pet_threshold: float = 1.0,
    headway_threshold: float = 0.8,
    average_seeds: bool = False,
    also_write_csv: bool = True,
):
    """
    Aggregate safety metrics from the current dashboard-export workbooks.

    Inputs:
      - *_datasets.xlsx produced by dashboard.py

    Outputs:
      - safety_comparison.xlsx
      - one CSV per sheet when also_write_csv=True
    """
    del xlabels, xlims, drac_threshold, do_drac_share  # kept for backward-compatible signature

    files = discover_dataset_files(input_dir, include_all_runs=average_seeds)
    inventory_rows = []
    ttc_frames = []
    pet_frames = []
    drac_frames = []
    headway_frames = []

    for path in files:
        meta = parse_run_identity(path)
        inventory_rows.append(meta)

        ttc = summarize_histogram(
            read_sheet(path, "safety_TTC_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"]),
            risk_threshold=threshold_ttc,
            risk_direction="below",
        ).rename(columns={"risk_share": f"risk_share_lt_{threshold_ttc:g}s"})
        ttc_frames.append(append_run_metadata(ttc, meta))

        pet = summarize_histogram(
            read_sheet(path, "safety_PET_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"]),
            risk_threshold=pet_threshold,
            risk_direction="below",
        ).rename(columns={"risk_share": f"risk_share_lt_{pet_threshold:g}s"})
        pet_frames.append(append_run_metadata(pet, meta))

        headway = summarize_histogram(
            read_sheet(path, "safety_Headway_hist", required=["bin_left", "bin_right", "bin_mid", "HDV", "CAV"]),
            risk_threshold=headway_threshold,
            risk_direction="below",
        ).rename(columns={"risk_share": f"risk_share_lt_{headway_threshold:g}s"})
        headway_frames.append(append_run_metadata(headway, meta))

        drac = read_sheet(
            path,
            "safety_DRAC_summary",
            required=["Type", "count", "mean", "std", "p50", "p90", "p95", "min", "max"],
        ).rename(columns={"Type": "vehicle_type"})
        drac["vehicle_type"] = drac["vehicle_type"].astype(str).str.upper()
        drac_frames.append(append_run_metadata(drac, meta))

    tables = {
        "inventory": pd.DataFrame(inventory_rows).sort_values("penetration_rate").reset_index(drop=True),
        "safety_TTC": concat_and_sort(ttc_frames),
        "safety_PET": concat_and_sort(pet_frames),
        "safety_DRAC": concat_and_sort(drac_frames),
        "safety_Headway": concat_and_sort(headway_frames),
    }

    if average_seeds:
        tables["inventory_runs"] = tables["inventory"].copy()
        pen_group = ["penetration_rate", "penetration_pct", "requested_penetration_rate", "rounded_penetration_pct", "penetration_source"]
        pen_vehicle_group = pen_group + ["vehicle_type"]
        tables["inventory"] = aggregate_mean_table(tables["inventory"], pen_group)
        tables["safety_TTC"] = aggregate_mean_table(tables["safety_TTC"], pen_vehicle_group)
        tables["safety_PET"] = aggregate_mean_table(tables["safety_PET"], pen_vehicle_group)
        tables["safety_DRAC"] = aggregate_mean_table(tables["safety_DRAC"], pen_vehicle_group)
        tables["safety_Headway"] = aggregate_mean_table(tables["safety_Headway"], pen_vehicle_group)

    out_path = Path(output_dir) / "safety_comparison.xlsx"
    write_tables(out_path, tables, also_write_csv=also_write_csv)

    plots_dir = Path(output_dir) / "plots"
    plot_penetration_trend(
        tables["safety_TTC"],
        value_col="mean",
        out_png=plots_dir / "safety_ttc_mean_trend.png",
        ylabel="Mean TTC (s)",
        title="Mean TTC vs Penetration",
    )
    risk_col = f"risk_share_lt_{threshold_ttc:g}s"
    plot_penetration_trend(
        tables["safety_TTC"],
        value_col=risk_col,
        out_png=plots_dir / "safety_ttc_risk_share_trend.png",
        ylabel=f"Share TTC < {threshold_ttc:g}s",
        title="TTC Risk Share vs Penetration",
    )
    plot_penetration_trend(
        tables["safety_PET"],
        value_col="mean",
        out_png=plots_dir / "safety_pet_mean_trend.png",
        ylabel="Mean PET (s)",
        title="Mean PET vs Penetration",
    )
    pet_risk_col = f"risk_share_lt_{pet_threshold:g}s"
    plot_penetration_trend(
        tables["safety_PET"],
        value_col=pet_risk_col,
        out_png=plots_dir / "safety_pet_risk_share_trend.png",
        ylabel=f"Share PET < {pet_threshold:g}s",
        title="PET Risk Share vs Penetration",
    )
    plot_penetration_trend(
        tables["safety_DRAC"],
        value_col="mean",
        out_png=plots_dir / "safety_drac_mean_trend.png",
        ylabel="Mean DRAC (m/s^2)",
        title="Mean DRAC vs Penetration",
    )
    plot_penetration_trend(
        tables["safety_DRAC"],
        value_col="p95",
        out_png=plots_dir / "safety_drac_p95_trend.png",
        ylabel="DRAC P95 (m/s^2)",
        title="DRAC P95 vs Penetration",
    )
    plot_penetration_trend(
        tables["safety_Headway"],
        value_col="mean",
        out_png=plots_dir / "safety_headway_mean_trend.png",
        ylabel="Mean Headway (s)",
        title="Mean Headway vs Penetration",
    )
    headway_risk_col = f"risk_share_lt_{headway_threshold:g}s"
    plot_penetration_trend(
        tables["safety_Headway"],
        value_col=headway_risk_col,
        out_png=plots_dir / "safety_headway_risk_share_trend.png",
        ylabel=f"Share Headway < {headway_threshold:g}s",
        title="Headway Risk Share vs Penetration",
    )

    return out_path
