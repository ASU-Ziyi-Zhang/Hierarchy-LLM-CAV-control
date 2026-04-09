# fuel_features_merge.py
from __future__ import annotations
from pathlib import Path
from typing import Dict, Optional
import pandas as pd
import numpy as np

def _read_csv(path: Path):
    try:
        df = pd.read_csv(path)
        return df, None
    except Exception as e:
        return None, f"{type(e).__name__}: {e}"

def build_fuel_features(
    input_dir: str,
    output_dir: str,
    fuel_csv_name: str = "summary_fuel.csv",
    add_unit_conversions: bool = True,   # 是否增加 L/100km 等换算列
) -> str:
    """
    读取现成的 summary_fuel.csv，整理成按渗透率聚合的三张表（Mixed / CAV / HDV）。
    输入列（你给的口径）：
      penetration,
      HDV_TotalFuel_g, HDV_AvgFuelPerVeh_g, HDV_FuelEff_mile_per_gal, HDV_Vehicles,
      CAV_TotalFuel_g, CAV_AvgFuelPerVeh_g, CAV_FuelEff_mile_per_gal, CAV_Vehicles,
      Mixed_TotalFuel_g, Mixed_AvgFuelPerVeh_g, Mixed_FuelEff_mile_per_gal,
      CAV_Fuel_Savings_pct
    输出：
      - fuel_features_by_penetration.xlsx（Sheets: Mixed / CAV / HDV）
      - fuel_features_mixed.csv / _cav.csv / _hdv.csv
      - skipped_files.txt（若读不到文件）
    """
    in_dir = Path(input_dir)
    out_dir = Path(output_dir)
    out_dir.mkdir(parents=True, exist_ok=True)

    skipped = []

    csv_path = in_dir / fuel_csv_name
    if not csv_path.exists():
        raise FileNotFoundError(f"Not found: {csv_path}")

    df, err = _read_csv(csv_path)
    if err:
        skipped.append((fuel_csv_name, f"csv read error: {err}"))
        # 仍然写个空壳输出，方便流程不中断
        empty = pd.DataFrame(columns=["penetration"])
        for name in ["Mixed","CAV","HDV"]:
            empty.to_csv(out_dir / f"fuel_features_{name.lower()}.csv", index=False)
        with pd.ExcelWriter(out_dir / "fuel_features_by_penetration.xlsx", engine="xlsxwriter") as w:
            empty.to_excel(w, sheet_name="Mixed", index=False)
            empty.to_excel(w, sheet_name="CAV", index=False)
            empty.to_excel(w, sheet_name="HDV", index=False)
        with open(out_dir / "skipped_files.txt", "w", encoding="utf-8") as fh:
            for name, reason in skipped:
                fh.write(f"- {name}: {reason}\n")
        return str(out_dir / "fuel_features_by_penetration.xlsx")

    # 只挑我们关心/已知列（容错：不存在就跳过）
    cols_keep = [
        "penetration",
        "HDV_TotalFuel_g", "HDV_AvgFuelPerVeh_g", "HDV_FuelEff_mile_per_gal", "HDV_Vehicles",
        "CAV_TotalFuel_g", "CAV_AvgFuelPerVeh_g", "CAV_FuelEff_mile_per_gal", "CAV_Vehicles",
        "Mixed_TotalFuel_g", "Mixed_AvgFuelPerVeh_g", "Mixed_FuelEff_mile_per_gal",
        "CAV_Fuel_Savings_pct",
    ]
    cols = [c for c in cols_keep if c in df.columns]
    df = df[cols].copy()

    # （可选）增加单位换算列：gal/mile → L/100km
    # 1 mile = 1.609344 km; 1 gal(US) = 3.785411784 L
    # FE(gal/mi) → L/100km = FE * 3.785411784 / 1.609344 * 100
    if add_unit_conversions:
        k = 3.785411784 / 1.609344 * 100.0
        for prefix in ["HDV", "CAV", "Mixed"]:
            col = f"{prefix}_FuelEff_gal_per_mile"
            if col in df.columns:
                df[f"{prefix}_FuelEff_L_per_100km"] = 1/(df[col].astype(float) * k)

    # 拆成三张“每组一行”的宽表（与前面模块一致：每行一个 penetration）
    def _make_group_table(group: str) -> pd.DataFrame:
        prefix = f"{group}_"
        use_cols = [c for c in df.columns if c == "penetration" or c.startswith(prefix) or c == "CAV_Fuel_Savings_pct"]
        t = df[use_cols].copy()
        # 去掉前缀形成更简洁的列名
        rename_map = {c: c[len(prefix):] for c in use_cols if c.startswith(prefix)}
        t = t.rename(columns=rename_map)
        # 仅 Mixed 表保留 CAV_Fuel_Savings_pct（这是一个总体指标）
        if group != "Mixed" and "CAV_Fuel_Savings_pct" in t.columns:
            t = t.drop(columns=["CAV_Fuel_Savings_pct"])
        return t.sort_values("penetration")

    dfs = {
        "Mixed": _make_group_table("Mixed"),
        "CAV":   _make_group_table("CAV"),
        "HDV":   _make_group_table("HDV"),
    }

    # 输出 CSV
    dfs["Mixed"].to_csv(out_dir / "fuel_features_mixed.csv", index=False)
    dfs["CAV"].to_csv(out_dir / "fuel_features_cav.csv", index=False)
    dfs["HDV"].to_csv(out_dir / "fuel_features_hdv.csv", index=False)

    # 输出 Excel（3 个 sheet）
    xlsx_out = out_dir / "fuel_features_by_penetration.xlsx"
    with pd.ExcelWriter(xlsx_out, engine="xlsxwriter") as w:
        dfs["Mixed"].to_excel(w, sheet_name="Mixed", index=False)
        dfs["CAV"].to_excel(w, sheet_name="CAV", index=False)
        dfs["HDV"].to_excel(w, sheet_name="HDV", index=False)

    # skipped 记录
    if skipped:
        with open(out_dir / "skipped_files.txt", "w", encoding="utf-8") as fh:
            fh.write("Notes about missing/unread inputs or sheets:\n")
            for name, reason in skipped:
                fh.write(f"- {name}: {reason}\n")

    return str(xlsx_out)