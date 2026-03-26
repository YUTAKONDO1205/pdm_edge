import numpy as np

# norm.npz を読み込む
d = np.load('norm.npz')
MU = d['mu']
SIG = d['sig']

# 基本情報を表示
print("MU shape:", MU.shape)
print("SIG shape:", SIG.shape)

# チェック項目
print("=== SIG のチェック ===")
print("0 が含まれているか:", np.any(SIG == 0))
print("NaN が含まれているか:", np.any(np.isnan(SIG)))
print("inf が含まれているか:", np.any(np.isinf(SIG)))

# もしあればそのインデックスも確認
print("0 の位置:", np.where(SIG == 0)[0])
