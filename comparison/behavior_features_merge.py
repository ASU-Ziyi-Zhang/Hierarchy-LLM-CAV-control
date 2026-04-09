# behavior_features_merge.py
from __future__ import annotations
import re
import unicodedata
from pathlib import Path
from typing import Dict, Optional, Tuple

import numpy as np
import pandas as pd

# ----------------- Robust helpers -----------------
def _norm_colname(name: str) -> str:
    s = str(name)
    s = unicodedata.normalize("NFKC", s)
    s = s.strip().lower()
    s = s.replace(" ", "").replace("\u00a0", "").replace("_", "")
    s = s.replace("penetration", "pen")
    # keep only [a-z0-9%]
    keep = []
    for ch in s:
        if ch.isalnum() or ch in ["%"]:
            keep.append(ch)
    s = "".join(keep)
    s = re.sub(r"^p(?=\d)", "pen", s)
    return s

def _find_bin_mid_col(df: pd.DataFrame) -> Optional[str]:
    cand = None
    for c in df.columns:
        n = _norm_colname(c)
        if n in ("binmid", "bin_mid", "binmids"):
            return c
        if n.startswith("bin") and "mid" in n:
            cand = c
    return cand

def _find_k_col(df: pd.DataFrame) -> Optional[str]:
    for c in df.columns:
        n = _norm_colname(c)
        if n in ("k", "lc", "lanechanges", "lanechange", "numlc"):
            return c
    return None

def _read_excel(path: Path, sheet: str) -> tuple[pd.DataFrame|None, str|None]:
    try:
        import openpyxl  # noqa
        df = pd.read_excel(path, sheet_name=sheet, engine="openpyxl")
        return df, None
    except Exception as e1:
        try:
            df = pd.read_excel(path, sheet_name=sheet)
            return df, None
        except Exception as e2:
            return None, f"{type(e1).__name__ or 'Error'} / {type(e2).__name__ or 'Error'}"

def _read_csv(path: Path) -> tuple[pd.DataFrame|None, str|None]:
    try:
        df = pd.read_csv(path)
        return df, None
    except Exception as e:
        return None, f"{type(e).__name__}"

# ----------------- descriptors -----------------
def _bin_widths(bin_mid: np.ndarray) -> np.ndarray:
    x = np.asarray(bin_mid, dtype=float)
    if len(x) <= 1:
        return np.ones_like(x)
    dx = np.diff(x)
    widths = np.empty_like(x)
    widths[1:-1] = 0.5 * (dx[:-1] + dx[1:])
    widths[0] = dx[0]
    widths[-1] = dx[-1]
    widths = np.where(widths <= 0, np.nan, widths)
    return widths

def _pdf_descriptors(bin_mid: np.ndarray, density: np.ndarray) -> tuple[float,float,float,float,float]:
    """连续型（Gap/SpaceGap）：mean, std, p10, p50, p90；自动按 bin 宽归一。"""
    x = np.asarray(bin_mid, dtype=float)
    f = np.asarray(density, dtype=float)
    w = _bin_widths(x)
    mask = ~(np.isnan(x) | np.isnan(f) | np.isnan(w))
    x, f, w = x[mask], f[mask], w[mask]
    if len(x) == 0:
        return np.nan, np.nan, np.nan, np.nan, np.nan
    area = float(np.sum(f * w))
    if not np.isfinite(area) or area <= 0:
        return np.nan, np.nan, np.nan, np.nan, np.nan
    f = f / area
    mean = float(np.sum(x * f * w))
    var = max(0.0, float(np.sum(((x - mean) ** 2) * f * w)))
    std = float(np.sqrt(var))
    order = np.argsort(x)
    xs, fs, ws = x[order], f[order], w[order]
    cdf = np.cumsum(fs * ws)
    cdf = np.clip(cdf, 0, 1)
    def q(p: float) -> float:
        idx = int(np.searchsorted(cdf, p, side="left"))
        if idx <= 0: return float(xs[0])
        if idx >= len(xs): return float(xs[-1])
        c0, c1 = cdf[idx-1], cdf[idx]; x0, x1 = xs[idx-1], xs[idx]
        if c1 == c0: return float(x0)
        t = (p - c0) / (c1 - c0)
        return float(x0 + t * (x1 - x0))
    return mean, std, q(0.10), q(0.50), q(0.90)

