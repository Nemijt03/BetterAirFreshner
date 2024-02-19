#include <Arduino.h>

class Timer {
  public:
    void (*func)();
    unsigned long activationTime;
    unsigned long intervalTime;

    Timer(unsigned long interval, void (*inputFunc)()) {
      activationTime = interval + millis();
      intervalTime = interval;
      func = inputFunc;
    };
    
    bool isTime() {
      return activationTime <= millis();
    };

    void reset() {
      activationTime = millis() + intervalTime;
    }

    void tick() {
      if (isTime()) {
        func();
        reset();
      }
    }
};
