#include "pin_command.h"

PinCommand::PinCommand(CommandParser* parser) : Command(parser) {
}

Pin* PinCommand::getPin() {
  int pin = this->getParser()->argumentAsInt("pin");
  return this->getBoard()->getPin(pin);
};
