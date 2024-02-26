
void resetShotsConfirm() {
    lcd.home();
    lcd.println(F("Reset shots?"));
    globalMenu = &confirmReset;
    menu(*globalMenu, 2);
}

void resetShots() {
    remainingShots = 2400;
    toIdleMenu();
}
