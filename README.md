# pdm_edge

開発者: 近藤悠太 (Kondo Yuta)

# SPRESENSE Vibration/Acoustic Anomaly Detection

本研究では、三軸加速度センサと音響センサから取得した信号をSPRESENSEでサンプリングし、
FFTにより特徴量を抽出した後、Isolation ForestとRandom Forestを用いて異常兆候を検知する。
対象はモーターの異常振動であり、不釣り合いおもりを付与した異常状態との比較により評価した。

SPRESENSEと加速度・音響センサを用いた振動異常検知AIシステムのGitHub公開用リポジトリです。

この研究では、三軸加速度センサと音響センサをSPRESENSEで同期サンプリングし、FFTで特徴量を作成し、Isolation ForestとRandom Forestを用いて異常候補抽出と分類を行います。サンプリングは10 kHz、特徴量は4チャネル×50 bin = 200次元、窓長100サンプル、75%オーバーラップが研究の基本設定です。
# SPRESENSEと加速度・音響センサを用いた振動異常検知AIシステム

SPRESENSEと加速度・音響センサの4チャンネル波形を使って、振動異常を判定するエッジAIサンプルです。  
実装の流れは既存の形を踏襲し、`FFT -> 周波数帯域平均 -> 正規化 -> RandomForest -> C/C++ヘッダ出力` のまま整理しています。

## 主なファイル

- `README.md`
- `requirements.txt`
- `config.py`
- `dataset.py`
- `features.py`
- `train.py`
- `evaluate.py`
- `export_headers.py`
- `pdm_edge_sketch.ino`

互換用に `src/` も残してあり、`python -m src.train` のような呼び出しもできます。

## ディレクトリ構成

```text
pdm_edge/
├─ data/
│  ├─ normal/
│  └─ error/
├─ figures/
├─ model_export/
├─ spresense/
│  ├─ README.md
│  └─ anomaly_inference.hpp
├─ config.py
├─ dataset.py
├─ features.py
├─ train.py
├─ evaluate.py
├─ export_headers.py
├─ check_norm.py
├─ npz2header.py
├─ pdm_edge_sketch.ino
└─ README.md
```

`data/raw/normal` と `data/raw/error` の構成でも読み込めます。

## 入力CSV形式

```csv
accX,accY,accZ,mic
7588,-8864,-12064,327
7616,-8916,-12128,330
7644,-8832,-12120,335
...
```

1ファイルは64サンプルを想定しています。  
64未満なら0埋め、64を超える場合は先頭64サンプルを使います。

## 特徴量設計

- 4チャンネル: `accX`, `accY`, `accZ`, `mic`
- 窓長: 64 samples
- 窓関数: Hann window
- 周波数特徴: FFT先頭32ビンを8帯域に平均化
- 特徴量次元: `8 bands x 4 channels = 32`
- 分類器: `RandomForestClassifier`

設定値は `config.py` にまとめています。

## セットアップ

```bash
python -m venv .venv
.venv\Scripts\activate
pip install -r requirements.txt
```

## 学習

```bash
python train.py
```

生成される主なファイル:

- `model_rf.pkl`
- `scaler.pkl`
- `norm.npz`
- `model_export/rf_model.h`
- `model_export/norm.h`

## 評価

```bash
python evaluate.py
```

評価結果を表示し、混同行列を `figures/confusion_matrix.png` に保存します。

## ヘッダ再出力

```bash
python export_headers.py
```

保存済みの `model_rf.pkl` と `scaler.pkl` から、SPRESENSE組み込み用のヘッダを再生成します。

## SPRESENSE組み込み

`spresense/anomaly_inference.hpp` に、Python側と同じ特徴量抽出と正規化処理を入れています。  
`pdm_edge_sketch.ino` はそれを呼び出す最小スケッチです。

基本手順:

1. `python train.py` で `model_export/rf_model.h` と `model_export/norm.h` を生成する
2. 必要なヘッダをSPRESENSE側プロジェクトへ配置する
3. `SensorFrame` に64サンプルぶんの `acc_x`, `acc_y`, `acc_z`, `mic` を入れる
4. `SpresenseAnomaly::Predict(frame)` で判定する

詳細は `spresense/README.md` を参照してください。

## 補足

- センサ構成を増やす場合は `config.py` の `channels` を変更します
- 特徴量粒度を変える場合は `fft_size`, `spectrum_bins`, `band_count` を調整します
- 実装は軽量さを優先し、既存方針どおり Random Forest ベースにしています
