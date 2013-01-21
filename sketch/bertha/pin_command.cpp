#include "pin_command.h"

#include "buffer.h"
#include "pin.h"
#include "pins.h"

PinCommand::PinCommand(Buffer request) {
  _pin = request.nextInt();
}

Pin* PinCommand::getPin() {
  Pins* pins = Pins::getInstance();
  return pins->getPin(_pin);
};
