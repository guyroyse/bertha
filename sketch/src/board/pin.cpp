#include "pin.h"

Pin::Pin(int pin) {
  _pin = pin;
}

int Pin::getPin() {
  return _pin; 
}
