#include "Timer.cpp"

Timer* updateTemp;
//Timer updateDist(500, millis(), &displayDistance, &getDistance);
//Timer updateMotion(200, millis(), &displayMotion, &getMotion);

void setup() {
  displaySetup();
  updateTemp = new Timer(2000, millis(), &displayTemperature, &getTemperature);
}

void loop() {

  updateTemp->update(millis());
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
