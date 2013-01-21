#include "arduino.h"

#include "bertha_io.h"
#include "bertha_buffer.h"
#include "command.h"
#include "command_factory.h"

BerthaIO* io;

void setup() {
  io = new BerthaIO();
}

void loop() {
  BerthaBuffer request = io->nextRequest();
  BerthaBuffer response = processRequest(request);
  io->send(response);
  io->reset();
}

BerthaBuffer processRequest(BerthaBuffer request) {
  Command* command = CommandFactory::createCommand(request);
  BerthaBuffer response = command->execute();
  delete command;
  return response;
}
