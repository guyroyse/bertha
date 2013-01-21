#include "query_pin_mode_command.h"

#include "bertha_buffer.h"
#include "pin_command.h"
#include "pin.h"
#include "pin_mode.h"

QueryPinModeCommand::QueryPinModeCommand(BerthaBuffer request) : PinCommand(request) {
}

void QueryPinModeCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  PinMode mode = pin->getMode();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(mode.toString());
}
