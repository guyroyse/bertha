#include "analog_pin.h"

AnalogPin::AnalogPin(int pin) : Pin(pin) {
}

int AnalogPin::getValue() {
  int pin = this->getPin();
  return analogRead(pin);
}
