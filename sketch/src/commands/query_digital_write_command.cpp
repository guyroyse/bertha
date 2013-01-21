#include "query_digital_write_command.h"

#include "../bertha_buffer.h"
#include "pin_command.h"
#include "../pin.h"

QueryDigitalWriteCommand::QueryDigitalWriteCommand(BerthaBuffer request) : PinCommand(request) {
}

void QueryDigitalWriteCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}

