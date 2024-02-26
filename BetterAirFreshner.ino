#include "Timer.cpp"
#include "menu.cpp"

Timer updateTemp(2000, &temperature);
Timer updateDist(300, &distance);
Timer updateMotion(300, &motion);
// Timer led(500, &blink);
// Timer led1(350, &blink1);


void setup() {
  displaySetup();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
  
  menuTesting();
}

void loop() {
  loopMenu();
  
  // led.tick();
  // led1.tick();
  // updateTemp.tick();
  // updateDist.tick();
  // updateMotion.tick();
}