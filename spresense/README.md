# SPRESENSE組み込みメモ

このフォルダには、Python側で学習したRandom ForestをSPRESENSEへ持っていくための最小サンプルを置いています。

## 使い方

1. ルートで `python train.py` を実行します
2. 生成された `model_export/rf_model.h` と `model_export/norm.h` を使います
3. [anomaly_inference.hpp](anomaly_inference.hpp) をスケッチから参照できる場所へ置きます
4. ルートの `pdm_edge_sketch.ino` を必要に応じてベースにします
5. `SensorFrame` に64サンプルぶんの `acc_x`, `acc_y`, `acc_z`, `mic` を詰めます
6. `SpresenseAnomaly::Predict(frame)` を呼び出して判定します

## 注意点

- このサンプルはPython側と一致するように、SPRESENSE上でも64点DFT相当の処理を行います
- 高速化したい場合は、同じ特徴量仕様を保ったままFFTライブラリへ置き換えてください
- モデル更新時は `model_export/rf_model.h` と `model_export/norm.h` を更新してください
