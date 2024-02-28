#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
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

MenuItem confirmReset[2] = {MenuItem("OK", &resetShots, true), MenuItem("CANCEL", &toSelectorMenu, false)};
MenuItem selectorMenu[3] = 
  {MenuItem("Reset shots", &resetShotsConfirm, false), MenuItem("OP2", &nothing, false), MenuItem("Option 3", &nothing, true)};

struct MenuItem *globalMenu = selectorMenu; // het memory adress van het currently selected menu lijst.
int menuLength;


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
    delay(1000);
    displayMenu();
  }
  if(digitalRead(A1) == LOW){
    selectItem();
  }
}