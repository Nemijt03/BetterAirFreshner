#include <LiquidCrystal.h>
#include <EEPROM.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 6, d7 = A1;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int timeToSpray = 15;
int entered = 0;
int exited = 0;
float longEnough = 300000; // 5 minutes and then it's a long time
int closeEnough = 200;
int backlightPin = 13;

byte degree[] = {
    B01100,
    B10010,
    B10010,
    B01100,
    B00000,
    B00000,
    B00000,
    B00000};

#define NOTINUSE 0
#define NR1 1
#define NR2 2
#define CLEANING 3
#define UNDEFINED 4
#define TRIGGERED 5
#define MENUACTIVE 6
byte state = NOTINUSE;

int getRemainingShots()
{
  int res;
  EEPROM.get(0, res);
  return res;
}

void resetRemainingShots()
{
  EEPROM.put(0, 2400);
}

void decrementRemainingShots()
{
  int i = getRemainingShots();
  i--;
  EEPROM.put(0, i);
}
struct MenuItem
{
  String name;
  void (*func)();
  bool selected;

  MenuItem(String Name, void (*Func)(), bool Selected)
  {
    name = Name;
    func = Func;
    selected = Selected;
  }
};

MenuItem idleMenu[1] = {MenuItem("To settings", &toSelectorMenu, true)};
MenuItem confirmReset[2] = {MenuItem("OK", &resetShots, true), MenuItem("CANCEL", &toIdle, false)};
MenuItem selectorMenu[3] =
    {MenuItem("Reset shots", &resetShotsConfirm, false), MenuItem("Timing options", &toTimingMenu, false), MenuItem("Back to idle", &toIdle, true)};
MenuItem timingMenu[10] =
    {
        MenuItem("15 seconds", &selectTiming, true), MenuItem("18 seconds", &selectTiming, false),
        MenuItem("21 seconds", &selectTiming, false), MenuItem("24 seconds", &selectTiming, false),
        MenuItem("27 seconds", &selectTiming, false), MenuItem("30 seconds", &selectTiming, false),
        MenuItem("33 seconds", &selectTiming, false), MenuItem("36 seconds", &selectTiming, false),
        MenuItem("39 seconds", &selectTiming, false), MenuItem("42 seconds", &selectTiming, false)};

struct MenuItem *globalMenu = idleMenu; // memory adress of the currently selected menu list.
int menuLength = 1;

void nothing()
{
}

void displayMenu()
{
  menu();
}

void loopMenu()
{
  if (state == TRIGGERED)
  {
    updateSpray.tick();
    builtInSprayDelay.tick();
  }
  if (state != TRIGGERED && state != MENUACTIVE && state != NOTINUSE)
  {
    updateSensorState.tick();
  }
  if (getButton() == 1)
  {
    selectNext();
    delay(500);
    displayMenu();
  }
  if (getButton() == 2)
  {
    delay(500);
    selectItem();
  }
  if (getButton() == 3)
  {
    delay(500);
    spray();
  }
}
