from __future__ import annotations

import os
from dataclasses import dataclass
from typing import Any

try:
    import requests
except ImportError:
    requests = None

try:
    import winreg
except ImportError:
    winreg = None


DEFAULT_AIML_URL = "https://api-main.aiml.asu.edu/query"
DEFAULT_TIMEOUT_SECONDS = 30.0


def _load_aiml_token(token: str | None = None) -> str | None:
    if token:
        return token

    env_token = os.getenv("AIML_API_TOKEN")
    if env_token:
        return env_token

    if os.name == "nt" and winreg is not None:
        try:
            with winreg.OpenKey(winreg.HKEY_CURRENT_USER, r"Environment") as key:
                value, _ = winreg.QueryValueEx(key, "AIML_API_TOKEN")
                if value:
                    return value
        except OSError:
            pass

    return None


class AIMLClientError(RuntimeError):
    """Raised when the AIML client cannot complete a request."""


@dataclass
class AIMLClientResponse:
    """Normalized response wrapper for the AIML API."""

    status_code: int
    ok: bool
    text: str
    data: Any
    payload: dict[str, Any]


class AIMLClient:
    """Thin reusable client for the ASU AIML query endpoint."""

    def __init__(
        self,
        token: str | None = None,
        base_url: str = DEFAULT_AIML_URL,
        default_model: str | None = None,
        timeout_seconds: float = DEFAULT_TIMEOUT_SECONDS,
        session: Any | None = None,
    ):
        self.base_url = base_url
        self.default_model = default_model
        self.timeout_seconds = timeout_seconds
        self.session = session or (requests.Session() if requests is not None else None)
        self.token = _load_aiml_token(token)

        if not self.token:
            raise AIMLClientError(
                "AIML API token is missing. Set the AIML_API_TOKEN environment variable or pass token explicitly."
            )

        if self.session is None:
            raise AIMLClientError(
                "The optional 'requests' dependency is missing, so live AIML queries are unavailable."
            )

    @property
    def headers(self) -> dict[str, str]:
        return {
            "Authorization": f"Bearer {self.token}",
            "Content-Type": "application/json",
        }

    def build_payload(
        self,
        query: str,
        model: str | None = None,
        extra_payload: dict[str, Any] | None = None,
    ) -> dict[str, Any]:
        payload: dict[str, Any] = {"query": query}
        chosen_model = model or self.default_model
        if chosen_model:
            payload["model"] = chosen_model
        if extra_payload:
            payload.update(extra_payload)
        return payload

    def query(
        self,
        query: str,
        model: str | None = None,
        extra_payload: dict[str, Any] | None = None,
        timeout_seconds: float | None = None,
    ) -> AIMLClientResponse:
        if self.session is None:
            raise AIMLClientError("The optional 'requests' dependency is missing, so live AIML queries are unavailable.")

        payload = self.build_payload(query=query, model=model, extra_payload=extra_payload)
        timeout = timeout_seconds or self.timeout_seconds

        try:
            response = self.session.post(
                self.base_url,
                json=payload,
                headers=self.headers,
                timeout=timeout,
            )
        except Exception as exc:
            raise AIMLClientError(f"AIML request failed: {exc}") from exc

        text = response.text
        try:
            data = response.json()
        except ValueError:
            data = text

        if not response.ok:
            raise AIMLClientError(
                f"AIML request returned HTTP {response.status_code}: {text}"
            )

        return AIMLClientResponse(
            status_code=response.status_code,
            ok=response.ok,
            text=text,
            data=data,
            payload=payload,
        )

    def query_text(
        self,
        query: str,
        model: str | None = None,
        extra_payload: dict[str, Any] | None = None,
        timeout_seconds: float | None = None,
    ) -> str:
        result = self.query(
            query=query,
            model=model,
            extra_payload=extra_payload,
            timeout_seconds=timeout_seconds,
        )
        if isinstance(result.data, dict):
            for key in ("response", "text", "output", "answer", "result"):
                value = result.data.get(key)
                if isinstance(value, str):
                    return value
        return result.text
