#include "pin_command.h"

#include "../bertha_buffer.h"
#include "../pin.h"
#include "../pins.h"

PinCommand::PinCommand(BerthaBuffer request) {
  _pin = request.nextInt();
}

Pin* PinCommand::getPin() {
  Pins* pins = Pins::getInstance();
  return pins->getPin(_pin);
};
