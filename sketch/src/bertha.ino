#include "arduino.h"

#include "io/bertha_io.h"
#include "io/bertha_buffer.h"
#include "commands/command.h"
#include "commands/factory.h"

BerthaIO* io;

void setup() {
  io = new BerthaIO();
}

void loop() {

  BerthaBuffer request = io->nextRequest();

  Command* command = CommandFactory::createCommand(request);
  BerthaBuffer response = command->execute();
  delete command;

  io->send(response);
  io->reset();

}
