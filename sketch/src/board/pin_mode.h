#ifndef pin_mode_h
#define pin_mode_h

#include "Arduino.h"

class PinMode {

  int _mode;
  
  public:
  
    PinMode();
    PinMode(int);
    PinMode(char*);
    
    void set(int);
    void set(char*);
    
    int get();
    
    char* toString();

  private:
  
    int stringToMode(char*);
    char* modeToString(int);
  
};

#endif
  
    
