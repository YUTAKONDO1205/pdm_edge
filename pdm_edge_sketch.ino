#include <Arduino.h>

#include "spresense/anomaly_inference.hpp"

#define ACC_X_PIN A0
#define ACC_Y_PIN A1
#define ACC_Z_PIN A2
#define MIC_PIN A3

SpresenseAnomaly::SensorFrame frame;

void readSensors(SpresenseAnomaly::SensorFrame* current_frame) {
  for (int i = 0; i < SpresenseAnomaly::kFrameSize; ++i) {
    current_frame->acc_x[i] = static_cast<float>(analogRead(ACC_X_PIN));
    current_frame->acc_y[i] = static_cast<float>(analogRead(ACC_Y_PIN));
    current_frame->acc_z[i] = static_cast<float>(analogRead(ACC_Z_PIN));
    current_frame->mic[i] = static_cast<float>(analogRead(MIC_PIN));
    delayMicroseconds(100);
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  readSensors(&frame);

  const int result = SpresenseAnomaly::Predict(frame);
  if (result == 1) {
    Serial.println("ANOMALY DETECTED");
  } else {
    Serial.println("NORMAL");
  }

  delay(200);
}
