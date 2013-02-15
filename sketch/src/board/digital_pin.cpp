#include "digital_pin.h"

DigitalPin::DigitalPin(int pin) : Pin(pin) {
}

PinMode DigitalPin::getMode() {
  return _mode;
}

PinValue DigitalPin::getValue() {
  if (_mode.get() == OUTPUT) return _value;
  int value = digitalRead(this->getPin());
  return PinValue(value);
}

void DigitalPin::setMode(PinMode mode) {
  _mode = mode;
  pinMode(this->getPin(), _mode.get());
}

void DigitalPin::setValue(PinValue value) {
  _value = value;
  digitalWrite(this->getPin(), _value.get());
}

void DigitalPin::reset() {
  this->setMode(PinMode(INPUT));
  this->setValue(PinValue(LOW));
}