def _pmf_descriptors(k_vals: np.ndarray, values: np.ndarray) -> tuple[float,float,float,float,float]:
    """离散型（LC）：自动归一后给 mean, std, p10, p50, p90（按离散 CDF 插值）。"""
    k = np.asarray(k_vals, dtype=float)
    v = np.asarray(values, dtype=float)
    mask = ~(np.isnan(k) | np.isnan(v))
    k, v = k[mask], v[mask]
    tot = float(np.sum(v))
    if not np.isfinite(tot) or tot <= 0:
        return np.nan, np.nan, np.nan, np.nan, np.nan
    p = v / tot
    mean = float(np.sum(k * p))
    var = max(0.0, float(np.sum(((k - mean) ** 2) * p)))
    std = float(np.sqrt(var))
    order = np.argsort(k)
    ks, ps = k[order], p[order]
    cdf = np.cumsum(ps); cdf = np.clip(cdf, 0, 1)
    def q(pv: float) -> float:
        idx = int(np.searchsorted(cdf, pv, side="left"))
        if idx <= 0: return float(ks[0])
        if idx >= len(ks): return float(ks[-1])
        c0, c1 = cdf[idx-1], cdf[idx]; x0, x1 = ks[idx-1], ks[idx]
        if c1 == c0: return float(x0)
        t = (pv - c0) / (c1 - c0)
        return float(x0 + t * (x1 - x0))
    return mean, std, q(0.10), q(0.50), q(0.90)

def _pmf_share_over(k_vals: np.ndarray, values: np.ndarray, thr: float) -> float:
    k = np.asarray(k_vals, dtype=float)
    v = np.asarray(values, dtype=float)
    mask = ~(np.isnan(k) | np.isnan(v))
    k, v = k[mask], v[mask]
    tot = float(np.sum(v))
    if not np.isfinite(tot) or tot <= 0:
        return np.nan
    return float(np.sum(v[k > thr]) / tot)

