#include "digital_pin.h"

DigitalPin::DigitalPin(int pin) : Pin(pin) {
  this->setMode("INPUT");
}

char* DigitalPin::getMode() {
  if (_pwm) return "PWM";
  return _mode.toString();
}

PinValue DigitalPin::getValue() {
  if (_pwm) return _value;
  if (_mode.get() == OUTPUT) return _value;
  int value = digitalRead(this->getPin());
  return PinValue(value);
}

void DigitalPin::setMode(char* mode) {
  if (!strcmp("PWM", mode)) {
    _pwm = true;
  } else {
    _pwm = false;
    _mode = PinMode(mode);
    pinMode(this->getPin(), _mode.get());
  }

}

void DigitalPin::setValue(PinValue value) {
  _value = value;
  if (_pwm) {
    analogWrite(this->getPin(), _value.get());
  } else {
    digitalWrite(this->getPin(), _value.get());
  }
}

void DigitalPin::reset() {
  this->setMode("INPUT");
  this->setValue(PinValue(LOW));
}
