#include "digital_write.h"

#include "../bertha_buffer.h"
#include "pin_command.h"
#include "../board/pin.h"

DigitalWriteCommand::DigitalWriteCommand(BerthaBuffer request) : PinCommand(request) {
  _value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  pin->setValue(_value);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}
