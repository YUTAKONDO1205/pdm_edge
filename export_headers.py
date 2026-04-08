from __future__ import annotations

from runtime_bootstrap import ensure_runtime

ensure_runtime(("numpy", "micromlgen"))

import pickle

import numpy as np
from micromlgen import port

from config import DEFAULT_CONFIG, ProjectConfig


def render_norm_header(mu: np.ndarray, sig: np.ndarray) -> str:
    mu_values = ", ".join(f"{float(value):.6f}f" for value in mu)
    sig_values = ", ".join(f"{float(value):.6f}f" for value in sig)

    return (
        "#pragma once\n\n"
        f"constexpr int FEATURE_DIM = {len(mu)};\n\n"
        f"const float MU[FEATURE_DIM] = {{{mu_values}}};\n"
        f"const float SIG[FEATURE_DIM] = {{{sig_values}}};\n"
    )


def export_headers(
    model: object,
    mu: np.ndarray,
    sig: np.ndarray,
    config: ProjectConfig = DEFAULT_CONFIG,
) -> None:
    config.ensure_output_dirs()
    model_header = port(model)
    norm_header = render_norm_header(mu, sig)

    config.model_header_path.write_text(model_header, encoding="utf-8")
    config.norm_header_path.write_text(norm_header, encoding="utf-8")


def load_artifacts(
    config: ProjectConfig = DEFAULT_CONFIG,
) -> tuple[object, np.ndarray, np.ndarray]:
    if not config.model_pickle_path.exists() or not config.scaler_pickle_path.exists():
        raise FileNotFoundError("Run python train.py before exporting headers.")

    with config.model_pickle_path.open("rb") as file:
        model = pickle.load(file)

    with config.scaler_pickle_path.open("rb") as file:
        scaler = pickle.load(file)

    mu = np.asarray(scaler["mu"], dtype=np.float64)
    sig = np.asarray(scaler["sig"], dtype=np.float64)
    return model, mu, sig


def main() -> None:
    model, mu, sig = load_artifacts()
    export_headers(model, mu, sig)

    print(f"Wrote {DEFAULT_CONFIG.model_header_path}")
    print(f"Wrote {DEFAULT_CONFIG.norm_header_path}")


if __name__ == "__main__":
    main()
