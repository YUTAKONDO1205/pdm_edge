from __future__ import annotations

from runtime_bootstrap import ensure_runtime

ensure_runtime(("numpy", "sklearn", "matplotlib", "seaborn", "pandas", "scipy"))

import pickle

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.metrics import classification_report, confusion_matrix
from sklearn.model_selection import train_test_split

from config import DEFAULT_CONFIG, ProjectConfig
from dataset import load_dataset
from features import normalize_features


def load_model_and_scaler(
    config: ProjectConfig = DEFAULT_CONFIG,
) -> tuple[object, np.ndarray, np.ndarray]:
    if not config.model_pickle_path.exists() or not config.scaler_pickle_path.exists():
        raise FileNotFoundError("Run python train.py before evaluation.")

    with config.model_pickle_path.open("rb") as file:
        model = pickle.load(file)

    with config.scaler_pickle_path.open("rb") as file:
        scaler = pickle.load(file)

    return (
        model,
        np.asarray(scaler["mu"], dtype=np.float64),
        np.asarray(scaler["sig"], dtype=np.float64),
    )


def save_confusion_matrix(
    y_true: np.ndarray,
    y_pred: np.ndarray,
    config: ProjectConfig = DEFAULT_CONFIG,
) -> None:
    matrix = confusion_matrix(y_true, y_pred)
    config.ensure_output_dirs()

    plt.figure(figsize=(5, 4))
    sns.heatmap(
        matrix,
        annot=True,
        fmt="d",
        cmap="Blues",
        cbar=False,
        xticklabels=["normal", "error"],
        yticklabels=["normal", "error"],
    )
    plt.xlabel("Predicted")
    plt.ylabel("Actual")
    plt.tight_layout()
    plt.savefig(config.confusion_matrix_path, dpi=200)
    plt.close()


def main() -> None:
    config = DEFAULT_CONFIG
    dataset = load_dataset(config)
    model, mu, sig = load_model_and_scaler(config)
    normalized_features, _, _ = normalize_features(dataset.features, mu=mu, sig=sig)

    _, x_test, _, y_test = train_test_split(
        normalized_features,
        dataset.labels,
        test_size=config.test_size,
        random_state=config.random_state,
        stratify=dataset.labels,
    )

    y_pred = model.predict(x_test)
    print("=== Test ===")
    print(classification_report(y_test, y_pred, digits=4))

    save_confusion_matrix(y_test, y_pred, config)
    print(f"Saved {config.confusion_matrix_path}")


if __name__ == "__main__":
    main()
