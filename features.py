from __future__ import annotations

from functools import lru_cache

import numpy as np
import pandas as pd
from scipy.fft import rfft
from scipy.signal import windows

from config import DEFAULT_CONFIG, ProjectConfig


def _prepare_signal(signal: np.ndarray, target_length: int) -> np.ndarray:
    if signal.size < target_length:
        return np.pad(signal, (0, target_length - signal.size))

    return signal[:target_length]


@lru_cache(maxsize=None)
def _hann_window(target_length: int) -> np.ndarray:
    return windows.hann(target_length)


def extract_band_features(
    signal: np.ndarray | list[float],
    config: ProjectConfig = DEFAULT_CONFIG,
) -> np.ndarray:
    prepared = _prepare_signal(np.asarray(signal, dtype=np.float64), config.fft_size)
    windowed = prepared * _hann_window(config.fft_size)
    spectrum = np.abs(rfft(windowed))

    if spectrum.size < config.spectrum_bins:
        spectrum = np.pad(spectrum, (0, config.spectrum_bins - spectrum.size))
    else:
        spectrum = spectrum[: config.spectrum_bins]

    return spectrum.reshape(config.band_count, config.band_width).mean(axis=1, dtype=np.float64)


def extract_feature_vector(
    frame: pd.DataFrame,
    config: ProjectConfig = DEFAULT_CONFIG,
) -> np.ndarray:
    missing = [channel for channel in config.channels if channel not in frame.columns]
    if missing:
        raise ValueError(f"missing channel columns: {', '.join(missing)}")

    channel_matrix = frame.loc[:, list(config.channels)].to_numpy(dtype=np.float64, copy=False)
    channel_features = [
        extract_band_features(channel_matrix[:, index], config)
        for index in range(channel_matrix.shape[1])
    ]
    feature_vector = np.concatenate(channel_features)

    if feature_vector.size != config.feature_dim:
        raise ValueError(
            f"unexpected feature size {feature_vector.size}, expected {config.feature_dim}"
        )

    return feature_vector


def normalize_features(
    features: np.ndarray,
    mu: np.ndarray | None = None,
    sig: np.ndarray | None = None,
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    matrix = np.asarray(features, dtype=np.float64)
    current_mu = matrix.mean(axis=0) if mu is None else np.asarray(mu, dtype=np.float64)
    current_sig = (
        np.clip(matrix.std(axis=0), 1e-6, None)
        if sig is None
        else np.asarray(sig, dtype=np.float64)
    )
    normalized = (matrix - current_mu) / current_sig
    return normalized, current_mu, current_sig
