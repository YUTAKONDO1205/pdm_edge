# pdm_edge

開発者: 近藤悠太 (Kondo Yuta)

# SPRESENSE Vibration/Acoustic Anomaly Detection

本研究では、三軸加速度センサと音響センサから取得した信号をSPRESENSEでサンプリングし、
FFTにより特徴量を抽出した後、Isolation ForestとRandom Forestを用いて異常兆候を検知する。
対象はモーターの異常振動であり、不釣り合いおもりを付与した異常状態との比較により評価した。

SPRESENSEと加速度・音響センサを用いた振動異常検知AIシステムのGitHub公開用リポジトリです。

この研究では、三軸加速度センサと音響センサをSPRESENSEで同期サンプリングし、FFTで特徴量を作成し、Isolation ForestとRandom Forestを用いて異常候補抽出と分類を行います。サンプリングは10 kHz、特徴量は4チャネル×50 bin = 200次元、窓長100サンプル、75%オーバーラップが研究の基本設定です。

## リポジトリ構成

```text
pdm_edge/
├── data/
│   └── raw/
│       ├── normal/
│       └── error/
├── export/
├── figures/
├── models/
├── spresense/
├── src/
│   ├── config.py
│   ├── dataset.py
│   ├── features.py
│   ├── train.py
│   ├── evaluate.py
│   └── export_headers.py
├── .gitignore
├── requirements.txt
└── README.md
```

## 想定CSV形式

ヘッダ付きCSVを想定します。

```csv
accX,accY,accZ,mic
0.01,-0.03,0.98,2048
...
```

## 使い方

### 1. 環境構築

```bash
python -m venv .venv
source .venv/bin/activate  # Windows: .venv\Scripts\activate
pip install -r requirements.txt
```

### 2. データ配置

```text
data/raw/normal/sensor_log_normal_1.csv
data/raw/normal/sensor_log_normal_2.csv
data/raw/normal/sensor_log_normal_3.csv
data/raw/error/sensor_log_erorr_1.csv
data/raw/error/sensor_log_erorr_2.csv
data/raw/error/sensor_log_erorr_3.csv
```

### 3. 学習

```bash
python -m src.train
```

### 4. 評価・可視化

```bash
python -m src.evaluate
```

### 5. 組込み用ヘッダ出力

```bash
python -m src.export_headers
```

## 出力物

- `models/random_forest.joblib`
- `models/isolation_forest.joblib`
- `models/scaler.joblib`
- `export/norm.h`
- `export/rf_model.h`
- `figures/*.png`

## GitHubに載せるときのコツ

- `data/raw/` の生データは容量や公開範囲を見て、必要なら `.gitignore` 対象にする
- 論文・ポスターの図は `figures/` に保存する
- 学習済みモデルを載せるなら、再現手順と学習条件をREADMEに明記する
- 研究概要、使用センサ、評価条件をREADME冒頭に書く

## 研究メモ

研究資料では、Random Forest 300木、Isolation Forest 100木、さらに正常252/300・異常300/300の結果や、250〜350 Hz帯域の差が主要指標として整理されています。fileciteturn1file11
