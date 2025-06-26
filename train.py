"""
train.py  ――  FFT200次元特徴＋RandomForest 学習 & Cヘッダ生成
---------------------------------------------------------------
  python train.py              # 学習と精度出力
  python train.py --export-c   # 上に加えて rf_model.h norm.npz 生成
"""

import numpy as np, pandas as pd, argparse
from pathlib import Path
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
import joblib   # ← 再学習用 pickle 保存に使う

# ------------------- parameters ------------------- #
FS = 10_000; WIN_LEN = 100; OVERLAP = 0.25
NFFT = 1_024; FEAT_BIN = 50
COLS = ["accX", "accY", "accZ", "mic"]

# ---------------- helper ---------------- #
def windows(df, wlen, overlap):
    hop = int(wlen * (1-overlap))
    for st in range(0, len(df)-wlen+1, hop):
        yield df.iloc[st:st+wlen]

def fft_feature(win):
    feats=[]
    for c in COLS:
        x = win[c].astype(float).values
        x -= x.mean()
        spec = np.abs(np.fft.rfft(np.pad(x,(0,NFFT-len(x))))) / len(x)
        feats.append(spec[:FEAT_BIN])
    return np.array(feats)   # (4,50)

def build_dataset(data_dir="data"):
    xs, ys = [], []
    for p in sorted(Path(data_dir).glob("sensor_log_*.csv")):
        df = pd.read_csv(p)
        if df.columns[0] != "accX":
            df.columns = COLS[:df.shape[1]]
        lab = 0 if "normal" in p.name else 1
        for w in windows(df, WIN_LEN, OVERLAP):
            xs.append(fft_feature(w));  ys.append(lab)
    X = np.stack(xs).reshape(len(xs), -1)
    return X, np.array(ys)

# -------------------- main ------------------------ #
if __name__ == "__main__":
    ap = argparse.ArgumentParser()
    ap.add_argument("--export-c", action="store_true")
    ap.add_argument("--data-dir", default="data")
    args = ap.parse_args()

    # 1. データ読み込み
    X_raw, y = build_dataset(args.data_dir)

    # 2. 正規化
    scaler = StandardScaler().fit(X_raw)
    X = scaler.transform(X_raw)
    np.savez("norm.npz", mu=scaler.mean_, sigma=scaler.scale_)
    print("[OK] norm.npz saved")

    # 3. 学習 / テスト分割
    Xtr,Xte,ytr,yte = train_test_split(X, y, test_size=0.2,
                                       stratify=y, random_state=42)

    # 4. RF 学習
    rf = RandomForestClassifier(n_estimators=300, random_state=42)
    rf.fit(Xtr, ytr)
    print(f"Train acc: {rf.score(Xtr,ytr):.3f}  Test acc: {rf.score(Xte,yte):.3f}")

    # 5. 任意でエクスポート
    if args.export_c:
        from micromlgen import port
        with open("rf_model.h","w") as f:
            f.write(port(rf, classmap={0:"NORMAL",1:"ERROR"}, dtype="int16"))
        joblib.dump(rf,     "model_rf.pkl")
        joblib.dump(scaler, "scaler.pkl")
        print("[OK] rf_model.h / model_rf.pkl / scaler.pkl generated")

