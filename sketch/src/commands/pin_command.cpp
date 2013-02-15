#include "pin_command.h"

PinCommand::PinCommand(CommandParser* parser) : Command(parser) {
}

DigitalPin* PinCommand::getPin() {
  int pin = this->getParser()->argumentAsInt("pin");
  return this->getBoard()->getDigitalPin(pin);
};
