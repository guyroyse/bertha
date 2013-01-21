#ifndef pins_h
#define pins_h

#include "pin.h"

class Board {

  static Board* _instance;
  Pin* _pins[13];  

  public:
    Pin* getPin(int);

    static Board* getInstance();

  private:
    Board();
    ~Board();
  
};

#endif
