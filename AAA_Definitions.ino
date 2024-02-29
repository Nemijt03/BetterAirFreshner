#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int remainingShots = 2400; // maximum amount of shots

byte degree[] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};

struct MenuItem
{
  String name;
  void (*func)();
  bool selected;

  MenuItem(String Name, void (*Func)(), bool Selected) {
    name = Name;
    func = Func;
    selected = Selected;
  }
};

MenuItem idleMenu[1] = {MenuItem("To settings", &toSelectorMenu, true)};
MenuItem confirmReset[2] = {MenuItem("OK", &resetShots, true), MenuItem("CANCEL", &toIdle, false)};
MenuItem selectorMenu[3] = 
  {MenuItem("Reset shots", &resetShotsConfirm, false), MenuItem("Timing options", &toWhenSprayMenu, false), MenuItem("Back to idle", &toIdle, true)};
MenuItem whenSprayMenu[2] = {MenuItem("When entering", &selectSprayAtEnter, true), MenuItem("When exiting", &selectSprayAtExit, false)};
MenuItem timingMenu[10] = 
{
  MenuItem("15 seconds", &selectTiming, true),  MenuItem("18 seconds", &selectTiming, false), 
  MenuItem("21 seconds", &selectTiming, false), MenuItem("24 seconds", &selectTiming, false), 
  MenuItem("27 seconds", &selectTiming, false), MenuItem("30 seconds", &selectTiming, false), 
  MenuItem("33 seconds", &selectTiming, false), MenuItem("36 seconds", &selectTiming, false), 
  MenuItem("39 seconds", &selectTiming, false), MenuItem("42 seconds", &selectTiming, false)
};

struct MenuItem *globalMenu = selectorMenu; // het memory adress van het currently selected menu lijst.
int menuLength = 3;


void nothing() {

}

void menuTesting() {
  menu();
}

void displayMenu() {
  menu();
}

void loopMenu() {
  if (digitalRead(A3) == LOW) {
    selectNext();
    delay(500);
    displayMenu();
  }
  if(digitalRead(A1) == LOW){
    delay(500);
    selectItem();
  }
}