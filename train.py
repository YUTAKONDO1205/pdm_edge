from __future__ import annotations

from runtime_bootstrap import ensure_runtime

ensure_runtime(("numpy", "sklearn", "pandas", "scipy", "micromlgen"))

import pickle

import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split

from config import DEFAULT_CONFIG, ProjectConfig
from dataset import load_dataset
from export_headers import export_headers
from features import normalize_features


def save_artifacts(
    model: RandomForestClassifier,
    mu: np.ndarray,
    sig: np.ndarray,
    config: ProjectConfig = DEFAULT_CONFIG,
) -> None:
    config.ensure_output_dirs()

    with config.model_pickle_path.open("wb") as file:
        pickle.dump(model, file)

    with config.scaler_pickle_path.open("wb") as file:
        pickle.dump(
            {
                "mu": mu,
                "sig": sig,
                "channels": config.channels,
                "fft_size": config.fft_size,
                "spectrum_bins": config.spectrum_bins,
                "band_count": config.band_count,
            },
            file,
        )

    np.savez(config.norm_npz_path, mu=mu, sig=sig)
    export_headers(model, mu, sig, config)


def main() -> None:
    config = DEFAULT_CONFIG
    dataset = load_dataset(config)
    normalized_features, mu, sig = normalize_features(dataset.features)

    x_train, x_test, y_train, y_test = train_test_split(
        normalized_features,
        dataset.labels,
        test_size=config.test_size,
        random_state=config.random_state,
        stratify=dataset.labels,
    )

    model = RandomForestClassifier(
        n_estimators=config.n_estimators,
        random_state=config.random_state,
    )
    model.fit(x_train, y_train)

    print(
        f"Loaded {len(dataset.labels)} samples "
        f"({int((dataset.labels == 0).sum())} normal / {int((dataset.labels == 1).sum())} error)"
    )
    print(f"Feature dimension: {config.feature_dim}")
    print("=== Train ===")
    print(classification_report(y_train, model.predict(x_train), digits=4))
    print("=== Test ===")
    print(classification_report(y_test, model.predict(x_test), digits=4))

    save_artifacts(model, mu, sig, config)

    print(f"Saved {config.model_pickle_path}")
    print(f"Saved {config.scaler_pickle_path}")
    print(f"Saved {config.norm_npz_path}")
    print(f"Saved {config.model_header_path}")
    print(f"Saved {config.norm_header_path}")


if __name__ == "__main__":
    main()
