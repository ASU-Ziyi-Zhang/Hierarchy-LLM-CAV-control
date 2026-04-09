#!/usr/bin/env python3
"""Convenience launcher for hierarchy-enabled runs."""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path


def main() -> int:
    root = Path(__file__).resolve().parent
    main_py = root / "main.py"
    forwarded_args = sys.argv[1:]
    if "--enable_hierarchy" not in forwarded_args:
        forwarded_args = ["--enable_hierarchy", *forwarded_args]
    cmd = [sys.executable, str(main_py), *forwarded_args]
    return subprocess.call(cmd, cwd=root)


if __name__ == "__main__":
    raise SystemExit(main())
