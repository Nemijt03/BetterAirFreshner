byte sensorState = 0;

// int sensor = 0 -> sitting sensor (distance)
// int sensor = 1 -> time 
// int sensor = 2 -> toilet paper (magnet)
// int state = 0 (false), 1 (true), 2 (long)
void updateSensors(int sensor, int state) {
    sensorState |= state << sensor;
}

void resetSensors() {
    sensorState = 0;
}

int getSensorState(int sensor) {
    if (sensor == 2) return sensorState >> 2;

    int mask = sensor + 1;
    return (sensorState & mask) == mask;
}

// state = 3 -> in use, cleaning
// state = 1 -> in use, number 1
// state = 2 -> in use, number 2
int getStateFromSensors() {

    Serial.print("Sensorstate: ");
    Serial.println(sensorState);
    Serial.print("getsensor 1: ");
    Serial.println(getSensorState(1));
    if (sensorState > 8 || (sensorState > 4 && sensorState < 8 && getSensorState(1))) return NR2;
    if (sensorState < 4 && getSensorState(1)) return CLEANING;
    return NR1;
    // no toilet paper, no sitting, long time.
}

void sensorStateUpdate() {
    Serial.println(F("sensorStateUpdate"));

    Serial.println(sit());
    updateSensors(0, sit());
    Serial.println(timeOnToilet());
    updateSensors(1, timeOnToilet());
    Serial.println(toiletPaper());
    updateSensors(2, toiletPaper());
    Serial.println(F("sit, timeontoilet, toiletpaper"));

    int getS = getStateFromSensors();
    changeState(getS);

}