#ifndef pins_h
#define pins_h

#include "pin.h"

class Pins {

  static Pins* _instance;
  Pin* _pins[13];  

  public:
    Pin* getPin(int);

    static Pins* getInstance();

  private:
    Pins();
    ~Pins();
  
};

#endif
