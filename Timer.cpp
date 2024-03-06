#include <Arduino.h>


class Timer {
  public:
    void (*func)();
    unsigned long activationTime;
    unsigned long intervalTime;
    unsigned long prevMillis = 0;
    
    Timer(unsigned long interval, void (*inputFunc)()) {
      activationTime = millis(); //currentmillis
      intervalTime = interval;
      func = inputFunc;
    };
    
    bool isTime() {
      return activationTime - prevMillis >= intervalTime;
    };

    void reset() {
      prevMillis = activationTime;
    }

    void tick() {
      if (isTime()) {
        reset();
        func();
      }
    }
};
