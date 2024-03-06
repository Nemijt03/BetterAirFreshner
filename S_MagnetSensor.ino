//onder op stokje plakken 
// en in extented wc rol plakken
// na 1 hele ronden heeft die contact
int magnetPin = 3;
int rolls = 0;
byte hasContact = 0;
byte cont = 0;


void setupMotionSensor() {
  pinMode(magnetPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(magnetPin), triggerMove, FALLING); // TRIGGERMOVE VERVANGEN
}


//doet het nog niet
void updatePaper() {
   
    byte butt = digitalRead(magnetPin);
    if(butt == LOW) {
        cont = 1; 
    }
    else if (butt == HIGH){
        hasContact = 0;
        cont = 0;
    }

    if(cont && !hasContact) {
        rolls += 1;
        hasContact = 1;
    }
    Serial.println(rolls);
}

int toiletPaper() {
  if(rolls == 0) return 0;
  if(rolls <= 3) return 1; //testen hoeveel
  return 2;
}