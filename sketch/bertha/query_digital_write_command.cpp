#include "query_digital_write_command.h"

#include "buffer.h"
#include "pin_command.h"
#include "pin.h"

QueryDigitalWriteCommand::QueryDigitalWriteCommand(Buffer request) : PinCommand(request) {
}

void QueryDigitalWriteCommand::executeInternal(Buffer* response) {
  Pin* pin = getPin();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}

