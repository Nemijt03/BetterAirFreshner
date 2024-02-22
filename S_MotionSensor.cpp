#include <Arduino.h>

int sensorPin = 10;

int getMotion() {
  return digitalRead(sensorPin);
}
