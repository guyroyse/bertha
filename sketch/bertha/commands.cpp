#include "commands.h"

Buffer Command::execute() {
  executeInternal(&response);
  return response;
}

void VersionCommand::executeInternal(Buffer* response) {
  response->append("v1.0.0");
}

SetPinModeCommand::SetPinModeCommand(Buffer request) {
  _pin = request.nextInt();
  _mode = PinMode(request.nextToken());
}

void SetPinModeCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  pin->setMode(_mode);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getMode().toString());
}

QueryPinModeCommand::QueryPinModeCommand(Buffer request) {
  _pin = request.nextInt();
}

void QueryPinModeCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  PinMode mode = pin->getMode();
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(mode.toString());
}

DigitalWriteCommand::DigitalWriteCommand(Buffer request) {
  _pin = request.nextInt();
  _value = request.nextInt();
}

void DigitalWriteCommand::executeInternal(Buffer* response) {
  Pins* pins = Pins::getInstance();
  Pin* pin = pins->getPin(_pin);
  pin->setValue(_value);
  response->append("OK: pin ")->append(pin->getPin())->append(" set to ")->append(pin->getValue());
}

void ErrorCommand::executeInternal(Buffer* response) {
  response->append("ERR: unknown command");
}

Command* CommandFactory::createCommand(Buffer request) {
  char* verb = request.firstToken();
  if (!strcmp("version", verb)) return new VersionCommand();
  if (!strcmp("setPinMode", verb)) return new SetPinModeCommand(request);
  if (!strcmp("queryPinMode", verb)) return new QueryPinModeCommand(request);
  if (!strcmp("digitalWrite", verb)) return new DigitalWriteCommand(request);
  return new ErrorCommand();
}
