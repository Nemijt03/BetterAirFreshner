int oldLight = 0; //moet geen nul zijn maar de oude light

// when light on or of
void checkEnterExit(){
    int getL = getLight();
    if(abs(getL - oldLight) > 100) {
        if(whenSX == 500) {
            changeState(UNDEFINED);
            entered = millis();
        }
        if(whenSX == 0) exited = millis();
        if(getL > whenSX && getL < whenSY) timedSpray(); 
    }
    oldLight = getL;
}

int timeOnToilet(){
  if(exited - entered >= longEnough && getMotion()) return 1;
  return 0;
}

void timedSpray() {
  int timing = timeToSpray - 15;
  updateSpray = Timer(timing, &howManySpray);
  changeState(TRIGGERED);
}

void howManySpray() {
  updateSensors(0, sit());
  updateSensors(1, timeOnToilet());
  updateSensors(2, toiletPaper());
  
  int getS = getStateFromSensors();
  changeState(getS);
  if(getS != 3) {
    for(int i = 0; i < getS; i++) {
      spray();
    }
  }
}

void spray() {
  Serial.println(F("Spraying"));
  digitalWrite(7, HIGH);
  changeState(NOTINUSE);
}
