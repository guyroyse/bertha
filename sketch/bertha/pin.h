#ifndef pin_h
#define pin_h

#include "pin_mode.h"

class Pin {

  int _pin, _value;
  PinMode _mode;
  
  public:    
    Pin() {};
    
    int getPin() { return _pin; };
    int getValue() { return _value; };
    PinMode getMode() { return _mode; };
  
    void setPin(int pin) { _pin = pin; };
    void setValue(int value) { _value = value; };
    void setMode(PinMode mode) { _mode = mode; };
  
};

#endif
  
    
