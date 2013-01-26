#include "set_pin.h"

SetPinCommand::SetPinCommand(CommandParser* parser) : PinCommand(parser) {
  _mode = parser->argument("mode");
  _value = parser->argument("value");
}

void SetPinCommand::updateBoard() {
  Pin* pin = this->getPin();
  if (_mode) pin->setMode(PinMode(_mode));
  if (_value) pin->setValue(PinValue(_value));
}

void SetPinCommand::buildResponse() {
  Pin* pin = this->getPin();
  this->setOkStatus();
  this->appendNameAndValue("pin", pin->getPin());
  this->appendNameAndValue("mode", pin->getMode().toString());
  this->appendNameAndValue("value", pin->getValue().toString());
}
