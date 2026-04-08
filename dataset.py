from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

import numpy as np
import pandas as pd

from config import DEFAULT_CONFIG, ProjectConfig
from features import extract_feature_vector


@dataclass
class DatasetBundle:
    features: np.ndarray
    labels: np.ndarray
    files: list[Path]


def _resolve_class_files(config: ProjectConfig) -> tuple[list[Path], list[Path]]:
    for root in config.candidate_data_roots:
        normal_dir = root / config.normal_folder
        error_dir = root / config.error_folder
        if normal_dir.is_dir() and error_dir.is_dir():
            normal_files = sorted(normal_dir.glob("*.csv"))
            error_files = sorted(error_dir.glob("*.csv"))
            if normal_files and error_files:
                return normal_files, error_files

    legacy_root = config.base_dir / "data"
    if legacy_root.is_dir():
        normal_files = sorted(legacy_root.glob("*normal*.csv"))
        error_files = sorted(legacy_root.glob("*error*.csv"))
        if normal_files and error_files:
            return normal_files, error_files

    raise FileNotFoundError(
        "Could not find dataset folders. Expected data/normal + data/error "
        "or data/raw/normal + data/raw/error."
    )


def _load_split(
    files: list[Path],
    label: int,
    config: ProjectConfig,
) -> tuple[list[np.ndarray], list[int], list[Path]]:
    features: list[np.ndarray] = []
    labels: list[int] = []
    used_files: list[Path] = []

    for csv_path in files:
        frame = pd.read_csv(csv_path)
        feature_vector = extract_feature_vector(frame, config)
        features.append(feature_vector)
        labels.append(label)
        used_files.append(csv_path)

    return features, labels, used_files


def load_dataset(config: ProjectConfig = DEFAULT_CONFIG) -> DatasetBundle:
    normal_files, error_files = _resolve_class_files(config)

    normal_features, normal_labels, normal_used = _load_split(normal_files, 0, config)
    error_features, error_labels, error_used = _load_split(error_files, 1, config)

    features = np.asarray(normal_features + error_features, dtype=np.float64)
    labels = np.asarray(normal_labels + error_labels, dtype=np.int64)
    files = normal_used + error_used

    if not len(features):
        raise ValueError("Dataset is empty")

    return DatasetBundle(features=features, labels=labels, files=files)
