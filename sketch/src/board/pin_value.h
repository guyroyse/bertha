#ifndef pin_value_h
#define pin_value_h

#include "arduino.h"

class PinValue {

  int _value;
  
  public:
  
    PinValue();
    PinValue(int);
    PinValue(char*);
    
    void set(int);
    void set(char*);
    
    int get();
    
    char* toString();

  private:
  
    int stringToValue(char*);
    char* valueToString(int);
  
};

#endif
  
    
