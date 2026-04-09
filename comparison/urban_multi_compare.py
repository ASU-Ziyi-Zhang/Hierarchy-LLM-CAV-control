from __future__ import annotations

from pathlib import Path

import matplotlib.pyplot as plt
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


def _try_read_sheet(path: Path, sheet_name: str, required=None) -> pd.DataFrame | None:
    try:
        return read_sheet(path, sheet_name, required=required)
    except Exception:
        return None


def _append_rows(dest: list[dict], df: pd.DataFrame | None, meta: dict) -> None:
    if df is None or df.empty:
        return
    work = df.copy()
    for row in work.to_dict(orient="records"):
        dest.append({**meta, **row})


def _metric_value(metric_map: dict[str, float], *labels: str, default: float = 0.0) -> float:
    for label in labels:
        if label in metric_map:
            return metric_map[label]
    return default


def _safe_required_sheet(path: Path, sheet_name: str, required_cols: list[str]) -> pd.DataFrame | None:
    df = _try_read_sheet(path, sheet_name)
    if df is None or df.empty:
        return None
    if any(col not in df.columns for col in required_cols):
        return None
    return df


def _normalize_queue_ts_df(df: pd.DataFrame | None) -> pd.DataFrame | None:
    if df is None or df.empty:
        return None
    work = df.copy()
    rename_map = {}
    if "window_start" not in work.columns and "cycle_start" in work.columns:
        rename_map["cycle_start"] = "window_start"
    if "window_end" not in work.columns and "cycle_end" in work.columns:
        rename_map["cycle_end"] = "window_end"
    if rename_map:
        work = work.rename(columns=rename_map)
    return work


def _penetration_intersection_group_cols(work: pd.DataFrame, *, include_approach: bool = False) -> list[str]:
    cols = [
        col for col in [
            "penetration_rate",
            "penetration_pct",
            "requested_penetration_rate",
            "rounded_penetration_pct",
            "penetration_source",
            "intersection_id",
        ]
        if col in work.columns
    ]
    if include_approach and "approach_direction" in work.columns:
        cols.append("approach_direction")
    return cols


def _summarize_avg_delay_intersections(df: pd.DataFrame) -> pd.DataFrame:
    if df is None or df.empty or "intersection_id" not in df.columns or "avg_delay_all" not in df.columns:
        return pd.DataFrame()

    work = df.copy()
    work = work[work["intersection_id"].notna()].copy()
    work = work[work["intersection_id"].astype(str) != "unknown"].copy()
    if work.empty:
        return pd.DataFrame()

    group_cols = _penetration_intersection_group_cols(work)
    if not group_cols:
        return pd.DataFrame()

    agg_spec = {"avg_delay_all": ("avg_delay_all", "mean")}
    if "avg_stopped_delay_all" in work.columns:
        agg_spec["avg_stopped_delay_all"] = ("avg_stopped_delay_all", "mean")
    if "n_all" in work.columns:
        agg_spec["n_all"] = ("n_all", "sum")

    summary = work.groupby(group_cols, dropna=False).agg(**agg_spec).reset_index()
    return summary.sort_values(["penetration_rate", "intersection_id"]).reset_index(drop=True)


def _summarize_vc_intersections(df: pd.DataFrame) -> pd.DataFrame:
    if df is None or df.empty or "intersection_id" not in df.columns:
        return pd.DataFrame()
    if not {"vc_ratio_avg", "vc_ratio_max"}.issubset(df.columns):
        return pd.DataFrame()

    work = df.copy()
    work = work[work["intersection_id"].notna()].copy()
    work = work[work["intersection_id"].astype(str) != "unknown"].copy()
    if work.empty:
        return pd.DataFrame()

    group_cols = _penetration_intersection_group_cols(work)
    if not group_cols:
        return pd.DataFrame()

    agg_spec = {
        "vc_ratio_avg": ("vc_ratio_avg", "mean"),
        "vc_ratio_max": ("vc_ratio_max", "max"),
    }
    if "volume_vph" in work.columns:
        agg_spec["volume_vph"] = ("volume_vph", "mean")
    if "capacity_vph" in work.columns:
        agg_spec["capacity_vph"] = ("capacity_vph", "mean")

    summary = work.groupby(group_cols, dropna=False).agg(**agg_spec).reset_index()
    return summary.sort_values(["penetration_rate", "intersection_id"]).reset_index(drop=True)


