from __future__ import annotations

import math
import re
from pathlib import Path
from typing import Dict, Iterable

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def discover_dataset_files(input_dir: str | Path, *, include_all_runs: bool = False) -> list[Path]:
    in_dir = Path(input_dir)
    candidates = sorted(in_dir.glob("*_datasets.xlsx"))
    if not candidates:
        raise FileNotFoundError(f"No '*_datasets.xlsx' files found in {in_dir}")

    if include_all_runs:
        return sorted(
            candidates,
            key=lambda path: (
                round(float(parse_run_identity(path)["penetration_rate"]), 6),
                -1 if parse_run_identity(path).get("seed") is None else int(parse_run_identity(path)["seed"]),
                path.stat().st_mtime,
                path.name,
            ),
        )

    chosen: dict[float, tuple[tuple[int, float], Path]] = {}
    for path in candidates:
        meta = parse_run_identity(path)
        key = round(float(meta["penetration_rate"]), 6)
        score = (
            1 if meta.get("requested_penetration_rate") is not None else 0,
            path.stat().st_mtime,
        )
        current = chosen.get(key)
        if current is None or score > current[0]:
            chosen[key] = (score, path)

    return [item[1] for _, item in sorted(chosen.items(), key=lambda kv: kv[0])]


def parse_run_identity(path: str | Path) -> dict:
    """
    Parse a dashboard export filename.

    Preferred modern pattern:
      <scenario>_p0.3_cav30_datasets.xlsx
      <scenario>_p0.3_seed23423_cav30_datasets.xlsx

    Legacy fallback pattern:
      <scenario>_cav30_datasets.xlsx
    """
    stem = Path(path).stem.lower()

    p_match = re.search(r"(?:^|[_-])p(?P<rate>\d+(?:\.\d+)?)(?=[_-]|$)", stem)
    seed_match = re.search(r"(?:^|[_-])seed(?P<seed>\d+)(?=[_-]|$)", stem)
    cav_match = re.search(r"(?:^|[_-])cav(?P<pct>\d+)(?=[_-]|$)", stem)

    requested_rate = float(p_match.group("rate")) if p_match else None
    seed = int(seed_match.group("seed")) if seed_match else None
    cav_pct = float(cav_match.group("pct")) if cav_match else None

    rounded_pct = None

    if requested_rate is not None:
        rate = requested_rate
        rounded_pct = round(rate * 100.0)
        source = "requested_penetration_tag"
    elif cav_pct is not None:
        rounded_pct = int(round(cav_pct / 10.0) * 10)
        rate = rounded_pct / 100.0
        source = "legacy_cav_pct_rounded_to_decile"
    else:
        raise ValueError(
            f"Cannot infer penetration from filename: {Path(path).name}. "
            "Expected '_p0.3_' or '_cav30_'."
        )

    return {
        "file_name": Path(path).name,
        "run_label": Path(path).stem,
        "seed": seed,
        "seed_tag": f"seed{seed}" if seed is not None else None,
        "penetration_rate": float(rate),
        "penetration_pct": float(rate * 100.0),
        "requested_penetration_rate": requested_rate,
        "actual_cav_pct_from_name": cav_pct,
        "rounded_penetration_pct": rounded_pct,
        "penetration_source": source,
    }


def read_sheet(path: str | Path, sheet_name: str, required: Iterable[str] | None = None) -> pd.DataFrame:
    df = pd.read_excel(path, sheet_name=sheet_name, engine="openpyxl")
    if required:
        missing = [col for col in required if col not in df.columns]
        if missing:
            raise ValueError(f"[{Path(path).name}] sheet '{sheet_name}' missing columns: {missing}")
    return df


def _safe_float(value) -> float:
    try:
        out = float(value)
    except Exception:
        return float("nan")
    return out


def _quantile_from_hist(bin_left: np.ndarray, bin_right: np.ndarray, counts: np.ndarray, q: float) -> float:
    total = float(np.sum(counts))
    if total <= 0:
        return float("nan")

    target = q * total
    cum = 0.0
    for left, right, count in zip(bin_left, bin_right, counts):
        count = float(count)
        if count <= 0:
            continue
        next_cum = cum + count
        if target <= next_cum:
            frac = (target - cum) / count
            frac = min(max(frac, 0.0), 1.0)
            return float(left + frac * (right - left))
        cum = next_cum
    return float(bin_right[-1]) if len(bin_right) else float("nan")


def _risk_share_below(bin_left: np.ndarray, bin_right: np.ndarray, counts: np.ndarray, threshold: float) -> float:
    total = float(np.sum(counts))
    if total <= 0:
        return float("nan")

    share = 0.0
    for left, right, count in zip(bin_left, bin_right, counts):
        count = float(count)
        if count <= 0:
            continue
        if right <= threshold:
            share += count
        elif left < threshold < right:
            frac = (threshold - left) / max(right - left, 1e-12)
            share += count * min(max(frac, 0.0), 1.0)
    return float(share / total)


