# SPRESENSE組み込みガイド

このフォルダには、Python側で学習したモデルをSPRESENSEで使うための最小構成を置いています。

## 使用するファイル

- `model_export/rf_model.h`: 学習済み Random Forest
- `model_export/norm.h`: 正規化用パラメータ
- `spresense/anomaly_inference.hpp`: 特徴量抽出と推論処理
- `pdm_edge_sketch.ino`: 呼び出し例

## 導入手順

1. ルートで `python train.py` を実行します
2. `model_export/rf_model.h` と `model_export/norm.h` が生成されることを確認します
3. `spresense/anomaly_inference.hpp` を含めて、SPRESENSE側プロジェクトから参照できるようにします
4. `pdm_edge_sketch.ino` をベースにセンサ読取処理を組み込みます
5. `SensorFrame` に64サンプルぶんの `acc_x`, `acc_y`, `acc_z`, `mic` を格納します
6. `SpresenseAnomaly::Predict(frame)` を呼び出して、正常 / 異常を判定します

## 推論の流れ

`anomaly_inference.hpp` では、Python側と同じ考え方で以下を実行します。

1. 64サンプルの波形を受け取る
2. Hann window をかける
3. 周波数成分を計算する
4. 先頭32ビンを8帯域に平均化する
5. 4チャンネルぶん連結して32次元特徴量を作る
6. `norm.h` の `MU` と `SIG` で正規化する
7. `rf_model.h` のモデルで推論する

## 注意点

- Python側とSPRESENSE側で、サンプル数や特徴量設計をそろえることが重要です
- モデルを更新したら `model_export/rf_model.h` と `model_export/norm.h` も更新してください
- 高速化したい場合は、同じ特徴量仕様を保ったままFFTライブラリに置き換えると扱いやすいです

## こんなときに確認する場所

- 学習条件を変えたい: `config.py`
- 特徴量処理を見たい: `features.py`
- 組み込み側の処理を見たい: `spresense/anomaly_inference.hpp`
- スケッチ例を見たい: `pdm_edge_sketch.ino`