def _summarize_queue_intersections(df: pd.DataFrame) -> pd.DataFrame:
    if df is None or df.empty or "intersection_id" not in df.columns:
        return pd.DataFrame()

    work = df.copy()
    if "avg_queued_vehicles" in work.columns and "max_queued_vehicles" in work.columns:
        pass
    elif "Average Queue" in work.columns and "Max Queue" in work.columns:
        work = work.rename(columns={
            "Average Queue": "avg_queued_vehicles",
            "Max Queue": "max_queued_vehicles",
        })
    else:
        return pd.DataFrame()

    work = work[work["intersection_id"].notna()].copy()
    work = work[work["intersection_id"].astype(str) != "unknown"].copy()
    if work.empty:
        return pd.DataFrame()

    group_cols = _penetration_intersection_group_cols(work, include_approach=True)
    if not group_cols:
        return pd.DataFrame()

    summary = (
        work.groupby(group_cols, dropna=False)
        .agg(
            avg_queued_vehicles=("avg_queued_vehicles", "mean"),
            max_queued_vehicles=("max_queued_vehicles", "max"),
            peak_avg_queued_vehicles=("avg_queued_vehicles", "max"),
        )
        .reset_index()
    )
    return summary.sort_values(["penetration_rate", "intersection_id"]).reset_index(drop=True)


def _plot_penetration_intersection_heatmap(
    df: pd.DataFrame,
    *,
    value_col: str,
    out_png: str | Path,
    title: str,
    colorbar_label: str,
):
    if df is None or df.empty:
        return None
    needed = {"penetration_pct", "intersection_id", value_col}
    if not needed.issubset(df.columns):
        return None

    keep_cols = ["penetration_pct", "intersection_id", value_col]
    if "approach_direction" in df.columns:
        keep_cols.append("approach_direction")
    work = df[keep_cols].dropna(subset=["penetration_pct", "intersection_id", value_col]).copy()
    work = work[work["intersection_id"].astype(str) != "unknown"]
    if work.empty:
        return None

    has_approach = "approach_direction" in work.columns
    if has_approach:
        work["row_label"] = work["intersection_id"].astype(str) + " | " + work["approach_direction"].astype(str)
    else:
        work["row_label"] = work["intersection_id"].astype(str)

    pivot = work.pivot_table(
        index="row_label",
        columns="penetration_pct",
        values=value_col,
        aggfunc="mean",
    )
    if pivot.empty:
        return None

    pivot = pivot.sort_index()
    pivot = pivot.reindex(sorted(pivot.columns.astype(float)), axis=1)

    fig, ax = plt.subplots(figsize=(8.2, max(3.8, 0.7 * len(pivot.index))))
    im = ax.imshow(pivot.to_numpy(dtype=float), aspect="auto", cmap="YlOrRd")

    ax.set_title(title)
    ax.set_xlabel("Penetration (%)")
    ax.set_ylabel("Intersection | Approach" if has_approach else "Intersection")
    ax.set_xticks(range(len(pivot.columns)))
    ax.set_xticklabels([f"{float(c):g}" for c in pivot.columns], rotation=45, ha="right")
    ax.set_yticks(range(len(pivot.index)))
    ax.set_yticklabels([str(i) for i in pivot.index])

    cbar = fig.colorbar(im, ax=ax)
    cbar.set_label(colorbar_label)

    out_png = Path(out_png)
    out_png.parent.mkdir(parents=True, exist_ok=True)
    fig.tight_layout()
    fig.savefig(out_png, dpi=180)
    plt.close(fig)
    return out_png


def _baseline_from_table(
    df: pd.DataFrame,
    value_col: str,
    *,
    vehicle_col: str | None = None,
    vehicle_value: str | None = None,
) -> list[dict]:
    if df is None or df.empty or value_col not in df.columns or "penetration_pct" not in df.columns:
        return []

    work = df[df["penetration_pct"].astype(float) == 0.0].copy()
    if vehicle_col is not None and vehicle_value is not None and vehicle_col in work.columns:
        work = work[work[vehicle_col].astype(str) == str(vehicle_value)]
    if work.empty:
        return []

    return [{
        "y": float(work[value_col].iloc[0]),
        "label": "p=0 baseline",
        "color": "#444444",
        "linestyle": "--",
    }]


