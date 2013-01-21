#include "set_pin_mode.h"

SetPinModeCommand::SetPinModeCommand(BerthaBuffer request) : PinCommand(request) {
  _mode = PinMode(request.nextToken());
}

void SetPinModeCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  pin->setMode(_mode);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getMode().toString());
}

