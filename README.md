# pdm_edge

開発者: 近藤悠太 (Kondo Yuta)

## 概要

このリポジトリは、SPRESENSEと加速度・音響センサを用いた振動異常検知AIシステムです。  
加速度3軸とマイクの4チャンネル波形を使い、エッジ側で異常を判定できるようにしています。

実装の流れはシンプルで、以下の構成です。

- 波形読込
- FFTによる周波数特徴量抽出
- 正規化
- Random Forest による正常 / 異常分類
- SPRESENSE向けヘッダ出力

## 主なファイル

- `README.md`: プロジェクト全体の説明
- `requirements.txt`: Python依存関係
- `config.py`: 学習条件やパス設定
- `dataset.py`: CSVデータの読込
- `features.py`: FFTと特徴量生成
- `train.py`: 学習とモデル保存
- `evaluate.py`: 評価と混同行列出力
- `export_headers.py`: SPRESENSE向けヘッダ再生成
- `pdm_edge_sketch.ino`: SPRESENSE側の最小スケッチ例
- `spresense/README.md`: 組み込み側の使い方

`src/` 配下には互換用の薄いラッパーを残してあり、`python -m src.train` のような呼び出しもできます。

## ディレクトリ構成

```text
pdm_edge/
├─ data/
│  ├─ normal/
│  └─ error/
├─ figures/
├─ model_export/
│  ├─ rf_model.h
│  └─ norm.h
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
├─ runtime_bootstrap.py
├─ pdm_edge_sketch.ino
└─ requirements.txt
```

`data/raw/normal` と `data/raw/error` の構成でも読み込めます。

## 入力データ形式

CSVは以下の4列を想定しています。

```csv
accX,accY,accZ,mic
7588,-8864,-12064,327
7616,-8916,-12128,330
7644,-8832,-12120,335
...
```

- 1ファイルあたり64サンプルを想定
- 64未満なら0埋め
- 64を超える場合は先頭64サンプルを使用

## 特徴量設計

- 使用チャンネル: `accX`, `accY`, `accZ`, `mic`
- 窓長: 64 samples
- 窓関数: Hann window
- FFT: 先頭32ビンを使用
- 帯域平均: 8バンド
- 最終特徴量次元: `8 x 4 = 32`
- 分類器: `RandomForestClassifier`

設定値は `config.py` にまとめています。

## セットアップ

```bash
python -m venv .venv
.venv\Scripts\activate
pip install -r requirements.txt
```

補足:

- `python train.py` 実行時に必要ライブラリが見つからない場合、`runtime_bootstrap.py` がローカルの `venv` を優先して再実行します
- それでも不足する場合は `pip install -r requirements.txt` を実行してください

## 学習

```bash
python train.py
```

学習後に以下が生成されます。

- `model_rf.pkl`
- `scaler.pkl`
- `norm.npz`
- `model_export/rf_model.h`
- `model_export/norm.h`

## 評価

```bash
python evaluate.py
```

評価結果を表示し、混同行列を以下に保存します。

- `figures/confusion_matrix.png`

## ヘッダ再出力

```bash
python export_headers.py
```

保存済みの `model_rf.pkl` と `scaler.pkl` から、SPRESENSE向けヘッダを再生成します。  
出力先は `model_export/` 配下です。

## SPRESENSEへの組み込み

SPRESENSE側では以下のファイルを使います。

- `model_export/rf_model.h`
- `model_export/norm.h`
- `spresense/anomaly_inference.hpp`
- `pdm_edge_sketch.ino`

基本手順:

1. `python train.py` でモデルとヘッダを生成する
2. `model_export/` 配下のヘッダをSPRESENSE側プロジェクトで参照する
3. `SensorFrame` に64サンプルぶんのセンサ値を格納する
4. `SpresenseAnomaly::Predict(frame)` を呼び出す

詳細は [spresense/README.md](C:/Users/PC_User/pdm_edge/spresense/README.md) を参照してください。

## 補足

- センサ構成を変更したい場合は `config.py` の `channels` を編集します
- 特徴量粒度を変えたい場合は `fft_size`, `spectrum_bins`, `band_count` を調整します
- 現在の実装は軽量性と組み込みやすさを優先して Random Forest ベースにしています
