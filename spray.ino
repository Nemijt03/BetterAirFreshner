int oldLight = 0; //moet geen nul zijn maar de oude light
int lightThreshold = 800;
int mosfet = A2;
int spraysRemaining = 0;

// when light on or of
void checkEnterExit(){
    int getL = getLight();
    // Serial.print(F("Light level: "));
    // Serial.println(getL);
    if(abs(getL - oldLight) > 100) {
        
        if(getL >= lightThreshold) { //
            // changeState(UNDEFINED); // blocks waiting for spray
            Serial.println("enter");
            entered = millis();
        }
        if(getL < lightThreshold) {exited = millis(); Serial.println("exit");} //resets van sensors
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
  updateSpray = Timer(timing * 1000, &howManySpray);
  changeState(TRIGGERED);
}

void howManySpray() {
  updateSpray = Timer(10000, &nothing);
  updateSensors(0, sit());
  updateSensors(1, timeOnToilet());
  updateSensors(2, toiletPaper());
  
  int getS = getStateFromSensors();

  // changeState(getS);
  if(getS != 3) {
    spraysRemaining = getS - 1;
    mosfetToggle();
    // for(int i = 0; i < getS; i++) {
      // spray();
    // }
  }
}

void spray() {

  Serial.println(F("Spraying"));
  // decrementRemainingShots();
  digitalWrite(mosfet, HIGH); // change back and keep for 15 secs
  // toIdle();
}

byte mosfetState = LOW;

void mosfetToggle() {
  Serial.print(F("mosfetState: "));
  Serial.println(mosfetState);
  Serial.print(F("spraysRemaining: "));
  Serial.println(spraysRemaining);

  if (mosfetState == LOW) {
    mosfetState = HIGH;
    digitalWrite(mosfet, HIGH);
    Serial.println("LOW");
    builtInSprayDelay = Timer(17000, &mosfetToggle); //TODO 17000 delay
  }
  else if (mosfetState == HIGH && spraysRemaining != 0){
    writeLow();
    spraysRemaining--;
    Serial.println(F("HIGH spraysremaining != 0"));
    builtInSprayDelay = Timer(2000, &mosfetToggle);
  }
  else {
    writeLow();
    Serial.println(F("changestate aanroepen"));
    toIdle();
    // changeState denk ik
    // hoeft niet meer te ticken
  }


}
void writeLow() {
  decrementRemainingShots();
  Serial.println(F("17 sec na mosfet activatie"));
  mosfetState = LOW;
  digitalWrite(mosfet, LOW);
}