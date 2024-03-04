int buttonsPin = A3;

// 0 == (>800) == none
// 1 == (<100) == arrow down
// 2 == (<600) == arrow right
// 3 == (<700) == spray
// 4 == (<800) == magnet sensor
int getButton() {
    int readValue = analogRead(buttonsPin);

    if (readValue < 100) return 1; // around 0
    if (readValue < 600) return 2; // around 500
    if (readValue < 700) return 3; // around 666
    if (readValue < 800) return 4; // around 750
    return 0; // around 1000
}