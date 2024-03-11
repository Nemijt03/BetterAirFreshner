#include "Timer.cpp"

Timer updateTemp(2000, &updateTemperature);
Timer updateDist(10000, &updateSit);
Timer updateLight(1000, &checkEnterExit);
Timer updateSpray(0, &nothing);
Timer builtInSprayDelay(0, &nothing);
Timer updateSensorState(5000, &sensorStateUpdate);
Timer updateHeartBeat(300, &blinkStateLed);

void setup()
{
  displaySetup();
  setupMagnetSensor();
  setupMotionSensor();
  pinMode(13, OUTPUT);
  pinMode(A3, INPUT);  // Button
  pinMode(7, OUTPUT);  // RGB LED
  pinMode(9, OUTPUT);  // RGB LED
  pinMode(10, OUTPUT); // RGB LED
  pinMode(A2, OUTPUT); // Mosfet

  Serial.begin(9600);
  toIdle();
}

void loop()
{
  loopMenu();
  updateTemp.tick();
  updateLight.tick();
  updateDist.tick();
  updateHeartBeat.tick();
}