void resetShotsConfirm() {
    lcd.clear();
    lcd.home();
    lcd.print(F("Reset shots?"));
    Serial.println("hier");
    globalMenu = confirmReset;
    menuLength = 2;
    menu();
}

void resetShots() {
    resetRemainingShots();
    toIdle();
}
