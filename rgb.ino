#include <RGBLed.h>

int purple[3] = {75,1,94};
int turqoise[3] = {70,200,180};
int gold[3] = {255,120,0};

RGBLed led(9, 10, 6, RGBLed::COMMON_CATHODE);

void flash() {
    led.flash(purple, 1000);
    led.flash(turqoise, 1000);
    led.flash(gold, 1000);
}