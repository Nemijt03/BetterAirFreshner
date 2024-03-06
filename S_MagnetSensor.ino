//onder op stokje plakken 
// en in extented wc rol plakken
// na 1 hele ronden heeft die contact
int rolls = 0;
byte hasContact = 1;

//doet het nog niet
void updatePaper() {
    byte cont = 0;
    byte butt = getButton();
    if(butt == 4) cont = 1;
    else if(butt > 0) return;

    if(cont && !hasContact) {
        rolls += 1;
        hasContact = cont;
    }
    Serial.println(rolls);
}

int toiletPaper() {
  if(rolls == 0) return 0;
  if(rolls <= 3) return 1; //testen hoeveel
  return 2;
}