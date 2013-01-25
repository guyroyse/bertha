#include "factory.h"

Command* CommandFactory::createCommand(BerthaBuffer request) {
  char* verb = request.parseVerb();
  if (!strcmp("version", verb)) return new VersionCommand();
  if (!strcmp("queryPin", verb)) return new QueryPinCommand(request);
  if (!strcmp("setPinMode", verb)) return new SetPinModeCommand(request);
  if (!strcmp("queryPinMode", verb)) return new QueryPinModeCommand(request);
  if (!strcmp("digitalWrite", verb)) return new DigitalWriteCommand(request);
  if (!strcmp("queryDigitalWrite", verb)) return new QueryDigitalWriteCommand(request);
  if (!strcmp("digitalRead", verb)) return new DigitalReadCommand(request);
  return new ErrorCommand();
}
