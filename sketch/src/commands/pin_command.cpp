#include "pin_command.h"

PinCommand::PinCommand(CommandParser* parser) : Command() {
  _parser = parser;
  _pin = _parser->argumentAsInt("pin");
}

PinCommand::~PinCommand() {
  delete _parser;
}

Pin* PinCommand::getPin() {
  return this->getBoard()->getPin(_pin);
};
