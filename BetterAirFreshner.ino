#include "Timer.cpp"

void temperature() {
  displayTemperature(getTemperature());
}

Timer updateTemp(2000, &temperature);
//Timer updateDist(500, millis(), &displayDistance, &getDistance);
//Timer updateMotion(200, millis(), &displayMotion, &getMotion);

void setup() {
  displaySetup();
  // updateTemp = &createTimer(2000, &distance);
}

void loop() {
  updateTemp.tick();
//  updateDist.update(millis());
//  updateMotion.update(millis());
  
//  if (updateTemp.isTime(millis())) {
//    displayTemperature(getTemperature());
//    updateTemp.reset(millis());
//  }
//  
//  if (updateDist.isTime(millis())) {
//    displayDistance(getDistance());
//    updateDist.reset(millis());
//  }
//  
//  if (updateMotion.isTime(millis())) {
//    displayMotion(getMotion());
//    updateMotion.reset(millis());
//  }
  
}
