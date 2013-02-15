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

PinValue Pin::getValue() {
  if (_mode.get() == INPUT)
    return PinValue(digitalRead(_pin));
  return _value;
}

void Pin::setMode(PinMode mode) {
  _mode = mode;
  pinMode(_pin, _mode.get());
}

void Pin::setValue(PinValue value) {
  _value = value;
  digitalWrite(_pin, _value.get());
}

void Pin::reset() {
  this->setMode(PinMode(INPUT));
  this->setValue(PinValue(LOW));
}

AnalogPin::AnalogPin(int pin) {
  _pin = pin;
}

int AnalogPin::getPin() {
  return _pin;
}

int AnalogPin::getValue() {
  return analogRead(_pin);
}
