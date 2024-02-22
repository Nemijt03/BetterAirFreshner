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

// state = 1 -> in use, number 1
// state = 2 -> in use, number 2
// state = 3 -> in use, cleaning
int getStateFromSensors() {
    if (sensorState > 8) return 2; // much toilet paper
    if (sensorState == 2) return 3; // no toilet paper, no sitting, long time.
    // if (getSensorState(1) == 0 && getSensorState(2) != 2) return 1;
    return 1;
}