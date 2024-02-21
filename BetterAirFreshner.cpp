#include <Arduino.h>
#include "Timer.cpp"

Timer updateTemp(2000, &temperature);
Timer updateDist(300, &distance);
Timer updateMotion(300, &motion);
// Timer led(500, &blink);
// Timer led1(350, &blink1);

void setup() {
  displaySetup();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // led.tick();
  // led1.tick();
  updateTemp.tick();
  updateDist.tick();
  updateMotion.tick();
}
