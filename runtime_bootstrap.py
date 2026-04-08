from __future__ import annotations

import importlib.util
import subprocess
import sys
from pathlib import Path


def _resolve_local_venv_python(project_root: Path) -> Path:
    if sys.platform.startswith("win"):
        return project_root / "venv" / "Scripts" / "python.exe"

    return project_root / "venv" / "bin" / "python"


def ensure_runtime(required_modules: tuple[str, ...]) -> None:
    missing = [name for name in required_modules if importlib.util.find_spec(name) is None]
    if not missing:
        return

    project_root = Path(__file__).resolve().parent
    venv_python = _resolve_local_venv_python(project_root)
    current_python = Path(sys.executable).resolve()

    if venv_python.exists() and venv_python.resolve() != current_python:
        completed = subprocess.run([str(venv_python), *sys.argv], check=False)
        raise SystemExit(completed.returncode)

    missing_names = ", ".join(missing)
    raise ModuleNotFoundError(
        f"Missing required modules: {missing_names}. "
        f"Run `pip install -r requirements.txt` or activate the local virtual environment."
    )