def _spillback_index(output_dir: str | Path, *, include_all_runs: bool = False) -> dict[tuple[float, int | None] | float, list[Path] | Path]:
    out_dir = Path(output_dir)
    if not out_dir.exists():
        return {}

    index: dict[tuple[float, int | None] | float, list[Path] | Path] = {}
    for path in sorted(out_dir.glob("*spillback_events.csv")):
        try:
            meta = parse_run_identity(path)
        except Exception:
            continue
        if include_all_runs:
            key = (float(meta["penetration_rate"]), meta.get("seed"))
            index.setdefault(key, []).append(path)
        else:
            index[float(meta["penetration_rate"])] = path
    return index


def _sorted_df(rows, by):
    df = pd.DataFrame(rows)
    if df.empty:
        return df
    return df.sort_values(by).reset_index(drop=True)


def _penetration_tag(rate: float) -> str:
    return f"p{rate:g}"


def _load_metrics_object(scenario_output_dir: str | Path, penetration_rate: float):
    metrics_path = Path(scenario_output_dir) / f"metrics_{_penetration_tag(penetration_rate)}.pkl"
    if not metrics_path.exists():
        return None
    try:
        import dill
        with open(metrics_path, "rb") as f:
            return dill.load(f)
    except Exception:
        return None


def _rebuild_approach_delay_from_metrics(
    scenario_output_dir: str | Path,
    penetration_rate: float,
    free_flow_speed_hdv: float = 13.0,
    free_flow_speed_cav: float = 15.0,
) -> dict[str, float | int] | None:
    metrics = _load_metrics_object(scenario_output_dir, penetration_rate)
    if metrics is None:
        return None

    approach_lanes = set()
    detector_mapping = getattr(metrics, "detector_mapping", None)
    if isinstance(detector_mapping, dict) and detector_mapping:
        for mp in detector_mapping.values():
            lane_id = mp.get("sumo_lane") or mp.get("lane_id")
            if lane_id:
                approach_lanes.add(lane_id)
    elif hasattr(metrics, "det2lane") and isinstance(metrics.det2lane, dict):
        approach_lanes.update(v for v in metrics.det2lane.values() if v)
    else:
        for d in getattr(metrics, "detector_data", []):
            lane_id = metrics._resolve_lane_key(d)
            if lane_id:
                approach_lanes.add(lane_id)

    timesteps = getattr(metrics, "timesteps", None)
    if not approach_lanes or not timesteps:
        return None

    traversals = {"hdv": {}, "cav": {}}
    for t in timesteps:
        lane_dict = getattr(metrics, "timestep_lane_positions", {}).get(t, {})
        for lane_id in approach_lanes:
            vehs = lane_dict.get(lane_id)
            if vehs is None:
                vehs = metrics._lane_vehicle_map_at_time(t, lane_id, allow_edge_fallback=True)
            if not vehs:
                continue
            for veh_id, pos in vehs.items():
                v_type = getattr(metrics, "vehicle_info", {}).get(veh_id, {}).get("type")
                if v_type not in ("hdv", "cav"):
                    continue
                key = (lane_id, veh_id)
                rec = traversals[v_type].get(key)
                if rec is None:
                    traversals[v_type][key] = {"t0": float(t), "p0": float(pos), "t1": float(t), "p1": float(pos)}
                else:
                    rec["t1"] = float(t)
                    rec["p1"] = float(pos)

    min_distance_m = 10.0
    delays_by_type = {"hdv": [], "cav": []}
    for v_type in ["hdv", "cav"]:
        v_ff = free_flow_speed_hdv if v_type == "hdv" else free_flow_speed_cav
        for rec in traversals[v_type].values():
            travel_time = max(0.0, rec["t1"] - rec["t0"])
            dist = max(0.0, rec["p1"] - rec["p0"])
            if dist < min_distance_m or travel_time <= 0.0:
                continue
            ff_time = dist / max(v_ff, 0.1)
            delays_by_type[v_type].append(max(0.0, travel_time - ff_time))

    all_delays = delays_by_type["hdv"] + delays_by_type["cav"]
    return {
        "hdv_mean": float(sum(delays_by_type["hdv"]) / len(delays_by_type["hdv"])) if delays_by_type["hdv"] else 0.0,
        "cav_mean": float(sum(delays_by_type["cav"]) / len(delays_by_type["cav"])) if delays_by_type["cav"] else 0.0,
        "all_mean": float(sum(all_delays) / len(all_delays)) if all_delays else 0.0,
        "hdv_count": int(len(delays_by_type["hdv"])),
        "cav_count": int(len(delays_by_type["cav"])),
        "all_count": int(len(all_delays)),
    }


