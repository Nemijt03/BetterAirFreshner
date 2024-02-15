class Timer {
  public:
    void (*func)(float f);
    float (*args)();
    unsigned long activationTime;
    unsigned long intervalTime;

    Timer(unsigned long interval, unsigned long currentMillis, void (*inputFunc)(float inputF), float (*inputArgs)()) {
      activationTime = interval + currentMillis;
      intervalTime = interval;
      func = inputFunc;
      args = inputArgs;
    };
    
    bool isTime(unsigned long currentMillis) {
      return activationTime <= currentMillis;
    };

    void reset(unsigned long currentMillis) {
      activationTime = currentMillis + intervalTime;
    }

    void update(unsigned long currentMillis) {
      if (isTime(currentMillis)) {
        func(args());
        reset(currentMillis);
      }
    }
};
