from pathlib import Path

from runtime_bootstrap import ensure_runtime

ensure_runtime(("numpy",))

import numpy as np

from config import DEFAULT_CONFIG


NORM_PATH = DEFAULT_CONFIG.norm_npz_path


def main() -> None:
    data = np.load(NORM_PATH)
    mu = data["mu"]
    sig = data["sig"]

    print(f"norm file: {NORM_PATH}")
    print(f"MU shape: {mu.shape}")
    print(f"SIG shape: {sig.shape}")
    print(f"SIG has zero: {np.any(sig == 0)}")
    print(f"SIG has NaN: {np.any(np.isnan(sig))}")
    print(f"SIG has inf: {np.any(np.isinf(sig))}")


if __name__ == "__main__":
    main()
