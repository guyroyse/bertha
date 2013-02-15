#ifndef analog_pin_h
#define analog_pin_h

#include "pin.h"
#include "Arduino.h"

class AnalogPin : public Pin {

  int _pin;

  public:
    AnalogPin(int);

    int getValue();
};

#endif
