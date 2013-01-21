#include "pin.h"

Pin::Pin(int pin) {
  _pin = pin;
}

int Pin::getPin() {
  return _pin; 
}

PinMode Pin::getMode() {
  return _mode;
}

int Pin::getValue() {
  return _value;
}

void Pin::setMode(PinMode mode) { 
  _mode = mode;
  pinMode(_pin, _mode.getMode());
}

void Pin::setValue(int value) { 
  _value = value;
  digitalWrite(_pin, _value);
}
