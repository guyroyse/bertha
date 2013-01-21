#include "set_pin_mode_command.h"

#include "buffer.h"
#include "pin_mode.h"
#include "pins.h"
#include "pin.h"

SetPinModeCommand::SetPinModeCommand(Buffer request) {
  _pin = request.nextInt();
  _mode = PinMode(request.nextToken());
}

void SetPinModeCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  pin->setMode(_mode);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getMode().toString());
}

