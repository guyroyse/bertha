#include "digital_read.h"

#include "pin_command.h"

DigitalReadCommand::DigitalReadCommand(BerthaBuffer request) : PinCommand(request) {
}

void DigitalReadCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  response->append("OK: pin ")->append(pin->getPin())->append(" is ")->append(pin->getValue());
}
