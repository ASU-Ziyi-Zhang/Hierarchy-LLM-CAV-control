
from pathlib import Path
import re
import numpy as np
import pandas as pd

import unicodedata
import re

def _norm_colname(name: str) -> str:
    """
    标准化列名：去空格、全角转半角、转小写、去常见符号。
    把 ' pen 10 ％ '、'Pen_10%'、'P10' 等都归一化到类似 'pen10%'.
    """
    s = str(name)
    s = unicodedata.normalize("NFKC", s)      # 全角->半角（％ -> % 等）
    s = s.strip().lower()
    s = s.replace(" ", "").replace("\u00a0", "")  # 普通/不间断空格
    s = s.replace("_", "")
    # 常见拼写兼容：p10 / pen10 / penetration10 都视作 pen10
    s = s.replace("penetration", "pen")
    # 保留数字和 %，其余去掉
    # （先把 'pen' 保留，其它非字母数字% 删掉）
    keep = []
    for ch in s:
        if ch.isalnum() or ch in ['%', ]:
            keep.append(ch)
    s = "".join(keep)
    # 统一成 pen 开头：比如 'p10%' -> 'pen10%'
    s = re.sub(r'^p(?=\d)', 'pen', s)
    return s

def _find_bin_mid_col(df) -> str | None:
    # 容错找到 bin_mid 列
    cand = None
    for c in df.columns:
        n = _norm_colname(c)
        if n in ("binmid", "bin_mid", "binmids"):  # 常见变体
            return c
        if n.startswith("bin") and "mid" in n:
            cand = c
    return cand

def _read_excel(path: Path, sheet_name: str):
    """Robust reader that tries openpyxl and falls back to xlrd/auto. Returns (df, err)."""
    errs = []
    try:
        import openpyxl  # noqa
        return pd.read_excel(path, sheet_name=sheet_name, engine="openpyxl"), None
    except Exception as e:
        errs.append(f"openpyxl: {e}")
    try:
        import xlrd  # noqa
        return pd.read_excel(path, sheet_name=sheet_name, engine="xlrd"), None
    except Exception as e:
        errs.append(f"xlrd: {e}")
    try:
        return pd.read_excel(path, sheet_name=sheet_name), None
    except Exception as e:
        errs.append(f"auto: {e}")
    return None, " | ".join(errs)

def _read_csv(path: Path):
    try:
        return pd.read_csv(path), None
    except Exception as e:
        return None, str(e)

def _bin_widths(bin_mid: np.ndarray) -> np.ndarray:
    """Estimate bin widths from bin_mid (supports non-uniform bins)."""
    bin_mid = np.asarray(bin_mid, dtype=float)
    if len(bin_mid) == 1:
        return np.array([1.0])
    diffs = np.diff(bin_mid)
    # Edge widths: assume left/right equal to nearest diff
    left = diffs[0]
    right = diffs[-1]
    widths = np.empty_like(bin_mid)
    widths[1:-1] = (diffs[:-1] + diffs[1:]) / 2.0
    widths[0] = left
    widths[-1] = right
    # Guard against non-positive widths
    widths = np.where(widths <= 0, np.nan, widths)
    return widths

def _pdf_descriptors(
    bin_mid: np.ndarray,
    density: np.ndarray,
    risk_threshold: float | None = None,
    low_is_risky: bool = True
):
    """
    Compute mean, std, and tail quantiles (P05/P10 or P90/P95) and optional risk share for a continuous PDF.
    - low_is_risky=True  -> 返回 P05, P10（小值代表危险）
    - low_is_risky=False -> 返回 P90, P95（大值代表危险）
    """
    x = np.asarray(bin_mid, dtype=float)
    f = np.asarray(density, dtype=float)
    w = _bin_widths(x)

    # 清理无效值
    mask = ~(np.isnan(x) | np.isnan(f) | np.isnan(w))
    x, f, w = x[mask], f[mask], w[mask]
    if len(x) == 0:
        return np.nan, np.nan, np.nan, np.nan, np.nan if risk_threshold is not None else None

    area = np.sum(f * w)
    if not np.isfinite(area) or area <= 0:
        return np.nan, np.nan, np.nan, np.nan, np.nan if risk_threshold is not None else None

    # 归一化
    f = f / area
    mean = np.sum(x * f * w)
    var = max(0.0, np.sum(((x - mean) ** 2) * f * w))
    std = np.sqrt(var)

    # 构建CDF
    order = np.argsort(x)
    xs, fs, ws = x[order], f[order], w[order]
    cdf = np.cumsum(fs * ws)
    cdf = np.clip(cdf, 0, 1)

    def _quantile(p: float) -> float:
        if len(xs) == 0:
            return np.nan
        idx = np.searchsorted(cdf, p, side="left")
        if idx == 0:
            return xs[0]
        if idx >= len(xs):
            return xs[-1]
        c0, c1 = cdf[idx-1], cdf[idx]
        x0, x1 = xs[idx-1], xs[idx]
        if c1 == c0:
            return x0
        t = (p - c0) / (c1 - c0)
        return x0 + t * (x1 - x0)

    if low_is_risky:
        p05 = _quantile(0.05)
        p10 = _quantile(0.10)
        tail1, tail2 = p05, p10
    else:
        p90 = _quantile(0.90)
        p95 = _quantile(0.95)
        tail1, tail2 = p90, p95

    risk_share = None
    if risk_threshold is not None:
        risk_share = float(np.sum(fs[xs < risk_threshold] * ws[xs < risk_threshold]))

    return mean, std, tail1, tail2, risk_share

