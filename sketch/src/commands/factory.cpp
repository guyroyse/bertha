#include "factory.h"

#include "../bertha_buffer.h"

#include "version.h"
#include "set_pin_mode.h"
#include "query_pin_mode.h"
#include "digital_write.h"
#include "query_digital_write.h"
#include "error.h"

Command* CommandFactory::createCommand(BerthaBuffer request) {
  char* verb = request.firstToken();
  if (!strcmp("version", verb)) return new VersionCommand();
  if (!strcmp("setPinMode", verb)) return new SetPinModeCommand(request);
  if (!strcmp("queryPinMode", verb)) return new QueryPinModeCommand(request);
  if (!strcmp("digitalWrite", verb)) return new DigitalWriteCommand(request);
  if (!strcmp("queryDigitalWrite", verb)) return new QueryDigitalWriteCommand(request);
  return new ErrorCommand();
}
