#include "query_pin.h"

QueryPinCommand::QueryPinCommand(CommandParser* parser) : PinCommand(parser) {
}

void QueryPinCommand::updateBoard() {
}

void QueryPinCommand::buildResponse() {
  DigitalPin* pin = this->getPin();
  this->setOkStatus();
  this->appendNameAndValue("pin", pin->getPin());
  this->appendNameAndValue("mode", pin->getMode().toString());
  this->appendNameAndValue("value", pin->getValue().get());
}
