#include "query_analog_pin.h"

QueryAnalogPinCommand::QueryAnalogPinCommand(CommandParser* parser) : Command(parser) {
}

void QueryAnalogPinCommand::updateBoard() {
}

void QueryAnalogPinCommand::buildResponse() {
  AnalogPin* pin = this->getPin();
  this->setOkStatus();
  this->appendNameAndValue("pin", pin->getPin());
  this->appendNameAndValue("value", pin->getValue());
}

AnalogPin* QueryAnalogPinCommand::getPin() {
  int pin = this->getParser()->argumentAsInt("pin");
  return this->getBoard()->getAnalogPin(pin);
};
