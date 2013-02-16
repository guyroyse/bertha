#include "pin_mode.h"

PinMode::PinMode() {
  _mode = INPUT;
}

PinMode::PinMode(int mode) {
  set(mode);
}

PinMode::PinMode(char* mode) {
  set(mode);
}

void PinMode::set(int mode) {
  _mode = mode;
}

void PinMode::set(char* mode) {
  set(stringToMode(mode));
}

int PinMode::get() {
  return _mode;
}

char* PinMode::toString() {
  return modeToString(get());
}

char* PinMode::modeToString(int mode) {
  if (mode == INPUT) return "INPUT";
  if (mode == OUTPUT) return "OUTPUT";
  return "PWM";
}

int PinMode::stringToMode(char* modeString) {
  if (!strcmp("INPUT", modeString)) return INPUT;
  return OUTPUT;
}
