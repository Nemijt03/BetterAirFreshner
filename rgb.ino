#include <RGBLed.h>

RGBLed led(9, 10, 7, RGBLed::COMMON_CATHODE);

int coloursPerState[7][3] = {
    {75,1,94},              // NOTINUSE -- Purple
    {70,200,180},           // NR1 -- Turqoise
    {255,120,0},            // NR2 -- Gold
    {255,0,0},              // CLEANING
    {0,255,0},              // UNDEFINED
    {255,255,0},            // TRIGGERED
    {0,255,255}             // MENUACTIVE
};