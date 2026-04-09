# mobility_features_merge.py
from __future__ import annotations
import re
import unicodedata
from pathlib import Path
from typing import Dict, Optional, Tuple

import numpy as np
import pandas as pd

# ----------------- Robust column helpers -----------------
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

# ----------------- PDF descriptors -----------------
def _bin_widths(bin_mid: np.ndarray) -> np.ndarray:
    x = np.asarray(bin_mid, dtype=float)
    if len(x) <= 1:
        return np.ones_like(x)
    # midpoints -> estimate widths by neighbor distances
    dx = np.diff(x)
    # interior width = (prev_gap + next_gap)/2; endpoints use nearest gap
    widths = np.empty_like(x)
    widths[1:-1] = 0.5 * (dx[:-1] + dx[1:])
    widths[0] = dx[0]
    widths[-1] = dx[-1]
    widths = np.where(widths <= 0, np.nan, widths)
    return widths

def _pdf_descriptors(
    bin_mid: np.ndarray,
    density: np.ndarray,
) -> tuple[float, float, float, float, float]:
    """
    对已是“概率密度”的直方图列计算：
    - mean, std
    - p10, p50, p90   （mobility 方向常用）
    注：自动按 bin 宽度归一，保证 ∫f dx = 1
    """
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
        if idx <= 0:
            return float(xs[0])
        if idx >= len(xs):
            return float(xs[-1])
        c0, c1 = cdf[idx-1], cdf[idx]
        x0, x1 = xs[idx-1], xs[idx]
        if c1 == c0:
            return float(x0)
        t = (p - c0) / (c1 - c0)
        return float(x0 + t * (x1 - x0))

    p10, p50, p90 = q(0.10), q(0.50), q(0.90)
    return mean, std, p10, p50, p90