def _approximate_approach_delay_all(approach_df: pd.DataFrame, meta: dict) -> dict[str, float | int] | None:
    if approach_df is None or approach_df.empty:
        return None

    work = approach_df.copy()
    work["vehicle_type"] = work["vehicle_type"].astype(str).str.upper()
    hdv = work.loc[work["vehicle_type"] == "HDV", "Approach Delay (s)"]
    cav = work.loc[work["vehicle_type"] == "CAV", "Approach Delay (s)"]
    if hdv.empty and cav.empty:
        return None

    hdv_mean = float(hdv.iloc[0]) if not hdv.empty else float("nan")
    cav_mean = float(cav.iloc[0]) if not cav.empty else float("nan")

    cav_share = meta.get("requested_penetration_rate")
    if cav_share is None:
        cav_share = meta.get("penetration_rate", 0.0)
    cav_share = min(max(float(cav_share), 0.0), 1.0)
    hdv_share = 1.0 - cav_share

    if not pd.notna(hdv_mean):
        all_mean = cav_mean
    elif not pd.notna(cav_mean):
        all_mean = hdv_mean
    else:
        all_mean = hdv_share * hdv_mean + cav_share * cav_mean

    return {
        "all_mean": float(all_mean),
        "hdv_mean": float(hdv_mean) if pd.notna(hdv_mean) else float("nan"),
        "cav_mean": float(cav_mean) if pd.notna(cav_mean) else float("nan"),
        "hdv_count": 0,
        "cav_count": 0,
        "all_count": 0,
        "aggregation_method": "fleet_penetration_weighted_approximation",
    }


