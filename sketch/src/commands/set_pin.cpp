#include "set_pin.h"

SetPinCommand::SetPinCommand(CommandParser* parser) : PinCommand(parser) {
}

void SetPinCommand::updateBoard() {

  CommandParser* parser = this->getParser();
  char* mode = parser->argument("mode");
  char* value = parser->argument("value");

  DigitalPin* pin = this->getPin();
  if (mode) pin->setMode(PinMode(mode));
  if (value) pin->setValue(PinValue(value));
}

void SetPinCommand::buildResponse() {
  DigitalPin* pin = this->getPin();
  this->setOkStatus();
  this->appendNameAndValue("pin", pin->getPin());
  this->appendNameAndValue("mode", pin->getMode().toString());
  this->appendNameAndValue("value", pin->getValue().toString());
}