# ----------------- Core builder -----------------
def build_behavior_features(
    input_dir: str,
    output_dir: str,
    behavior_xlsx_name: str = "behavior_tables.xlsx",
    lc_mean_csv_name: str = "summary_lc_mean.csv",
    lc_share_csv_name: str = "summary_lc_share_over_3.csv",
    lc_threshold: int = 3,
) -> str:
    """
    汇总 BEHAVIOR 指标（按渗透率）：
      - 从 behavior_tables.xlsx 读取 9 个 sheet（LC/Gap/SpaceGap × HDV/CAV/Combined）
        * LC：k + penXX%（离散 PMF/或频数——自动归一）
        * Gap/SpaceGap：bin_mid + penXX%（连续 PDF——自动按 bin 宽归一）
        计算 mean/std/p10/p50/p90；LC 还可计算 share(k>lc_threshold)
      - 并入：
        * summary_lc_mean.csv            → LC_mean（HDV/CAV/Mixed）
        * summary_lc_share_over_5.csv    → LC_share_over_5（HDV/CAV/Mixed）
    输出：
      - behavior_features_by_penetration.xlsx （Sheets: Mixed / CAV / HDV）
      - behavior_features_mixed.csv / _cav.csv / _hdv.csv
      - skipped_files.txt
    """
    in_dir = Path(input_dir)
    out_dir = Path(output_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    skipped = []

    # 1) 读行为总表
    xlsx_path = in_dir / behavior_xlsx_name
    if not xlsx_path.exists():
        raise FileNotFoundError(f"Not found: {xlsx_path}")

    try:
        import openpyxl  # noqa
        xl = pd.ExcelFile(xlsx_path, engine="openpyxl")
    except Exception:
        xl = pd.ExcelFile(xlsx_path)

    features: Dict[str, Dict[int, dict]] = {"Mixed": {}, "CAV": {}, "HDV": {}}
    def row_for(group: str, pen: int) -> dict:
        if pen not in features[group]:
            features[group][pen] = {"penetration": pen}
        return features[group][pen]

    for sh in xl.sheet_names:
        # 识别 LC/Gap/SpaceGap × HDV/CAV/Combined
        m = re.match(r"(?i)^(?:behavior_)?(lc|gap|spacegap)_(hdv|cav|combined)$", sh.strip())
        if not m:
            skipped.append((sh, "sheet name not recognized as (LC|Gap|SpaceGap)_(HDV|CAV|Combined)"))
            continue
        metric_key = m.group(1).lower()       # lc/gap/spacegap
        veh = m.group(2).lower()              # hdv/cav/combined
        group = "Mixed" if veh == "combined" else veh.upper()

        df, err = _read_excel(xlsx_path, sh)
        if err:
            skipped.append((sh, f"read error: {err}"))
            continue

        # 找渗透率列
        pen_col_map = {}
        for c in df.columns:
            n = _norm_colname(c)
            mpen = re.match(r"^pen(\d+)(%?)$", n)
            if mpen:
                pen_col_map[int(mpen.group(1))] = c
        if not pen_col_map:
            skipped.append((sh, f"no 'penXX' columns found; columns={list(df.columns)}"))
            continue

        if metric_key == "lc":
            k_col = _find_k_col(df)
            if k_col is None:
                skipped.append((sh, "missing 'k' column for LC"))
                continue
            ks = df[k_col].to_numpy(dtype=float)
            for pen in sorted(pen_col_map.keys()):
                vals = df[pen_col_map[pen]].to_numpy(dtype=float)  # 可能是频数或概率，自动归一
                mean, std, p10, p50, p90 = _pmf_descriptors(ks, vals)
                share_over = _pmf_share_over(ks, vals, lc_threshold)
                r = row_for(group, pen)
                r["LC_mean"] = mean
                r["LC_std"]  = std
                r["LC_p10"]  = p10
                r["LC_p50"]  = p50
                r["LC_p90"]  = p90
                r[f"LC_share_over_{lc_threshold}"] = share_over
        else:
            # Gap / SpaceGap
            bin_col = _find_bin_mid_col(df)
            if bin_col is None:
                skipped.append((sh, f"missing 'bin_mid' (got columns: {list(df.columns)})"))
                continue
            xs = df[bin_col].to_numpy(dtype=float)
            base = "Gap" if metric_key == "gap" else "SpaceGap"
            for pen in sorted(pen_col_map.keys()):
                dens = df[pen_col_map[pen]].to_numpy(dtype=float)  # 视为密度（若不是也会自动归一）
                mean, std, p10, p50, p90 = _pdf_descriptors(xs, dens)
                r = row_for(group, pen)
                r[f"{base}_mean"] = mean
                r[f"{base}_std"]  = std
                r[f"{base}_p10"]  = p10
                r[f"{base}_p50"]  = p50
                r[f"{base}_p90"]  = p90

    # 2) 并入 LC 的两个 CSV
    # 2.1 mean
    csv_mean = in_dir / "summary_lc_mean.csv"
    if csv_mean.exists():
        dfm, err = _read_csv(csv_mean)
        if err:
            skipped.append(("summary_lc_mean.csv", f"csv read error: {err}"))
        else:
            for _, r in dfm.iterrows():
                try:
                    pen = int(r["penetration"])
                except Exception:
                    continue
                for group, col in [("HDV","HDV_mean_LC"), ("CAV","CAV_mean_LC"), ("Mixed","Mixed_mean_LC")]:
                    if col in dfm.columns and pd.notna(r[col]):
                        row_for(group, pen)["LC_mean"] = float(r[col])  # 用 CSV 的均值覆盖/补充
    else:
        skipped.append(("summary_lc_mean.csv", "file not found"))

    # 2.2 share_over_3（阈值以文件含义为准）
    csv_share = in_dir / "summary_lc_share_over_3.csv"
    if csv_share.exists():
        dfs, err = _read_csv(csv_share)
        if err:
            skipped.append(("summary_lc_share_over_3.csv", f"csv read error: {err}"))
        else:
            for _, r in dfs.iterrows():
                try:
                    pen = int(r["penetration"])
                except Exception:
                    continue
                for group, col in [("HDV","HDV_share"), ("CAV","CAV_share"), ("Mixed","Mixed_share")]:
                    if col in dfs.columns and pd.notna(r[col]):
                        row_for(group, pen)[f"LC_share_over_{lc_threshold}"] = float(r[col])
    else:
        skipped.append(("summary_lc_share_over_3.csv", "file not found"))

    # 3) 输出
    dfs_out: Dict[str, pd.DataFrame] = {}
    for group in ["Mixed", "CAV", "HDV"]:
        if features[group]:
            df = pd.DataFrame(list(features[group].values()))
            cols = ["penetration"] + sorted([c for c in df.columns if c != "penetration"])
            dfs_out[group] = df[cols].sort_values("penetration")
        else:
            dfs_out[group] = pd.DataFrame(columns=["penetration"])

    out_dir = Path(output_dir)
    dfs_out["Mixed"].to_csv(out_dir / "behavior_features_mixed.csv", index=False)
    dfs_out["CAV"].to_csv(out_dir / "behavior_features_cav.csv", index=False)
    dfs_out["HDV"].to_csv(out_dir / "behavior_features_hdv.csv", index=False)

    xlsx_out = out_dir / "behavior_features_by_penetration.xlsx"
    with pd.ExcelWriter(xlsx_out, engine="xlsxwriter") as writer:
        dfs_out["Mixed"].to_excel(writer, sheet_name="Mixed", index=False)
        dfs_out["CAV"].to_excel(writer, sheet_name="CAV", index=False)
        dfs_out["HDV"].to_excel(writer, sheet_name="HDV", index=False)

    if skipped:
        with open(out_dir / "skipped_files.txt", "w", encoding="utf-8") as fh:
            fh.write("Notes about missing/unread inputs or sheets:\n")
            for name, reason in skipped:
                fh.write(f"- {name}: {reason}\n")

    return str(xlsx_out)