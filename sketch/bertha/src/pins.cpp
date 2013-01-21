#include "pins.h"

Pins* Pins::_instance = 0;

Pins::Pins() {
  for (int i = 0; i < 13; i++)
    _pins[i] = new Pin(i + 1);
}

Pins::~Pins() {
  for (int i = 0; i < 13; i++)
    delete _pins[i];
  delete _instance;
}
    
Pins* Pins::getInstance() {
  if (!_instance) _instance = new Pins();
  return _instance;
}

Pin* Pins::getPin(int pin) {
  return _pins[pin - 1];
}
