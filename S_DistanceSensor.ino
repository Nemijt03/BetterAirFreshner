#include <HCSR04.h>

HCSR04 hc(A4, A5); //initialisation class HCSR04 (trig pin , echo pin)
int beenSatOn = 0;

// make sure there is a minimum 6 ms delay between pulses
float getDistance() {
  return hc.dist();
}

void updateSit(){
  if(getDistance() < closeEnough) beenSatOn = 1;
}

int sit(){
  return beenSatOn;
}