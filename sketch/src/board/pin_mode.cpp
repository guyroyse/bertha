#include "pin_mode.h"
#include "arduino.h"

PinMode::PinMode() {
  _mode = OUTPUT;
}

PinMode::PinMode(int mode) {
  setMode(mode);
}

PinMode::PinMode(char* mode) {
  setMode(mode);
}

void PinMode::setMode(int mode) {
  _mode = mode;
}

void PinMode::setMode(char* mode) {
  setMode(stringToMode(mode));
}

int PinMode::getMode() {
  return _mode;
}

char* PinMode::toString() {
  return modeToString(getMode());
}

char* PinMode::modeToString(int mode) {
  if (mode == INPUT_PULLUP) return "PULLUP";
  if (mode == INPUT) return "INPUT";
  if (mode == OUTPUT) return "OUTPUT";
}

int PinMode::stringToMode(char* modeString) {
  if (!strcmp("PULLUP", modeString)) return INPUT_PULLUP;
  if (!strcmp("INPUT", modeString)) return INPUT;
  if (!strcmp("OUTPUT", modeString)) return OUTPUT;
}
