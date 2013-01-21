#include "set_pin_mode.h"

#include "../bertha_buffer.h"
#include "pin_command.h"
#include "../pin_mode.h"
#include "../pin.h"

SetPinModeCommand::SetPinModeCommand(BerthaBuffer request) : PinCommand(request) {
  _mode = PinMode(request.nextToken());
}

void SetPinModeCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  pin->setMode(_mode);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getMode().toString());
}

