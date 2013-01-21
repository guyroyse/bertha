#include "digital_write_command.h"

#include "buffer.h"
#include "pin_command.h"
#include "pin.h"

DigitalWriteCommand::DigitalWriteCommand(Buffer request) : PinCommand(request) {
  _value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(Buffer* response) {
  Pin* pin = getPin();
  pin->setValue(_value);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}
