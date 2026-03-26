import pandas as pd
import numpy as np
import os
from glob import glob
from scipy.fft import rfft
from scipy.signal import windows
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split
from micromlgen import port

# 設定
DATA_DIR = 'data'
EXPORT_DIR = 'model_export'
CHANNELS = ['accX', 'accY', 'accZ', 'mic']
N_FFT = 512
BIN_SIZE = 32                   # 512→256point使うので 32bin平均 → 8次元/ch
DIM_PER_CH = 256 // BIN_SIZE   # = 8
FINAL_DIM = DIM_PER_CH * len(CHANNELS)  # = 8×4 = 32次元

# 出力フォルダ作成
os.makedirs(EXPORT_DIR, exist_ok=True)

# 特徴抽出関数（FFT→bin平均）
def extract_features(signal):
    sig = signal.values
    if len(sig) != N_FFT:
        sig = sig[:N_FFT]  # 念のため長さ制限
    windowed = sig * windows.hann(len(sig))
    fft = np.abs(rfft(windowed))[:256]  # 512点のうち0〜256まで（Nyquist 500Hz）
    feat = [fft[i*BIN_SIZE:(i+1)*BIN_SIZE].mean() for i in range(DIM_PER_CH)]
    return feat

# データ読み込み関数
def load_dataset(label, keyword):
    x_list, y_list = [], []
    files = sorted([f for f in os.listdir(DATA_DIR) if keyword in f and f.endswith('.csv')])
    for fname in files:
        df = pd.read_csv(os.path.join(DATA_DIR, fname))
        feats = []
        for ch in CHANNELS:
            if ch not in df.columns:
                print(f"⚠ 列 {ch} が {fname} にありません")
                continue
            feats.extend(extract_features(df[ch]))
        if len(feats) == FINAL_DIM:
            x_list.append(feats)
            y_list.append(label)
    return np.array(x_list), np.array(y_list)

# データ読み込み
X_normal, y_normal = load_dataset(0, 'normal')
X_error,  y_error  = load_dataset(1, 'error')
X = np.vstack([X_normal, X_error])
y = np.concatenate([y_normal, y_error])

# 正規化
MU = X.mean(axis=0)
SIG = np.clip(X.std(axis=0), 1e-3, None)
Xn = (X - MU) / SIG

# train/test分割（汎化性能確認用）
X_train, X_test, y_train, y_test = train_test_split(Xn, y, test_size=0.25, random_state=42, stratify=y)

# 学習
clf = RandomForestClassifier(n_estimators=100, random_state=42)
clf.fit(X_train, y_train)

# 評価
print("=== Train ===")
print(classification_report(y_train, clf.predict(X_train)))
print("=== Test ===")
print(classification_report(y_test, clf.predict(X_test)))

# モデルをC++用に変換
with open(f'{EXPORT_DIR}/rf_model.h', 'w') as f:
    f.write(port(clf))
with open(f'{EXPORT_DIR}/norm.h', 'w') as f:
    f.write(f'const float MU[{FINAL_DIM}] = {{' + ','.join([f'{m:.6f}' for m in MU]) + '};\n')
    f.write(f'const float SIG[{FINAL_DIM}] = {{' + ','.join([f'{s:.6f}' for s in SIG]) + '};\n')

print("✅ モデル学習＆C++ヘッダ出力が完了しました。")
