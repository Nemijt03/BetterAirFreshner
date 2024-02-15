#include <HCSR04.h>

HCSR04 hc(A4, A5); //initialisation class HCSR04 (trig pin , echo pin)

// make sure there is a minimum 6 ms delay between pulses
float getDistance() {
  return hc.dist();
}
