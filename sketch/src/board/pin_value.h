#ifndef pin_value_h
#define pin_value_h

#include "Arduino.h"

class PinValue {

  int _value;
  
  public:
  
    PinValue();
    PinValue(int);
    PinValue(char*);
    
    void set(int);
    void set(char*);
    
    int get();
    
  private:
  
    int stringToValue(char*);
  
};

#endif
  
    
