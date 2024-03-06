int oldLight = 0; //moet geen nul zijn maar de oude light

// when light on or of
void checkEnterExit(){
    int getL = getLight();
    Serial.println(getL);
    if(abs(getL - oldLight) > 100) {
        
        if(getL >= 800) {
            changeState(UNDEFINED);
            Serial.println("enter");
            entered = millis();
        }
        if(getL < 800) {exited = millis(); Serial.println("exit");}
        if(getL > whenSX && getL < whenSY && getL < 800) {timedSpray();} 
    }
    oldLight = getL;
}

int timeOnToilet(){
  Serial.print("time on toilet: "); 
  Serial.println(exited - entered);
  if((exited - entered >= longEnough) && getMotion()) {return 1;}
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
  
  Serial.println(toiletPaper());
  int getS = getStateFromSensors();
  Serial.println(getS);

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
