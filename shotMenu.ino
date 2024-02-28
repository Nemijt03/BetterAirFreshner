
void resetShotsConfirm() {
    lcd.home();
    lcd.println(F("Reset shots?"));
    globalMenu = confirmReset;
    menu();
}

void resetShots() {
    remainingShots = 2400;
    toSelectorMenu();
}
