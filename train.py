"""
train.py  ――  FFT200次元特徴＋RandomForest 学習 & Cヘッダ生成
---------------------------------------------------------------
使い方：
    # 学習とテスト精度出力のみ
    python train.py

    # 学習＋モデルを C ヘッダ化
    python train.py --export-c
"""

import numpy as np
import pandas as pd
from pathlib import Path
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble  import RandomForestClassifier
from sklearn.model_selection import train_test_split
import argparse

# ------------------- parameters ------------------- #
FS       = 10_000          # sampling freq [Hz]
WIN_LEN  = 100             # window length (samples)
OVERLAP  = 0.25            # 25 % overlap
NFFT     = 1_024           # FFT length (2^n)
FEAT_BIN = 50              # 0–500 Hz → 50 bins
COLS     = ["accX", "accY", "accZ", "mic"]

# ---------------- helper functions ---------------- #
def windows(df, wlen, overlap):
    hop = int(wlen * (1 - overlap))
    for start in range(0, len(df) - wlen + 1, hop):
        yield df.iloc[start:start + wlen]

def fft_feature(win):
    """return (4,50) array"""
    feats = []
    for c in COLS:
        x = win[c].astype(float).values
        x -= x.mean()
        spec = np.abs(np.fft.rfft(np.pad(x, (0, NFFT - len(x))))) / len(x)
        feats.append(spec[:FEAT_BIN])            # 0–500 Hz
    return np.array(feats)

def build_dataset(data_dir="data"):
    feats, labs = [], []
    for path in sorted(Path(data_dir).glob("sensor_log_*.csv")):
        df = pd.read_csv(path)
        if df.columns[0] != "accX":              # ヘッダなし対策
            df.columns = COLS[:df.shape[1]]
        label = 0 if "normal" in path.name else 1
        for w in windows(df, WIN_LEN, OVERLAP):
            feats.append(fft_feature(w))
            labs.append(label)
    X = np.stack(feats).reshape(len(feats), -1)  # (N,200)
    y = np.array(labs)
    return X, y

# -------------------- main ------------------------ #
if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--export-c", action="store_true",
                    help="export trained RF to rf_model.h (int16)")
    ap.add_argument("--data-dir", default="data",
                    help="directory containing sensor_log_*.csv")
    args = ap.parse_args()

    # 1) load data & feature extraction
    X_raw, y = build_dataset(args.data_dir)

    # 2) standardize
    scaler = StandardScaler().fit(X_raw)
    X = scaler.transform(X_raw)
    np.savez("norm.npz", mu=scaler.mean_, sigma=scaler.scale_)
    print("[OK] norm.npz saved  (μ, σ)")

    # 3) train / test split
    X_tr, X_te, y_tr, y_te = train_test_split(
        X, y, test_size=0.2, stratify=y, random_state=42)

    # 4) Random Forest training
    rf = RandomForestClassifier(n_estimators=300, max_depth=None,
                                random_state=42)
    rf.fit(X_tr, y_tr)
    acc = rf.score(X_te, y_te)
    print(f"Test accuracy  : {acc:.3f}")
    print(f"Train accuracy : {rf.score(X_tr, y_tr):.3f}")

    # 5) export C header
    if args.export_c:
        try:
            from micromlgen import port
            with open("rf_model.h", "w") as f:
                f.write(port(rf, dtype="int16"))
            print("[OK] rf_model.h generated")
        except ImportError:
            print("micromlgen not installed; skip C header export.")
