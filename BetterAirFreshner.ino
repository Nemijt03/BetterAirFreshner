#include "Timer.cpp"

Timer updateTemp(2000, &updateTemperature);
Timer updateDist(10000, &updateSit);
Timer updateMotion(1000, &updateMoveIt);
Timer updateLight(1000, &checkEnterExit);
Timer updateSpray(0, &nothing);
Timer updateMagnet(1000, &updatePaper);

void setup() {
  displaySetup();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A3, INPUT); // Button
  pinMode(6, OUTPUT); // RGB LED
  pinMode(9, OUTPUT); // RGB LED
  pinMode(10, OUTPUT); // RGB LED

  Serial.begin(9600);
  toIdle();
}

void loop() {
  loopMenu();
  updateTemp.tick();
  updateLight.tick();
  updateDist.tick();
  updateMotion.tick();
  updateMagnet.tick();
}