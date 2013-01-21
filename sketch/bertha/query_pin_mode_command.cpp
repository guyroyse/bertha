#include "query_pin_mode_command.h"

#include "buffer.h"
#include "pins.h"
#include "pin.h"
#include "pin_mode.h"

QueryPinModeCommand::QueryPinModeCommand(Buffer request) {
  _pin = request.nextInt();
}

void QueryPinModeCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  PinMode mode = pin->getMode();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(mode.toString());
}

