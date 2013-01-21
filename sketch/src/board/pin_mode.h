#ifndef pin_mode_h
#define pin_mode_h

#include "arduino.h"

class PinMode {

  int _mode;
  
  public:
  
    PinMode();
    PinMode(int);
    PinMode(char*);
    
    void setMode(int);
    void setMode(char*);
    
    int getMode();
    
    char* toString();
  
  private:
  
    int stringToMode(char*);
    char* modeToString(int mode);
  
};

#endif
  
    
