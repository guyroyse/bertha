#include "commands.h"
#include "arduino.h"

Buffer Command::execute() {
  executeInternal(&response);
  return response;
}

void VersionCommand::executeInternal(Buffer* response) {
  response->append("v1.0.0");
}

PinModeCommand::PinModeCommand(Buffer request) {
  pin = request.nextInt();
  mode = PinMode(request.nextToken());
}

void PinModeCommand::executeInternal(Buffer* response) {
  pinMode(pin, mode.getMode());
  response->append("OK: pin ")->append(pin)->append(" set to ")->append(mode.toString());
}

DigitalWriteCommand::DigitalWriteCommand(Buffer request) {
  pin = request.nextInt();
  value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(Buffer* response) {
  digitalWrite(pin, value);
  response->append("OK: pin ")->append(pin)->append(" set to ")->append(value);
}

void ErrorCommand::executeInternal(Buffer* response) {
  response->append("ERR: unknown command");
}

Command* CommandFactory::createCommand(Buffer request) {
  char* verb = request.firstToken();
  if (!strcmp("version", verb)) return new VersionCommand();
  if (!strcmp("pinMode", verb)) return new PinModeCommand(request);
  if (!strcmp("digitalWrite", verb)) return new DigitalWriteCommand(request);
  return new ErrorCommand();
}
