// onder op stokje plakken
//  en in extented wc rol plakken
//  na 1 hele ronden heeft die contact
int magnetPin = 3;
int rolls = 0;

void setupMagnetSensor()
{
  pinMode(magnetPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(magnetPin), updatePaper, FALLING);
}

void updatePaper()
{
  rolls++;
}

int toiletPaper()
{
  if (rolls == 0)
    return 0;
  if (rolls <= 5)
    return 1;
  return 2;
}

void resetPaper()
{
  rolls = 0;
}