def _risk_share_above(bin_left: np.ndarray, bin_right: np.ndarray, counts: np.ndarray, threshold: float) -> float:
    total = float(np.sum(counts))
    if total <= 0:
        return float("nan")
    return float(1.0 - _risk_share_below(bin_left, bin_right, counts, threshold))


def summarize_histogram(
    df: pd.DataFrame,
    *,
    risk_threshold: float | None = None,
    risk_direction: str | None = None,
    include_mixed: bool = True,
) -> pd.DataFrame:
    needed = ["bin_left", "bin_right", "bin_mid", "HDV", "CAV"]
    missing = [col for col in needed if col not in df.columns]
    if missing:
        raise ValueError(f"Histogram table missing columns: {missing}")

    work = df.copy()
    work["Mixed"] = work["HDV"].astype(float) + work["CAV"].astype(float)

    rows = []
    bin_left = work["bin_left"].to_numpy(dtype=float)
    bin_right = work["bin_right"].to_numpy(dtype=float)
    bin_mid = work["bin_mid"].to_numpy(dtype=float)

    vehicle_types = ["HDV", "CAV"] + (["Mixed"] if include_mixed else [])
    for veh_type in vehicle_types:
        counts = work[veh_type].to_numpy(dtype=float)
        sample_count = float(np.sum(counts))
        if sample_count <= 0:
            rows.append(
                {
                    "vehicle_type": veh_type,
                    "sample_count": 0,
                    "mean": np.nan,
                    "std": np.nan,
                    "p05": np.nan,
                    "p10": np.nan,
                    "p50": np.nan,
                    "p90": np.nan,
                    "p95": np.nan,
                    "risk_share": np.nan,
                }
            )
            continue

        mean = float(np.sum(bin_mid * counts) / sample_count)
        var = float(np.sum(((bin_mid - mean) ** 2) * counts) / sample_count)

        row = {
            "vehicle_type": veh_type,
            "sample_count": int(sample_count),
            "mean": mean,
            "std": math.sqrt(max(var, 0.0)),
            "p05": _quantile_from_hist(bin_left, bin_right, counts, 0.05),
            "p10": _quantile_from_hist(bin_left, bin_right, counts, 0.10),
            "p50": _quantile_from_hist(bin_left, bin_right, counts, 0.50),
            "p90": _quantile_from_hist(bin_left, bin_right, counts, 0.90),
            "p95": _quantile_from_hist(bin_left, bin_right, counts, 0.95),
            "risk_share": np.nan,
        }

        if risk_threshold is not None and risk_direction:
            if risk_direction == "below":
                row["risk_share"] = _risk_share_below(bin_left, bin_right, counts, risk_threshold)
            elif risk_direction == "above":
                row["risk_share"] = _risk_share_above(bin_left, bin_right, counts, risk_threshold)
            else:
                raise ValueError(f"Unsupported risk_direction: {risk_direction}")

        rows.append(row)

    return pd.DataFrame(rows)


def summarize_discrete_counts(
    df: pd.DataFrame,
    *,
    value_col: str,
    risk_threshold: float | None = None,
    risk_direction: str | None = None,
    include_mixed: bool = True,
) -> pd.DataFrame:
    needed = [value_col, "HDV", "CAV"]
    missing = [col for col in needed if col not in df.columns]
    if missing:
        raise ValueError(f"Discrete table missing columns: {missing}")

    work = df.copy()
    work["Mixed"] = work["HDV"].astype(float) + work["CAV"].astype(float)

    rows = []
    values = work[value_col].to_numpy(dtype=float)
    vehicle_types = ["HDV", "CAV"] + (["Mixed"] if include_mixed else [])

    for veh_type in vehicle_types:
        counts = work[veh_type].to_numpy(dtype=float)
        total = float(np.sum(counts))
        if total <= 0:
            rows.append(
                {
                    "vehicle_type": veh_type,
                    "sample_count": 0,
                    "mean": np.nan,
                    "std": np.nan,
                    "p50": np.nan,
                    "p90": np.nan,
                    "p95": np.nan,
                    "risk_share": np.nan,
                }
            )
            continue

        mean = float(np.sum(values * counts) / total)
        var = float(np.sum(((values - mean) ** 2) * counts) / total)

        order = np.argsort(values)
        xs = values[order]
        cs = counts[order]
        cdf = np.cumsum(cs) / total

        def _q(level: float) -> float:
            idx = int(np.searchsorted(cdf, level, side="left"))
            idx = min(max(idx, 0), len(xs) - 1)
            return float(xs[idx])

        risk_share = np.nan
        if risk_threshold is not None and risk_direction:
            if risk_direction == "below":
                risk_share = float(np.sum(cs[xs < risk_threshold]) / total)
            elif risk_direction == "above":
                risk_share = float(np.sum(cs[xs > risk_threshold]) / total)
            else:
                raise ValueError(f"Unsupported risk_direction: {risk_direction}")

        rows.append(
            {
                "vehicle_type": veh_type,
                "sample_count": int(total),
                "mean": mean,
                "std": math.sqrt(max(var, 0.0)),
                "p50": _q(0.50),
                "p90": _q(0.90),
                "p95": _q(0.95),
                "risk_share": risk_share,
            }
        )

    return pd.DataFrame(rows)


