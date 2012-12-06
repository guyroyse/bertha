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
  pin.setPin(request.nextInt());
  pin.setMode(PinMode(request.nextToken()));
}

void PinModeCommand::executeInternal(Buffer* response) {
  pinMode(pin.getPin(), pin.getMode().getMode());
  response->append("OK: pin ")->append(pin.getPin())->append(" set to ")->append(pin.getMode().toString());
}

DigitalWriteCommand::DigitalWriteCommand(Buffer request) {
  pin.setPin(request.nextInt());
  pin.setValue(request.nextInt());
}

void DigitalWriteCommand::executeInternal(Buffer* response) {
  digitalWrite(pin.getPin(), pin.getValue());
  response->append("OK: pin ")->append(pin.getPin())->append(" set to ")->append(pin.getValue());
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
