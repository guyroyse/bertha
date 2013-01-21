#include "set_pin_mode.h"

#include "../bertha_buffer.h"
#include "pin_command.h"
#include "../board/pin_mode.h"
#include "../board/pin.h"

SetPinModeCommand::SetPinModeCommand(BerthaBuffer request) : PinCommand(request) {
  _mode = PinMode(request.nextToken());
}

void SetPinModeCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  pin->setMode(_mode);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getMode().toString());
}

