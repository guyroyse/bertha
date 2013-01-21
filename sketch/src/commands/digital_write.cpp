#include "digital_write.h"

#include "pin_command.h"

DigitalWriteCommand::DigitalWriteCommand(BerthaBuffer request) : PinCommand(request) {
  _value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  pin->setValue(_value);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}
