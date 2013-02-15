#ifndef board_h
#define board_h

#include "pins.h"

#define PIN_COUNT (NUM_DIGITAL_PINS - NUM_ANALOG_INPUTS)
#define ANALOG_PIN_COUNT NUM_ANALOG_INPUTS

class Board {

  static Board* _instance;
  DigitalPin* _digitalPins[PIN_COUNT];
  AnalogPin* _analogPins[ANALOG_PIN_COUNT];

  public:
    DigitalPin* getDigitalPin(int);
    AnalogPin* getAnalogPin(int);
    void reset();

    static Board* getInstance();

  private:
    Board();
    ~Board();
  
};

#endif
