#include "digital_write_command.h"

#include "buffer.h"
#include "pins.h"
#include "pin.h"

DigitalWriteCommand::DigitalWriteCommand(Buffer request) {
  _pin = request.nextInt();
  _value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  pin->setValue(_value);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}
