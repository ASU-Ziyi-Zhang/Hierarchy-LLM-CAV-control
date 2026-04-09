from __future__ import annotations

from pathlib import Path

import pandas as pd

from common import (
    aggregate_mean_table,
    discover_dataset_files,
    parse_run_identity,
    plot_penetration_trend,
    plot_penetration_trend_single,
    read_sheet,
    write_tables,
)


def multi_penetration_compare_fuel(
    input_dir: str,
    output_dir: str,
    average_seeds: bool = False,
    also_write_csv: bool = True,
):
    """
    Aggregate fuel metrics from the current dashboard-export workbooks.
    """
    files = discover_dataset_files(input_dir, include_all_runs=average_seeds)
    inventory_rows = []
    summary_rows = []
    savings_rows = []

    for path in files:
        meta = parse_run_identity(path)
        inventory_rows.append(meta)

        fuel = read_sheet(
            path,
            "energy_fuel_summary",
            required=["Vehicle Type", "Total Fuel (g)", "Avg Fuel per Vehicle (g)", "Fuel Efficiency (mile/gal)"],
        ).rename(columns={"Vehicle Type": "vehicle_type"})
        fuel["vehicle_type"] = fuel["vehicle_type"].astype(str).str.upper()

        for _, row in fuel.iterrows():
            summary_rows.append(
                {
                    **meta,
                    "vehicle_type": row["vehicle_type"],
                    "Total Fuel (g)": float(row["Total Fuel (g)"]),
                    "Avg Fuel per Vehicle (g)": float(row["Avg Fuel per Vehicle (g)"]),
                    "Fuel Efficiency (mile/gal)": float(row["Fuel Efficiency (mile/gal)"]),
                }
            )

        total_fuel = float(fuel["Total Fuel (g)"].sum())
        total_vehicles = 0.0
        total_miles = 0.0
        for _, row in fuel.iterrows():
            avg_per_vehicle = float(row["Avg Fuel per Vehicle (g)"])
            if avg_per_vehicle > 0:
                veh_count = float(row["Total Fuel (g)"]) / avg_per_vehicle
                total_vehicles += veh_count
                mpg = float(row["Fuel Efficiency (mile/gal)"])
                if mpg > 0:
                    gallons_per_vehicle = avg_per_vehicle / 2791.0
                    miles_per_vehicle = mpg * gallons_per_vehicle
                    total_miles += veh_count * miles_per_vehicle
        weighted_avg = float(total_fuel / total_vehicles) if total_vehicles > 0 else float("nan")
        mixed_mpg = float((total_miles * 2791.0) / total_fuel) if total_fuel > 0 and total_miles > 0 else float("nan")
        summary_rows.append(
            {
                **meta,
                "vehicle_type": "MIXED",
                "Total Fuel (g)": total_fuel,
                "Avg Fuel per Vehicle (g)": weighted_avg,
                "Fuel Efficiency (mile/gal)": mixed_mpg,
            }
        )

        try:
            fuel2 = read_sheet(path, "energy_fuel_summary2", required=["Metric", "Value"])
            for _, row in fuel2.iterrows():
                savings_rows.append(
                    {
                        **meta,
                        "metric": str(row["Metric"]),
                        "value": float(row["Value"]),
                    }
                )
        except Exception:
            continue

    tables = {
        "inventory": pd.DataFrame(inventory_rows).sort_values("penetration_rate").reset_index(drop=True),
        "fuel_summary": pd.DataFrame(summary_rows).sort_values(["penetration_rate", "vehicle_type"]).reset_index(drop=True),
        "fuel_secondary": pd.DataFrame(savings_rows).sort_values(["penetration_rate", "metric"]).reset_index(drop=True),
    }

    if average_seeds:
        tables["inventory_runs"] = tables["inventory"].copy()
        pen_group = ["penetration_rate", "penetration_pct", "requested_penetration_rate", "rounded_penetration_pct", "penetration_source"]
        pen_vehicle_group = pen_group + ["vehicle_type"]
        pen_metric_group = pen_group + ["metric"]
        tables["inventory"] = aggregate_mean_table(tables["inventory"], pen_group)
        tables["fuel_summary"] = aggregate_mean_table(tables["fuel_summary"], pen_vehicle_group)
        tables["fuel_secondary"] = aggregate_mean_table(tables["fuel_secondary"], pen_metric_group)

    out_path = Path(output_dir) / "fuel_comparison.xlsx"
    write_tables(out_path, tables, also_write_csv=also_write_csv)

    plots_dir = Path(output_dir) / "plots"
    fuel_by_type = tables["fuel_summary"][tables["fuel_summary"]["vehicle_type"].isin(["HDV", "CAV"])].copy()
    fuel_mixed = tables["fuel_summary"][tables["fuel_summary"]["vehicle_type"].isin(["MIXED"])].copy()
    fuel_eff_baseline = fuel_by_type[
        (fuel_by_type["penetration_pct"] == 0.0) & (fuel_by_type["vehicle_type"] == "HDV")
    ]["Fuel Efficiency (mile/gal)"]
    total_fuel_baseline = fuel_mixed[fuel_mixed["penetration_pct"] == 0.0]["Total Fuel (g)"]
    fuel_eff_baselines = []
    total_fuel_baselines = []
    if not fuel_eff_baseline.empty:
        fuel_eff_baselines.append(
            {
                "y": float(fuel_eff_baseline.iloc[0]),
                "label": "p=0 HDV baseline",
                "color": "#444444",
                "linestyle": "--",
                "linewidth": 1.6,
                "alpha": 0.9,
            }
        )
    if not total_fuel_baseline.empty:
        total_fuel_baselines.append(
            {
                "y": float(total_fuel_baseline.iloc[0]),
                "label": "p=0 total fuel baseline",
                "color": "#444444",
                "linestyle": "--",
                "linewidth": 1.6,
                "alpha": 0.9,
            }
        )

    plot_penetration_trend(
        fuel_by_type,
        value_col="Total Fuel (g)",
        out_png=plots_dir / "fuel_total_fuel_trend.png",
        ylabel="Total Fuel (g)",
        title="Total Fuel by Vehicle Type vs Penetration",
        vehicle_types=["HDV", "CAV"],
    )
    plot_penetration_trend_single(
        fuel_mixed,
        value_col="Total Fuel (g)",
        out_png=plots_dir / "fuel_total_fuel_all_trend.png",
        ylabel="Total Fuel (g)",
        title="Total Fuel (All Vehicles) vs Penetration",
        min_penetration_pct=10.0,
        baselines=total_fuel_baselines,
    )
    plot_penetration_trend(
        tables["fuel_summary"],
        value_col="Avg Fuel per Vehicle (g)",
        out_png=plots_dir / "fuel_avg_per_vehicle_trend.png",
        ylabel="Average Fuel per Vehicle (g)",
        title="Average Fuel per Vehicle vs Penetration",
    )
    plot_penetration_trend(
        tables["fuel_summary"],
        value_col="Fuel Efficiency (mile/gal)",
        out_png=plots_dir / "fuel_efficiency_trend.png",
        ylabel="Fuel Efficiency (mile/gal)",
        title="Fuel Efficiency vs Penetration",
        baselines=fuel_eff_baselines,
    )
    plot_penetration_trend_single(
        fuel_mixed,
        value_col="Fuel Efficiency (mile/gal)",
        out_png=plots_dir / "fuel_efficiency_all_trend.png",
        ylabel="Fuel Efficiency (mile/gal)",
        title="Fuel Efficiency (All Vehicles) vs Penetration",
        baselines=fuel_eff_baselines,
    )

    if not tables["fuel_secondary"].empty and "metric" in tables["fuel_secondary"].columns:
        for metric_name, sub in tables["fuel_secondary"].groupby("metric"):
            safe_name = (
                metric_name.lower()
                .replace("%", "pct")
                .replace("(", "")
                .replace(")", "")
                .replace("/", "_")
                .replace(" ", "_")
            )
            plot_penetration_trend_single(
                sub,
                value_col="value",
                out_png=plots_dir / f"fuel_{safe_name}_trend.png",
                ylabel=metric_name,
                title=f"{metric_name} vs Penetration",
            )

    return out_path
