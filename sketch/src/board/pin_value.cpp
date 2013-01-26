#include "pin_value.h"

PinValue::PinValue() {
  _value = LOW;
}

PinValue::PinValue(int value) {
  set(value);
}

PinValue::PinValue(char* value) {
  set(value);
}

void PinValue::set(int value) {
  _value = value;
}

void PinValue::set(char* value) {
  set(stringToValue(value));
}

int PinValue::get() {
  return _value;
}

char* PinValue::toString() {
  return valueToString(get());
}

char* PinValue::valueToString(int value) {
  if (value == HIGH) return "HIGH";
  return "LOW";
}

int PinValue::stringToValue(char* valueString) {
  if (!strcmp("HIGH", valueString)) return HIGH;
  return LOW;
}
