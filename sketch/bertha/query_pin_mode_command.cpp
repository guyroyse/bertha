#include "query_pin_mode_command.h"

#include "buffer.h"
#include "pin_command.h"
#include "pin.h"
#include "pin_mode.h"

QueryPinModeCommand::QueryPinModeCommand(Buffer request) : PinCommand(request) {
}

void QueryPinModeCommand::executeInternal(Buffer* response) {
  Pin* pin = getPin();
  PinMode mode = pin->getMode();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(mode.toString());
}
