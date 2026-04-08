#pragma once

#include <math.h>
#include <stdint.h>

#include "../model_export/norm.h"
#include "../model_export/rf_model.h"

namespace SpresenseAnomaly {
constexpr int kFrameSize = 64;
constexpr int kSpectrumBins = 32;
constexpr int kBandCount = 8;
constexpr int kBandWidth = kSpectrumBins / kBandCount;
constexpr float kPi = 3.14159265358979323846f;

struct SensorFrame {
    float acc_x[kFrameSize];
    float acc_y[kFrameSize];
    float acc_z[kFrameSize];
    float mic[kFrameSize];
};

inline float HannWindow(int index) {
    return 0.5f - 0.5f * cosf((2.0f * kPi * index) / (kFrameSize - 1));
}

inline void ExtractBandFeatures(const float* signal, float* output) {
    float spectrum[kSpectrumBins];

    for (int k = 0; k < kSpectrumBins; ++k) {
        float real_part = 0.0f;
        float imag_part = 0.0f;

        for (int n = 0; n < kFrameSize; ++n) {
            const float sample = signal[n] * HannWindow(n);
            const float angle = (2.0f * kPi * k * n) / kFrameSize;
            real_part += sample * cosf(angle);
            imag_part -= sample * sinf(angle);
        }

        spectrum[k] = sqrtf(real_part * real_part + imag_part * imag_part);
    }

    for (int band = 0; band < kBandCount; ++band) {
        float sum = 0.0f;
        for (int offset = 0; offset < kBandWidth; ++offset) {
            sum += spectrum[band * kBandWidth + offset];
        }
        output[band] = sum / kBandWidth;
    }
}

inline void BuildFeatureVector(const SensorFrame& frame, float* features) {
    ExtractBandFeatures(frame.acc_x, &features[0]);
    ExtractBandFeatures(frame.acc_y, &features[8]);
    ExtractBandFeatures(frame.acc_z, &features[16]);
    ExtractBandFeatures(frame.mic, &features[24]);
}

inline void NormalizeFeatures(float* features) {
    for (int i = 0; i < FEATURE_DIM; ++i) {
        features[i] = (features[i] - MU[i]) / SIG[i];
    }
}

inline int Predict(const SensorFrame& frame) {
    float features[FEATURE_DIM];
    BuildFeatureVector(frame, features);
    NormalizeFeatures(features);

    Eloquent::ML::Port::RandomForest model;
    return model.predict(features);
}

inline bool IsAnomaly(const SensorFrame& frame) {
    return Predict(frame) == 1;
}
}  // namespace SpresenseAnomaly
