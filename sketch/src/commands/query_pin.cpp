#include "query_pin.h"

QueryPinCommand::QueryPinCommand(BerthaBuffer request) {
  char* name = request.nextName();
  char* value = request.nextValue();
  _pin = atoi(value);
}

void QueryPinCommand::executeInternal(BerthaBuffer* response) {
  Board* board = Board::getInstance();
  Pin* pin = board->getPin(_pin);
  PinMode mode = pin->getMode();
  response->append("OK");
}
