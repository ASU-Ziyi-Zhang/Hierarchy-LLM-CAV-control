from __future__ import annotations

import argparse
from pathlib import Path

from behavior_multi_compare import multi_penetration_compare_behavior
from fuel_multi_compare import multi_penetration_compare_fuel
from mobility_multi_compare import multi_penetration_compare_mobility
from safety_multi_compare import multi_penetration_compare_v2
from urban_multi_compare import multi_penetration_compare_urban


PROJECT_ROOT = Path(__file__).resolve().parent.parent


def _resolve_path(path_str: str | None) -> Path | None:
    if path_str is None:
        return None
    p = Path(path_str)
    if p.is_absolute():
        return p
    return PROJECT_ROOT / p


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Aggregate dashboard-export workbooks across multiple penetration rates."
    )
    parser.add_argument("--input_dir", type=str, default=None, help="Directory containing '*_datasets.xlsx'.")
    parser.add_argument("--output_dir", type=str, default=None, help="Directory for comparison outputs.")
    parser.add_argument("--scenario_folder", type=str, default="sumo_scenarios")
    parser.add_argument("--scenario", type=str, default=None, help="Used to infer default input/output directories.")
    parser.add_argument(
        "--categories",
        type=str,
        default="safety,mobility,behavior,fuel,urban",
        help="Comma-separated categories to run. Supported: safety,mobility,behavior,fuel,urban",
    )
    parser.add_argument("--ttc_threshold", type=float, default=1.5)
    parser.add_argument("--pet_threshold", type=float, default=1.0)
    parser.add_argument("--headway_threshold", type=float, default=0.8)
    parser.add_argument("--lc_threshold", type=int, default=3)
    parser.add_argument("--average_seeds", action="store_true", help="Load all matching workbook runs and average metrics across seeds for each penetration.")
    parser.add_argument("--no_csv", action="store_true", help="Do not also export per-sheet CSV files.")
    return parser


def resolve_dirs(args) -> tuple[Path, Path]:
    if args.input_dir:
        input_dir = _resolve_path(args.input_dir)
    elif args.scenario:
        input_dir = _resolve_path(args.scenario_folder) / args.scenario / "excel_file"
    else:
        raise SystemExit("Provide either --input_dir or --scenario.")

    if args.output_dir:
        output_dir = _resolve_path(args.output_dir)
    elif args.scenario:
        output_dir = PROJECT_ROOT / "comparison" / "output" / args.scenario
    else:
        output_dir = input_dir / "comparison_output"

    return input_dir, output_dir


def resolve_scenario_output_dir(args, input_dir: Path) -> Path:
    if args.scenario:
        return _resolve_path(args.scenario_folder) / args.scenario / "output"
    if input_dir.name.lower() == "excel_file":
        return input_dir.parent / "output"
    return input_dir.parent / "output"


def main():
    parser = build_parser()
    args = parser.parse_args()

    input_dir, output_dir = resolve_dirs(args)
    output_dir.mkdir(parents=True, exist_ok=True)

    categories = [item.strip().lower() for item in args.categories.split(",") if item.strip()]
    valid = {"safety", "mobility", "behavior", "fuel", "urban"}
    bad = [item for item in categories if item not in valid]
    if bad:
        raise SystemExit(f"Unsupported categories: {bad}. Supported: {sorted(valid)}")

    also_write_csv = not args.no_csv

    print(f"Input directory:  {input_dir}")
    print(f"Output directory: {output_dir}")
    scenario_output_dir = resolve_scenario_output_dir(args, input_dir)

    print(f"Categories:       {', '.join(categories)}")
    print(f"Scenario output:  {scenario_output_dir}")

    if "safety" in categories:
        out = multi_penetration_compare_v2(
            input_dir=str(input_dir),
            output_dir=str(output_dir / "safety"),
            threshold_ttc=args.ttc_threshold,
            pet_threshold=args.pet_threshold,
            headway_threshold=args.headway_threshold,
            average_seeds=args.average_seeds,
            also_write_csv=also_write_csv,
        )
        print(f"[safety]   {out}")

    if "mobility" in categories:
        out = multi_penetration_compare_mobility(
            input_dir=str(input_dir),
            output_dir=str(output_dir / "mobility"),
            average_seeds=args.average_seeds,
            also_write_csv=also_write_csv,
        )
        print(f"[mobility] {out}")

    if "behavior" in categories:
        out = multi_penetration_compare_behavior(
            input_dir=str(input_dir),
            output_dir=str(output_dir / "behavior"),
            lc_threshold=args.lc_threshold,
            average_seeds=args.average_seeds,
            also_write_csv=also_write_csv,
        )
        print(f"[behavior] {out}")

    if "fuel" in categories:
        out = multi_penetration_compare_fuel(
            input_dir=str(input_dir),
            output_dir=str(output_dir / "fuel"),
            average_seeds=args.average_seeds,
            also_write_csv=also_write_csv,
        )
        print(f"[fuel]     {out}")

    if "urban" in categories:
        out = multi_penetration_compare_urban(
            input_dir=str(input_dir),
            output_dir=str(output_dir / "urban"),
            scenario_output_dir=str(scenario_output_dir),
            average_seeds=args.average_seeds,
            also_write_csv=also_write_csv,
        )
        print(f"[urban]    {out}")


if __name__ == "__main__":
    main()