# ----------------- Core builder -----------------
def build_mobility_features(
    input_dir: str,
    output_dir: str,
    density_xlsx_name: str = "mobility_density_tables.xlsx",
    delay_csv_name: str = "summary_delay_compare.csv",
) -> str:
    """
    汇总 MOBILITY 指标（按渗透率）：
      - 从 mobility_density_tables.xlsx 读取 9 个 sheet（Speed/Accel/TT × HDV/CAV/Combined）
        计算 mean/std/p10/p50/p90
      - 从 summary_delay_compare.csv 并入 Delay per Mile / Total Delay / Miles Traveled（HDV/CAV/Mixed）
    输出：
      - mobility_features_by_penetration.xlsx （Sheets: Mixed / CAV / HDV）
      - mobility_features_mixed.csv / _cav.csv / _hdv.csv
      - skipped_files.txt
    """
    in_dir = Path(input_dir)
    out_dir = Path(output_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    skipped = []

    # 1) 读取密度总表
    xlsx_path = in_dir / density_xlsx_name
    if not xlsx_path.exists():
        raise FileNotFoundError(f"Not found: {xlsx_path}")

    try:
        import openpyxl  # noqa
        xl = pd.ExcelFile(xlsx_path, engine="openpyxl")
    except Exception:
        xl = pd.ExcelFile(xlsx_path)

    # 目标 sheet：Speed/Accel/TT × HDV/CAV/Combined
    # 允许大小写差异，按正则解析
    features: Dict[str, Dict[int, dict]] = {"Mixed": {}, "CAV": {}, "HDV": {}}

    def row_for(group: str, pen: int) -> dict:
        if pen not in features[group]:
            features[group][pen] = {"penetration": pen}
        return features[group][pen]

    for sh in xl.sheet_names:
        m = re.match(r"(?i)^(speed|accel|tt)_(hdv|cav|combined)$", sh.strip())
        if not m:
            # 兼容旧命名：mobility_Speed_HDV 这类
            m2 = re.match(r"(?i)^(?:mobility_)?(speed|accel|tt)_(hdv|cav|combined)$", sh.strip())
            if not m2:
                skipped.append((sh, "sheet name not recognized as (Speed|Accel|TT)_(HDV|CAV|Combined)"))
                continue
            m = m2
        metric = m.group(1).capitalize()      # 'Speed'/'Accel'/'Tt'
        veh = m.group(2).capitalize()         # 'Hdv'/'Cav'/'Combined'
        metric = "TT" if metric.lower() in ["tt", "traveltime", "time","tt_hist"] else metric
        group = "Mixed" if veh.lower() == "combined" else veh.upper()

        df, err = _read_excel(xlsx_path, sh)
        if err:
            skipped.append((sh, f"read error: {err}"))
            continue

        bin_col = _find_bin_mid_col(df)
        if bin_col is None:
            skipped.append((sh, f"missing 'bin_mid' (got columns: {list(df.columns)})"))
            continue
        x = df[bin_col].to_numpy()

        # 渗透率列映射
        pen_col_map = {}
        for c in df.columns:
            n = _norm_colname(c)
            mpen = re.match(r"^pen(\d+)(%?)$", n)
            if mpen:
                pen_col_map[int(mpen.group(1))] = c
        if not pen_col_map:
            skipped.append((sh, f"no 'penXX' columns found; columns={list(df.columns)}"))
            continue

        # 逐渗透率计算描述符
        for pen in sorted(pen_col_map.keys()):
            dens = df[pen_col_map[pen]].to_numpy(dtype=float)
            mean, std, p10, p50, p90 = _pdf_descriptors(x, dens)
            r = row_for(group, pen)
            base = metric  # 'Speed'/'Accel'/'TT'
            r[f"{base}_mean"] = mean
            r[f"{base}_std"]  = std
            r[f"{base}_p10"]  = p10
            r[f"{base}_p50"]  = p50
            r[f"{base}_p90"]  = p90

    # 2) 并入 Delay 汇总（CSV 现成）
    delay_csv = in_dir / delay_csv_name
    if delay_csv.exists():
        df_delay, err = _read_csv(delay_csv)
        if err:
            skipped.append((delay_csv_name, f"csv read error: {err}"))
        else:
            # ---- 修正版：直接按列名显式匹配 ----
            for _, r in df_delay.iterrows():
                try:
                    pen = int(r["penetration"])
                except Exception:
                    continue
                # 三类群体：HDV / CAV / Mixed
                for group, prefix in [("HDV", "HDV_"), ("CAV", "CAV_"), ("Mixed", "Mixed_")]:
                    row = row_for(group, pen)
                    for suffix in [
                        "Delay per Mile (s/mile)",
                        "Total Delay (s)",
                        "Miles Traveled",
                    ]:
                        col = f"{prefix}{suffix}"
                        if col in df_delay.columns:
                            # 生成简洁键名，如 DelayPerMile, TotalDelay, MilesTraveled
                            key = suffix.replace(" (s/mile)", "").replace(" (s)", "").replace(" ", "")
                            row[f"{key}"] = float(r[col]) if pd.notna(r[col]) else np.nan
    else:
        skipped.append((delay_csv_name, "file not found"))

    # 3) 输出
    dfs: Dict[str, pd.DataFrame] = {}
    for group in ["Mixed", "CAV", "HDV"]:
        if features[group]:
            df = pd.DataFrame(list(features[group].values()))
            cols = ["penetration"] + sorted([c for c in df.columns if c != "penetration"])
            dfs[group] = df[cols].sort_values("penetration")
        else:
            dfs[group] = pd.DataFrame(columns=["penetration"])

    out_dir = Path(output_dir)
    (out_dir / "mobility_features_mixed.csv").write_text("") if False else None  # touch hint

    dfs["Mixed"].to_csv(out_dir / "mobility_features_mixed.csv", index=False)
    dfs["CAV"].to_csv(out_dir / "mobility_features_cav.csv", index=False)
    dfs["HDV"].to_csv(out_dir / "mobility_features_hdv.csv", index=False)

    xlsx_out = out_dir / "mobility_features_by_penetration.xlsx"
    with pd.ExcelWriter(xlsx_out, engine="xlsxwriter") as writer:
        dfs["Mixed"].to_excel(writer, sheet_name="Mixed", index=False)
        dfs["CAV"].to_excel(writer, sheet_name="CAV", index=False)
        dfs["HDV"].to_excel(writer, sheet_name="HDV", index=False)

    if skipped:
        with open(out_dir / "skipped_files.txt", "w", encoding="utf-8") as fh:
            fh.write("Notes about missing/unread inputs or sheets:\n")
            for name, reason in skipped:
                fh.write(f"- {name}: {reason}\n")

    return str(xlsx_out)