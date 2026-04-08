from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path


@dataclass(frozen=True)
class ProjectConfig:
    base_dir: Path = field(default_factory=lambda: Path(__file__).resolve().parent)
    data_root_names: tuple[str, ...] = ("data/raw", "data")
    normal_folder: str = "normal"
    error_folder: str = "error"
    channels: tuple[str, ...] = ("accX", "accY", "accZ", "mic")
    fft_size: int = 64
    spectrum_bins: int = 32
    band_count: int = 8
    test_size: float = 0.25
    random_state: int = 42
    n_estimators: int = 100

    def __post_init__(self) -> None:
        if self.spectrum_bins % self.band_count != 0:
            raise ValueError("spectrum_bins must be divisible by band_count")

    @property
    def feature_dim(self) -> int:
        return len(self.channels) * self.band_count

    @property
    def band_width(self) -> int:
        return self.spectrum_bins // self.band_count

    @property
    def candidate_data_roots(self) -> tuple[Path, ...]:
        return tuple(self.base_dir / name for name in self.data_root_names)

    @property
    def export_dir(self) -> Path:
        return self.base_dir / "model_export"

    @property
    def figures_dir(self) -> Path:
        return self.base_dir / "figures"

    @property
    def model_pickle_path(self) -> Path:
        return self.base_dir / "model_rf.pkl"

    @property
    def scaler_pickle_path(self) -> Path:
        return self.base_dir / "scaler.pkl"

    @property
    def norm_npz_path(self) -> Path:
        return self.base_dir / "norm.npz"

    @property
    def model_header_path(self) -> Path:
        return self.export_dir / "rf_model.h"

    @property
    def norm_header_path(self) -> Path:
        return self.export_dir / "norm.h"

    @property
    def confusion_matrix_path(self) -> Path:
        return self.figures_dir / "confusion_matrix.png"

    def ensure_output_dirs(self) -> None:
        self.export_dir.mkdir(parents=True, exist_ok=True)
        self.figures_dir.mkdir(parents=True, exist_ok=True)


DEFAULT_CONFIG = ProjectConfig()
