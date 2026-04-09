from pathlib import Path

from runtime_bootstrap import ensure_runtime

ensure_runtime(("numpy",))

import numpy as np

from config import DEFAULT_CONFIG
from export_headers import render_norm_header


def main() -> None:
    with np.load(DEFAULT_CONFIG.norm_npz_path) as data:
        mu = data["mu"]
        sig = data["sig"]
    header = render_norm_header(mu, sig)

    DEFAULT_CONFIG.norm_header_path.parent.mkdir(parents=True, exist_ok=True)
    DEFAULT_CONFIG.norm_header_path.write_text(header, encoding="utf-8")
    print(f"Wrote {DEFAULT_CONFIG.norm_header_path}")


if __name__ == "__main__":
    main()
