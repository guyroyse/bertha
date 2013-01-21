#ifndef pin_h
#define pin_h

#include "pin_mode.h"

class Pin {

  int _pin, _value;
  PinMode _mode;
  
  public:    
    Pin(int);
    
    int getPin();
    PinMode getMode();
    int getValue();
  
    void setValue(int); 
    void setMode(PinMode);
  
};

#endif