def build_safety_features(
    input_dir: str,
    output_dir: str,
    density_xlsx_name: str = "multi_density_tables.xlsx",
    drac_csv_name: str = "summary_drac_stats.csv",
    ttc_share_csv_name: str = "summary_ttc_risk_share.csv",
    pet_threshold: float = 1.0,
    headway_threshold: float = 0.8
):
    """
    Build penetration-level feature tables for SAFETY.
    Produces three tables (Mixed/CAV/HDV) with descriptors aggregated across metrics.
    """
    in_dir = Path(input_dir)
    out_dir = Path(output_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    skipped = []

    # 1) Read density workbook (multiple sheets with *_HDV/_CAV/_Combined)
    xlsx_path = in_dir / density_xlsx_name
    if not xlsx_path.exists():
        raise FileNotFoundError(f"Not found: {xlsx_path}")

    try:
        import openpyxl  # noqa
        xl = pd.ExcelFile(xlsx_path, engine="openpyxl")
    except Exception:
        xl = pd.ExcelFile(xlsx_path)

    # Structures to accumulate features
    features = {"Mixed": {}, "CAV": {}, "HDV": {}}

    def row_for(group: str, pen: int):
        if pen not in features[group]:
            features[group][pen] = {"penetration": pen}
        return features[group][pen]

    for sh in xl.sheet_names:
        m = re.match(r"(.+?)_(HDV|CAV|Combined)$", sh.strip())
        if not m:
            skipped.append((sh, "sheet name not matching <metric>_(HDV|CAV|Combined)"))
            continue
        metric, veh = m.group(1), m.group(2)
        group = "Mixed" if veh == "Combined" else veh

        df, err = _read_excel(xlsx_path, sh)
        if err:
            skipped.append((sh, f"read error: {err}"))
            continue
        # 先找 bin_mid（容错大小写/空格/下划线/全角）
        bin_col = _find_bin_mid_col(df)
        if bin_col is None:
            skipped.append((sh, f"missing 'bin_mid' (got columns: {list(df.columns)})"))
            continue
        x = df[bin_col].to_numpy()

        # 规范化并建立 "渗透率 → 原始列名" 的映射
        pen_col_map = {}  # { penetration_int : original_col_name }
        for c in df.columns:
            n = _norm_colname(c)
            # 匹配 pen10 或 pen10%（% 可有可无）
            m = re.match(r'^pen(\d+)(%?)$', n)
            if m:
                pen = int(m.group(1))
                pen_col_map[pen] = c

        if not pen_col_map:
            skipped.append((sh, f"no 'penXX' columns found; columns={list(df.columns)}"))
            continue

        # choose risk threshold if metric is PET or Headway
        risk_T = None
        if metric.lower() == "pet":
            risk_T = pet_threshold
        elif metric.lower() in ["headway", "timeheadway", "time_headway"]:
            risk_T = headway_threshold

        # 逐个渗透率列计算指标（按渗透率排序，保证输出整齐）
        for pen in sorted(pen_col_map.keys()):
            colname = pen_col_map[pen]
            dens = df[colname].to_numpy(dtype=float)

            # 小值危险的指标（用 p05/p10）
            low_is_risky = metric.lower() in ["ttc", "pet", "headway", "timeheadway", "time_headway"]

            mean, std, q1, q2, risk_share = _pdf_descriptors(
                x, dens, risk_T, low_is_risky=low_is_risky
            )

            row = row_for(group, pen)
            base = metric
            row[f"{base}_mean"] = mean
            row[f"{base}_std"] = std

            if low_is_risky:
                row[f"{base}_p05"] = q1
                row[f"{base}_p10"] = q2
            else:
                row[f"{base}_p90"] = q1
                row[f"{base}_p95"] = q2

            if risk_T is not None:
                if metric.lower() == "pet":
                    row[f"{base}_risk_share_lt_{pet_threshold:.1f}s"] = risk_share
                elif metric.lower() in ["headway", "timeheadway", "time_headway"]:
                    row[f"{base}_risk_share_lt_{headway_threshold:.1f}s"] = risk_share

    # 2) Merge TTC risk share (precomputed)
    ttc_csv = in_dir / ttc_share_csv_name
    if ttc_csv.exists():
        df_ttc, err = _read_csv(ttc_csv)
        if err:
            skipped.append(("summary_ttc_risk_share.csv", f"csv read error: {err}"))
        else:
            for _, r in df_ttc.iterrows():
                pen = int(r["penetration"])
                for group, col in [("HDV","share_HDV"), ("CAV","share_CAV"), ("Mixed","share_Mixed")]:
                    if col in df_ttc.columns:
                        row = row_for(group, pen)
                        row["TTC_risk_share_lt_1.5s"] = float(r[col])
    else:
        skipped.append(("summary_ttc_risk_share.csv", "file not found"))

    # 3) Merge DRAC summary (HDV/CAV only; Mixed if provided)
    drac_csv = in_dir / drac_csv_name
    if drac_csv.exists():
        df_drac, err = _read_csv(drac_csv)
        if err:
            skipped.append(("summary_drac_stats.csv", f"csv read error: {err}"))
        else:
            for _, r in df_drac.iterrows():
                pen = int(r["penetration"])
                rh = row_for("HDV", pen)
                rc = row_for("CAV", pen)
                rm = row_for("Mixed", pen)

                # 统一把这些统计并回去（如果列存在）
                for k in ["mean", "std", "min", "max", "p90", "p95"]:
                    colh = f"HDV_{k}"
                    colc = f"CAV_{k}"
                    colm = f"Mixed_{k}"
                    if colh in df_drac.columns and pd.notna(r[colh]):
                        rh[f"DRAC_{k}"] = float(r[colh])
                    if colc in df_drac.columns and pd.notna(r[colc]):
                        rc[f"DRAC_{k}"] = float(r[colc])
                    # 首先按 Mixed_* 列直接填充（如果存在）
                    if colm in df_drac.columns and pd.notna(r[colm]):
                        rm[f"DRAC_{k}"] = float(r[colm])
                    else:
                        # 如果没有 Mixed_* 列，则退回到用 CAV 与 HDV 的值计算 Mixed（简单平均，忽略缺失）
                        vals = []
                        if colh in df_drac.columns and pd.notna(r[colh]):
                            vals.append(float(r[colh]))
                        if colc in df_drac.columns and pd.notna(r[colc]):
                            vals.append(float(r[colc]))
                        if vals:
                            # 使用 numpy 的 nanmean 以防万一（但 vals 中不应包含 NaN）
                            rm[f"DRAC_{k}"] = float(np.nanmean(vals))
    else:
        skipped.append(("summary_drac_stats.csv", "file not found"))

    # 4) Build DataFrames and write outputs
    out_base = Path(output_dir)
    out_base.mkdir(parents=True, exist_ok=True)

    dfs = {}
    for group in ["Mixed","CAV","HDV"]:
        if features[group]:
            df = pd.DataFrame(list(features[group].values()))
            cols = ["penetration"] + sorted([c for c in df.columns if c != "penetration"])
            df = df[cols].sort_values("penetration")
        else:
            df = pd.DataFrame(columns=["penetration"])
        dfs[group] = df

    dfs["Mixed"].to_csv(out_base / "safety_features_mixed.csv", index=False)
    dfs["CAV"].to_csv(out_base / "safety_features_cav.csv", index=False)
    dfs["HDV"].to_csv(out_base / "safety_features_hdv.csv", index=False)

    xlsx_out = out_base / "safety_features_by_penetration.xlsx"
    with pd.ExcelWriter(xlsx_out, engine="xlsxwriter") as writer:
        dfs["Mixed"].to_excel(writer, sheet_name="Mixed", index=False)
        dfs["CAV"].to_excel(writer, sheet_name="CAV", index=False)
        dfs["HDV"].to_excel(writer, sheet_name="HDV", index=False)

    if skipped:
        with open(out_base / "skipped_files.txt", "w", encoding="utf-8") as fh:
            fh.write("Notes about missing/unread inputs or sheets:\n")
            for name, reason in skipped:
                fh.write(f"- {name}: {reason}\n")

    return str(xlsx_out)
