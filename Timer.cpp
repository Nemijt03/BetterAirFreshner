#include <Arduino.h>


class Timer {
  public:
    void (*func)();
    unsigned long activationTime;
    unsigned long intervalTime;
    unsigned long prevMillis = 0;
    
    Timer(unsigned long interval, void (*inputFunc)()) {
      activationTime = millis() + interval; //millis(); //millis() + interval
      intervalTime = interval;
      func = inputFunc;
    };
    
    bool isTime() {
      return activationTime <= millis();//activationTime - prevMillis >= intervalTime; //activationTime <= millis();
    }

    void reset() {
      activationTime = millis() + intervalTime;  //prevMillis = activationTime; //activationTime = millis();
    }

    void tick() {
      if (isTime()) {
        reset();
        func();
      }
    }
};
