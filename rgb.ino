#include <RGBLed.h>

RGBLed led(9, 10, 7, RGBLed::COMMON_CATHODE);

int coloursPerState[7][3] = {
    {255, 255, 255}, // NOTINUSE
    {255, 255, 0},   // NR1
    {0, 255, 0},     // NR2
    {255, 0, 0},     // CLEANING
    {255, 0, 255},   // UNDEFINED
    {0, 0, 255},     // TRIGGERED
    {0, 255, 255}    // MENUACTIVE
};