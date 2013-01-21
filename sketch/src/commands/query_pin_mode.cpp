#include "query_pin_mode.h"

QueryPinModeCommand::QueryPinModeCommand(BerthaBuffer request) : PinCommand(request) {
}

void QueryPinModeCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  PinMode mode = pin->getMode();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(mode.toString());
}