def multi_penetration_compare_urban(
    input_dir: str,
    output_dir: str,
    scenario_output_dir: str | None = None,
    average_seeds: bool = False,
    also_write_csv: bool = True,
):
    """
    Aggregate urban-signal metrics from dashboard-export workbooks and spillback CSVs.

    Optional sheets/files:
      - urban_Throughput
      - urban_AvgDelay
      - urban_ApproachDelay
      - urban_QueueLength
      - urban_VC_Ratio
      - *spillback_events.csv in the scenario output directory
    """
    files = discover_dataset_files(input_dir, include_all_runs=average_seeds)
    inventory_rows = []
    throughput_rows = []
    throughput_int_rows = []
    throughput_ts_rows = []
    avg_delay_rows = []
    avg_delay_ts_rows = []
    approach_rows = []
    approach_all_rows = []
    approach_ts_rows = []
    queue_rows = []
    queue_ts_rows = []
    vc_rows = []
    vc_ts_rows = []
    spillback_rows = []

    spillback_map = _spillback_index(scenario_output_dir, include_all_runs=average_seeds) if scenario_output_dir else {}

    for path in files:
        meta = parse_run_identity(path)
        inventory_rows.append(meta)

        # Throughput
        tp = _try_read_sheet(path, "urban_Throughput", required=["Metric", "Value"])
        if tp is not None and not tp.empty:
            tp_dict = dict(zip(tp["Metric"].astype(str), tp["Value"].astype(float)))
            throughput_rows.append({
                **meta,
                "total_vehicles": tp_dict.get("Total Vehicles", 0),
                "vehicles_per_hour": tp_dict.get("Vehicles/hr", 0),
                "cav_vehicles": tp_dict.get("CAV Vehicles", 0),
                "hdv_vehicles": tp_dict.get("HDV Vehicles", 0),
                "cav_vehicles_per_hour": tp_dict.get("CAV Vehicles/hr", 0),
                "hdv_vehicles_per_hour": tp_dict.get("HDV Vehicles/hr", 0),
            })
        _append_rows(
            throughput_ts_rows,
            _safe_required_sheet(path, "urban_Throughput_ts", ["intersection_id", "window_start", "window_end"]),
            meta,
        )
        _append_rows(
            throughput_int_rows,
            _safe_required_sheet(path, "urban_Throughput_int", ["intersection_id"]),
            meta,
        )

        # Average Delay
        ad = _try_read_sheet(path, "urban_AvgDelay", required=["Vehicle Type", "Avg Delay (s)"])
        if ad is not None and not ad.empty:
            ad = ad.rename(columns={"Vehicle Type": "vehicle_type"})
            ad["vehicle_type"] = ad["vehicle_type"].astype(str).str.upper()
            for _, row in ad.iterrows():
                avg_delay_rows.append({
                    **meta,
                    "vehicle_type": row["vehicle_type"],
                    "Avg Delay (s)": float(row["Avg Delay (s)"]),
                    "Avg Stopped Delay (s)": float(row.get("Avg Stopped Delay (s)", 0)),
                })
        _append_rows(
            avg_delay_ts_rows,
            _safe_required_sheet(path, "urban_AvgDelay_ts", ["intersection_id", "window_start", "window_end"]),
            meta,
        )

        # Approach Delay
        approach = _try_read_sheet(path, "urban_ApproachDelay", required=["Vehicle Type", "Approach Delay (s)"])
        if approach is not None and not approach.empty:
            approach = approach.rename(columns={"Vehicle Type": "vehicle_type"})
            approach["vehicle_type"] = approach["vehicle_type"].astype(str).str.upper()
            for _, row in approach.iterrows():
                approach_rows.append({
                    **meta,
                    "vehicle_type": row["vehicle_type"],
                    "Approach Delay (s)": float(row["Approach Delay (s)"]),
                })
        approach_all = None
        if scenario_output_dir:
            approach_all = _rebuild_approach_delay_from_metrics(scenario_output_dir, float(meta["penetration_rate"]))
        if approach_all is None:
            approach_all = _approximate_approach_delay_all(approach, meta)
        if approach_all is not None:
            approach_all_rows.append({
                **meta,
                "Approach Delay (s)": float(approach_all["all_mean"]),
                "sample_count": int(approach_all.get("all_count", 0) or 0),
                "aggregation_method": str(approach_all.get("aggregation_method", "metrics_pickle_sample_weighted")),
            })
        _append_rows(
            approach_ts_rows,
            _safe_required_sheet(path, "urban_ApproachDelay_ts", ["intersection_id", "window_start", "window_end"]),
            meta,
        )

        # Queue Length
        ql = _try_read_sheet(path, "urban_QueueLength")
        if ql is not None and not ql.empty:
            if {"intersection_id", "Average Queue", "Max Queue"}.issubset(ql.columns):
                _append_rows(queue_rows, ql, meta)
            elif {"Metric", "Value"}.issubset(ql.columns):
                ql_dict = dict(zip(ql["Metric"].astype(str), ql["Value"].astype(float)))
                queue_rows.append({
                    **meta,
                    "avg_queue_vehicles": _metric_value(ql_dict, "Avg Queued Vehicles", "Avg Queue (veh)"),
                    "max_queue_vehicles": _metric_value(ql_dict, "Max Queued Vehicles", "Max Queue (veh)"),
                    "avg_queue_cav": _metric_value(ql_dict, "Avg Queued CAV", "Avg Queue CAV"),
                    "avg_queue_hdv": _metric_value(ql_dict, "Avg Queued HDV", "Avg Queue HDV"),
                })
        _append_rows(
            queue_ts_rows,
            _normalize_queue_ts_df(
                _safe_required_sheet(path, "urban_QueueLength_ts", ["intersection_id", "window_start", "window_end"])
            ),
            meta,
        )
        _append_rows(
            queue_ts_rows,
            _normalize_queue_ts_df(
                _safe_required_sheet(path, "urban_QueueLength_cycles", ["intersection_id", "cycle_start", "cycle_end"])
            ),
            meta,
        )

        # v/c Ratio
        vc = _try_read_sheet(path, "urban_VC_Ratio", required=["Metric", "Value"])
        if vc is not None and not vc.empty:
            vc_dict = dict(zip(vc["Metric"].astype(str), vc["Value"].astype(float)))
            vc_rows.append({
                **meta,
                "vc_ratio_avg": vc_dict.get("Avg v/c", 0),
                "vc_ratio_max": vc_dict.get("Max v/c (critical)", 0),
                "volume_vph": vc_dict.get("Total Volume (vph)", 0),
                "capacity_vph": vc_dict.get("Total Capacity (vph)", 0),
            })
        _append_rows(
            vc_ts_rows,
            _safe_required_sheet(path, "urban_VC_Ratio_ts", ["intersection_id", "window_start", "window_end"]),
            meta,
        )

        # Spillback
        spillback_key = (float(meta["penetration_rate"]), meta.get("seed")) if average_seeds else float(meta["penetration_rate"])
        spillback_files = spillback_map.get(spillback_key)
        if not spillback_files:
            continue
        if not isinstance(spillback_files, list):
            spillback_files = [spillback_files]
        for spillback_file in spillback_files:
            if not spillback_file.exists():
                continue
            spill = pd.read_csv(spillback_file)
            if not spill.empty:
                if "Duration" in spill.columns:
                    durations = spill["Duration"].astype(float)
                elif {"Start", "End"}.issubset(spill.columns):
                    durations = spill["End"].astype(float) - spill["Start"].astype(float)
                elif {"start", "end"}.issubset(spill.columns):
                    durations = spill["end"].astype(float) - spill["start"].astype(float)
                else:
                    durations = pd.Series(dtype=float)
                spillback_rows.append({
                    **meta,
                    "event_count": int(len(spill)),
                    "avg_duration_s": float(durations.mean()) if len(durations) else float("nan"),
                    "max_duration_s": float(durations.max()) if len(durations) else float("nan"),
                    "total_duration_s": float(durations.sum()) if len(durations) else float("nan"),
                })

    tables = {
        "inventory": _sorted_df(inventory_rows, "penetration_rate"),
        "urban_Throughput": _sorted_df(throughput_rows, "penetration_rate"),
        "urban_Throughput_int": _sorted_df(throughput_int_rows, ["penetration_rate", "intersection_id"]),
        "urban_Throughput_ts": _sorted_df(throughput_ts_rows, ["penetration_rate", "intersection_id", "window_start", "window_end"]),
        "urban_AvgDelay": _sorted_df(avg_delay_rows, ["penetration_rate", "vehicle_type"]),
        "urban_AvgDelay_ts": _sorted_df(avg_delay_ts_rows, ["penetration_rate", "intersection_id", "window_start", "window_end"]),
        "urban_ApproachDelay": _sorted_df(approach_rows, ["penetration_rate", "vehicle_type"]),
        "urban_ApproachDelay_all": _sorted_df(approach_all_rows, "penetration_rate"),
        "urban_ApproachDelay_ts": _sorted_df(approach_ts_rows, ["penetration_rate", "intersection_id", "window_start", "window_end"]),
        "urban_QueueLength": _sorted_df(queue_rows, "penetration_rate"),
        "urban_QueueLength_ts": _sorted_df(queue_ts_rows, ["penetration_rate", "intersection_id", "window_start", "window_end"]),
        "urban_VC_Ratio": _sorted_df(vc_rows, "penetration_rate"),
        "urban_VC_Ratio_ts": _sorted_df(vc_ts_rows, ["penetration_rate", "intersection_id", "window_start", "window_end"]),
        "urban_Spillback": _sorted_df(spillback_rows, "penetration_rate"),
    }

    if average_seeds:
        tables["inventory_runs"] = tables["inventory"].copy()
        pen_group = ["penetration_rate", "penetration_pct", "requested_penetration_rate", "rounded_penetration_pct", "penetration_source"]
        pen_vehicle_group = pen_group + ["vehicle_type"]
        pen_int_group = pen_group + ["intersection_id"]
        pen_int_window_group = pen_int_group + ["window_start", "window_end"]
        tables["inventory"] = aggregate_mean_table(tables["inventory"], pen_group)
        tables["urban_Throughput"] = aggregate_mean_table(tables["urban_Throughput"], pen_group)
        tables["urban_Throughput_int"] = aggregate_mean_table(tables["urban_Throughput_int"], pen_int_group)
        tables["urban_Throughput_ts"] = aggregate_mean_table(tables["urban_Throughput_ts"], pen_int_window_group)
        tables["urban_AvgDelay"] = aggregate_mean_table(tables["urban_AvgDelay"], pen_vehicle_group)
        tables["urban_AvgDelay_ts"] = aggregate_mean_table(tables["urban_AvgDelay_ts"], pen_int_window_group)
        tables["urban_ApproachDelay"] = aggregate_mean_table(tables["urban_ApproachDelay"], pen_vehicle_group)
        tables["urban_ApproachDelay_all"] = aggregate_mean_table(tables["urban_ApproachDelay_all"], pen_group)
        tables["urban_ApproachDelay_ts"] = aggregate_mean_table(tables["urban_ApproachDelay_ts"], pen_int_window_group)
        if not tables["urban_QueueLength"].empty and "intersection_id" in tables["urban_QueueLength"].columns:
            queue_group = pen_group + [
                c for c in ["intersection_id", "tls_id", "approach_edge", "approach_direction"]
                if c in tables["urban_QueueLength"].columns
            ]
            tables["urban_QueueLength"] = aggregate_mean_table(tables["urban_QueueLength"], queue_group)
        else:
            tables["urban_QueueLength"] = aggregate_mean_table(tables["urban_QueueLength"], pen_group)
        if not tables["urban_QueueLength_ts"].empty:
            ts_cols = ["intersection_id"]
            if "window_start" in tables["urban_QueueLength_ts"].columns and "window_end" in tables["urban_QueueLength_ts"].columns:
                ts_cols += ["window_start", "window_end"]
            elif "cycle_start" in tables["urban_QueueLength_ts"].columns and "cycle_end" in tables["urban_QueueLength_ts"].columns:
                ts_cols += ["cycle_start", "cycle_end"]
            if "approach_direction" in tables["urban_QueueLength_ts"].columns:
                ts_cols.append("approach_direction")
            tables["urban_QueueLength_ts"] = aggregate_mean_table(tables["urban_QueueLength_ts"], pen_group + ts_cols)
        tables["urban_VC_Ratio"] = aggregate_mean_table(tables["urban_VC_Ratio"], pen_group)
        tables["urban_VC_Ratio_ts"] = aggregate_mean_table(tables["urban_VC_Ratio_ts"], pen_int_window_group)
        tables["urban_Spillback"] = aggregate_mean_table(tables["urban_Spillback"], pen_group)

    tables["urban_AvgDelay_int"] = _summarize_avg_delay_intersections(tables["urban_AvgDelay_ts"])
    tables["urban_VC_Ratio_int"] = _summarize_vc_intersections(tables["urban_VC_Ratio_ts"])

    queue_int_source = tables["urban_QueueLength"]
    if queue_int_source.empty or "intersection_id" not in queue_int_source.columns:
        queue_int_source = tables["urban_QueueLength_ts"]
    tables["urban_QueueLength_int"] = _summarize_queue_intersections(queue_int_source)

    out_path = Path(output_dir) / "urban_comparison.xlsx"
    write_tables(out_path, tables, also_write_csv=also_write_csv)

    plots_dir = Path(output_dir) / "plots"

    # Throughput trend
    plot_penetration_trend_single(
        tables["urban_Throughput"],
        value_col="vehicles_per_hour",
        out_png=plots_dir / "urban_throughput_trend.png",
        ylabel="Vehicles/hr",
        title="Throughput vs Penetration",
    )
    _plot_penetration_intersection_heatmap(
        tables["urban_Throughput_int"],
        value_col="mean_vehicles_per_hour",
        out_png=plots_dir / "urban_throughput_mean_heatmap.png",
        title="Throughput Heatmap: Mean Vehicles per Hour",
        colorbar_label="Mean Vehicles/hr",
    )

    # Average Delay by type
    avg_delay_baselines = _baseline_from_table(
        tables["urban_AvgDelay"],
        "Avg Delay (s)",
        vehicle_col="vehicle_type",
        vehicle_value="ALL",
    )
    plot_penetration_trend(
        tables["urban_AvgDelay"],
        value_col="Avg Delay (s)",
        out_png=plots_dir / "urban_avg_delay_trend.png",
        ylabel="Avg Delay (s)",
        title="Average Delay by Type vs Penetration",
        baselines=avg_delay_baselines,
    )
    _plot_penetration_intersection_heatmap(
        tables["urban_AvgDelay_int"],
        value_col="avg_delay_all",
        out_png=plots_dir / "urban_avg_delay_heatmap.png",
        title="Average Delay Heatmap: All Vehicles",
        colorbar_label="Average Delay (s)",
    )

    # Approach Delay by type
    plot_penetration_trend(
        tables["urban_ApproachDelay"],
        value_col="Approach Delay (s)",
        out_png=plots_dir / "urban_approach_delay_trend.png",
        ylabel="Approach Delay (s)",
        title="Approach Delay vs Penetration",
    )
    approach_baselines = _baseline_from_table(
        tables["urban_ApproachDelay_all"],
        "Approach Delay (s)",
    )
    plot_penetration_trend_single(
        tables["urban_ApproachDelay_all"],
        value_col="Approach Delay (s)",
        out_png=plots_dir / "urban_approach_delay_all_trend.png",
        ylabel="Approach Delay (All Vehicles) (s)",
        title="Overall Approach Delay vs Penetration",
        baselines=approach_baselines,
    )

    # Queue Length trend
    if not tables["urban_QueueLength"].empty and "avg_queue_vehicles" in tables["urban_QueueLength"].columns:
        queue_baselines = _baseline_from_table(
            tables["urban_QueueLength"],
            "avg_queue_vehicles",
        )
        plot_penetration_trend_single(
            tables["urban_QueueLength"],
            value_col="avg_queue_vehicles",
            out_png=plots_dir / "urban_queue_length_trend.png",
            ylabel="Avg Queue (vehicles)",
            title="Queue Length vs Penetration",
            baselines=queue_baselines,
        )
    _plot_penetration_intersection_heatmap(
        tables["urban_QueueLength_int"],
        value_col="avg_queued_vehicles",
        out_png=plots_dir / "urban_queue_avg_heatmap.png",
        title="Queue Heatmap: Average Queued Vehicles",
        colorbar_label="Avg Queued Vehicles",
    )
    _plot_penetration_intersection_heatmap(
        tables["urban_QueueLength_int"],
        value_col="max_queued_vehicles",
        out_png=plots_dir / "urban_queue_max_heatmap.png",
        title="Queue Heatmap: Max Queued Vehicles",
        colorbar_label="Max Queued Vehicles",
    )

    # v/c Ratio trend
    vc_avg_baselines = _baseline_from_table(
        tables["urban_VC_Ratio"],
        "vc_ratio_avg",
    )
    plot_penetration_trend_single(
        tables["urban_VC_Ratio"],
        value_col="vc_ratio_avg",
        out_png=plots_dir / "urban_vc_ratio_avg_trend.png",
        ylabel="Avg v/c Ratio",
        title="v/c Ratio vs Penetration",
        baselines=vc_avg_baselines,
    )
    _plot_penetration_intersection_heatmap(
        tables["urban_VC_Ratio_int"],
        value_col="vc_ratio_avg",
        out_png=plots_dir / "urban_vc_ratio_avg_heatmap.png",
        title="v/c Ratio Heatmap: Average v/c",
        colorbar_label="Average v/c Ratio",
    )
    vc_max_baselines = _baseline_from_table(
        tables["urban_VC_Ratio"],
        "vc_ratio_max",
    )
    plot_penetration_trend_single(
        tables["urban_VC_Ratio"],
        value_col="vc_ratio_max",
        out_png=plots_dir / "urban_vc_ratio_critical_trend.png",
        ylabel="Critical v/c Ratio",
        title="Critical v/c Ratio vs Penetration",
        baselines=vc_max_baselines,
    )
    _plot_penetration_intersection_heatmap(
        tables["urban_VC_Ratio_int"],
        value_col="vc_ratio_max",
        out_png=plots_dir / "urban_vc_ratio_critical_heatmap.png",
        title="v/c Ratio Heatmap: Critical v/c",
        colorbar_label="Critical v/c Ratio",
    )

    # Spillback trends
    plot_penetration_trend_single(
        tables["urban_Spillback"],
        value_col="event_count",
        out_png=plots_dir / "urban_spillback_event_count_trend.png",
        ylabel="Spillback Event Count",
        title="Spillback Event Count vs Penetration",
    )
    plot_penetration_trend_single(
        tables["urban_Spillback"],
        value_col="total_duration_s",
        out_png=plots_dir / "urban_spillback_total_duration_trend.png",
        ylabel="Total Spillback Duration (s)",
        title="Total Spillback Duration vs Penetration",
    )

    return out_path
