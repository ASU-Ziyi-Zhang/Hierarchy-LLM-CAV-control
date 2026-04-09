#!/usr/bin/env python3
"""Small smoke test for the AIML hierarchy backend."""

from __future__ import annotations

import argparse
import json

from src.hierarchical_control.llm_client import AIMLClient, AIMLClientError


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Smoke test the AIML API backend used by the hierarchy layer.")
    parser.add_argument("--query", default="hello", help="Prompt sent to the AIML API. Default: hello")
    parser.add_argument("--model", default=None, help="Optional model name passed through to the AIML API.")
    parser.add_argument("--timeout", type=float, default=30.0, help="Request timeout in seconds. Default: 30.0")
    parser.add_argument("--show-payload", action="store_true", help="Print the outgoing JSON payload.")
    return parser


def main() -> int:
    args = build_parser().parse_args()

    try:
        client = AIMLClient(default_model=args.model, timeout_seconds=args.timeout)
        response = client.query(args.query, model=args.model, timeout_seconds=args.timeout)
    except AIMLClientError as exc:
        print(f"[AIML-ERROR] {exc}")
        return 1

    print(f"[AIML-OK] status={response.status_code}")
    if args.show_payload:
        print("[AIML-PAYLOAD]")
        print(json.dumps(response.payload, indent=2, ensure_ascii=False))

    print("[AIML-RESPONSE]")
    if isinstance(response.data, dict):
        print(json.dumps(response.data, indent=2, ensure_ascii=False))
    else:
        print(response.text)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
