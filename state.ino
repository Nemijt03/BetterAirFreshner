// 0 == not in use
// 1 == in use, number 1
// 2 == in use, number 2
// 3 == in use, cleaning
// 4 == in use, type unknown
// 5 == triggered, spray shot imminent or waiting for spray shot
// 6 == operator menu active -> if end then go to 0

void changeState(byte toWhat) {
    Serial.println(F(""));
    state = toWhat;
    if (toWhat == TRIGGERED) displaySpray();
    led.setColor(coloursPerState[state]);
}

// 3  -> 2   -> 2   -> 1   -> 1  -> 0   -> 0   -> 3
// ON -> 200 -> OFF -> 200 -> ON -> 200 -> OFF -> 1000
byte ledState = 0;
void blinkStateLed() {
    if (ledState % 2 == 0) led.off();
    else led.setColor(coloursPerState[state]);

    if (ledState == 0) {
        updateHeartBeat = Timer(1000, &blinkStateLed);
        ledState = 3;
        return;
    }
    if (ledState == 3) {
        updateHeartBeat = Timer(200, &blinkStateLed);
    }
    ledState--;
}