def summarize_vehicle_count_ts(df: pd.DataFrame) -> pd.DataFrame:
    needed = ["Time(s)", "HDV", "CAV"]
    missing = [col for col in needed if col not in df.columns]
    if missing:
        raise ValueError(f"Vehicle-count table missing columns: {missing}")

    work = df.copy().sort_values("Time(s)")
    work["Mixed"] = work["HDV"].astype(float) + work["CAV"].astype(float)

    times = work["Time(s)"].to_numpy(dtype=float)
    dt = float(np.median(np.diff(times))) if len(times) > 1 else np.nan
    rows = []
    for veh_type in ["HDV", "CAV", "Mixed"]:
        vals = work[veh_type].to_numpy(dtype=float)
        rows.append(
            {
                "vehicle_type": veh_type,
                "avg_count": float(np.mean(vals)) if len(vals) else np.nan,
                "max_count": float(np.max(vals)) if len(vals) else np.nan,
                "p95_count": float(np.percentile(vals, 95)) if len(vals) else np.nan,
                "time_step_s": dt,
                "vehicle_seconds": float(np.sum(vals) * dt) if len(vals) and np.isfinite(dt) else np.nan,
            }
        )
    return pd.DataFrame(rows)


def append_run_metadata(df: pd.DataFrame, meta: Dict) -> pd.DataFrame:
    out = df.copy()
    meta_cols = [
        "file_name",
        "run_label",
        "seed_tag",
        "seed",
        "penetration_rate",
        "penetration_pct",
        "requested_penetration_rate",
        "actual_cav_pct_from_name",
        "rounded_penetration_pct",
        "penetration_source",
    ]
    for col in reversed(meta_cols):
        out.insert(0, col, meta.get(col))
    return out


def concat_and_sort(frames: list[pd.DataFrame]) -> pd.DataFrame:
    if not frames:
        return pd.DataFrame()
    df = pd.concat(frames, ignore_index=True)
    sort_cols = [col for col in ["penetration_rate", "vehicle_type"] if col in df.columns]
    if sort_cols:
        df = df.sort_values(sort_cols).reset_index(drop=True)
    return df


def aggregate_mean_table(df: pd.DataFrame, group_cols: Iterable[str]) -> pd.DataFrame:
    if df is None or df.empty:
        return pd.DataFrame()

    work = df.copy()
    group_cols = [col for col in group_cols if col in work.columns]
    if not group_cols:
        return work

    dropped_run_cols = {"file_name", "run_label", "seed_tag"}
    numeric_cols = [
        col
        for col in work.select_dtypes(include=[np.number]).columns
        if col not in group_cols and col != "seed"
    ]

    agg_spec: dict[str, str] = {col: "mean" for col in numeric_cols}
    for col in work.columns:
        if col in group_cols or col in numeric_cols or col == "seed" or col in dropped_run_cols:
            continue
        agg_spec[col] = "first"

    grouped_obj = work.groupby(group_cols, dropna=False)
    grouped = grouped_obj.agg(agg_spec).reset_index()
    grouped["run_count"] = grouped_obj.size().to_numpy()
    if "seed" in work.columns:
        grouped["seed_count"] = grouped_obj["seed"].agg(
            lambda s: int(s.nunique(dropna=True)) if s.notna().any() else int(len(s))
        ).to_numpy()
    grouped["aggregation"] = "mean"

    sort_cols = [col for col in ["penetration_rate", "Time", "vehicle_type", "metric", "statistic"] if col in grouped.columns]
    if sort_cols:
        grouped = grouped.sort_values(sort_cols).reset_index(drop=True)
    return grouped


def write_tables(output_xlsx: str | Path, tables: Dict[str, pd.DataFrame], *, also_write_csv: bool = True) -> Path:
    output_xlsx = Path(output_xlsx)
    output_xlsx.parent.mkdir(parents=True, exist_ok=True)

    with pd.ExcelWriter(output_xlsx, engine="xlsxwriter") as writer:
        for sheet_name, df in tables.items():
            if df is None or df.empty:
                continue
            df.to_excel(writer, sheet_name=sheet_name[:31], index=False)

    if also_write_csv:
        for sheet_name, df in tables.items():
            if df is None or df.empty:
                continue
            csv_path = output_xlsx.parent / f"{sheet_name}.csv"
            df.to_csv(csv_path, index=False)

    return output_xlsx


