#include "arduino.h"
#include "bertha_io.h"
#include "commands.h"

BerthaIO* io;

void setup() {
  io = new BerthaIO();
}

void loop() {
  Buffer request = io->nextRequest();
  Buffer response = processRequest(request);
  io->send(response);
  io->reset();
}

Buffer processRequest(Buffer request) {
  Command* command = CommandFactory::createCommand(request);
  Buffer response = command->execute();
  delete command;
  return response;
}
