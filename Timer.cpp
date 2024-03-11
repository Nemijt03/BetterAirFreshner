#include <Arduino.h>

class Timer
{
public:
  void (*func)();
  unsigned long activationTime;
  unsigned long intervalTime;
  unsigned long prevMillis = 0;

  Timer(unsigned long interval, void (*inputFunc)())
  {
    activationTime = millis() + interval;
    intervalTime = interval;
    func = inputFunc;
  };

  bool isTime()
  {
    return activationTime <= millis();
  }

  void reset()
  {
    activationTime = millis() + intervalTime;
  }

  void tick()
  {
    if (isTime())
    {
      reset();
      func();
    }
  }
};