def plot_penetration_trend(
    df: pd.DataFrame,
    *,
    value_col: str,
    out_png: str | Path,
    ylabel: str | None = None,
    title: str | None = None,
    vehicle_col: str = "vehicle_type",
    vehicle_types: Iterable[str] | None = None,
    min_penetration_pct: float = 10.0,
    baselines: Iterable[dict] | None = None,
):
    """
    Plot one metric against penetration.

    Expected columns:
      - penetration_pct
      - value_col
      - vehicle_col (optional but typical)
    """
    if df is None or df.empty or value_col not in df.columns:
        return None

    work = df.copy()
    if "penetration_pct" not in work.columns:
        return None
    work = work[work["penetration_pct"].astype(float) >= float(min_penetration_pct)].copy()
    if work.empty:
        return None

    if vehicle_col not in work.columns:
        work[vehicle_col] = "ALL"

    if vehicle_types is None:
        vehicle_types = [vt for vt in ["HDV", "CAV", "MIXED", "Mixed", "ALL"] if vt in set(work[vehicle_col].astype(str))]
        if not vehicle_types:
            vehicle_types = sorted(work[vehicle_col].dropna().astype(str).unique())

    colors = {
        "HDV": "#1f77b4",
        "CAV": "#d62728",
        "MIXED": "#2ca02c",
        "Mixed": "#2ca02c",
        "ALL": "#9467bd",
    }

    fig, ax = plt.subplots(figsize=(7.2, 4.8))
    plotted = False

    for vt in vehicle_types:
        sub = work[work[vehicle_col].astype(str) == str(vt)].copy()
        if sub.empty:
            continue
        sub = sub[["penetration_pct", value_col]].dropna().sort_values("penetration_pct")
        if sub.empty:
            continue
        ax.plot(
            sub["penetration_pct"],
            sub[value_col],
            marker="o",
            linewidth=2.0,
            markersize=5,
            label=str(vt),
            color=colors.get(str(vt), None),
        )
        plotted = True

    if not plotted:
        plt.close(fig)
        return None

    ax.set_xlabel("Penetration (%)")
    ax.set_ylabel(ylabel or value_col)
    if title:
        ax.set_title(title)

    if baselines:
        for base in baselines:
            y = base.get("y")
            if y is None or not np.isfinite(float(y)):
                continue
            ax.axhline(
                float(y),
                color=base.get("color", "#444444"),
                linestyle=base.get("linestyle", "--"),
                linewidth=float(base.get("linewidth", 1.5)),
                alpha=float(base.get("alpha", 0.9)),
                label=base.get("label"),
            )

    ax.grid(True, linestyle="--", alpha=0.35)
    ax.legend(frameon=False)

    out_png = Path(out_png)
    out_png.parent.mkdir(parents=True, exist_ok=True)
    fig.tight_layout()
    fig.savefig(out_png, dpi=180)
    plt.close(fig)
    return out_png


def plot_penetration_trend_single(
    df: pd.DataFrame,
    *,
    value_col: str,
    out_png: str | Path,
    ylabel: str | None = None,
    title: str | None = None,
    min_penetration_pct: float = 10.0,
    baselines: Iterable[dict] | None = None,
):
    """
    Plot one scalar metric against penetration when there is no vehicle-type split.
    """
    if df is None or df.empty or value_col not in df.columns or "penetration_pct" not in df.columns:
        return None

    work = df[["penetration_pct", value_col]].dropna().copy()
    work = work[work["penetration_pct"].astype(float) >= float(min_penetration_pct)].sort_values("penetration_pct")
    if work.empty:
        return None

    fig, ax = plt.subplots(figsize=(7.2, 4.8))
    ax.plot(work["penetration_pct"], work[value_col], marker="o", linewidth=2.0, markersize=5, color="#1f77b4")
    ax.set_xlabel("Penetration (%)")
    ax.set_ylabel(ylabel or value_col)
    if title:
        ax.set_title(title)
    if baselines:
        for base in baselines:
            y = base.get("y")
            if y is None or not np.isfinite(float(y)):
                continue
            ax.axhline(
                float(y),
                color=base.get("color", "#444444"),
                linestyle=base.get("linestyle", "--"),
                linewidth=float(base.get("linewidth", 1.5)),
                alpha=float(base.get("alpha", 0.9)),
                label=base.get("label"),
            )
    ax.grid(True, linestyle="--", alpha=0.35)
    if baselines:
        ax.legend(frameon=False)

    out_png = Path(out_png)
    out_png.parent.mkdir(parents=True, exist_ok=True)
    fig.tight_layout()
    fig.savefig(out_png, dpi=180)
    plt.close(fig)
    return out_png
