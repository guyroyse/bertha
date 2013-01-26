#ifndef pin_h
#define pin_h

#include "Arduino.h"
#include "pin_mode.h"
#include "pin_value.h"

class Pin {

  int _pin;
  PinMode _mode;
  PinValue _value;
  
  public:    
    Pin(int);
    
    int getPin();
    PinMode getMode();
    PinValue getValue();
  
    void setValue(PinValue);
    void setMode(PinMode);

    void reset();
};

#endif
