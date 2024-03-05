#include "Timer.cpp"
#include "menu.cpp"

Timer updateTemp(2000, &updateTemperature);
Timer updateDist(300, &distance);
Timer updateMotion(300, &motion);
Timer updateLight(1000, &light);
// Timer led(500, &blink);
// Timer led1(350, &blink1);


void setup() {
  displaySetup();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, OUTPUT); // LED
  pinMode(A3, INPUT); // Button
  pinMode(6, OUTPUT); // RGB LED
  pinMode(9, OUTPUT); // RGB LED
  pinMode(10, OUTPUT); // RGB LED

  Serial.begin(9600);
  // button input needs to be coupled
  toIdle();
}

void loop() {
  loopMenu();
  updateTemp.tick();
  updateLight.tick();
  // led.tick();
  // led1.tick();
  // updateDist.tick();
  // updateMotion.tick();
}