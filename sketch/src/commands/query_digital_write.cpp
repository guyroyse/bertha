#include "query_digital_write.h"

QueryDigitalWriteCommand::QueryDigitalWriteCommand(BerthaBuffer request) : PinCommand(request) {
}

void QueryDigitalWriteCommand::executeInternal(BerthaBuffer* response) {
  Pin* pin = getPin();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}

