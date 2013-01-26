#include "error.h"

ErrorCommand::ErrorCommand(CommandParser* parser) : Command(parser) {
}

void ErrorCommand::updateBoard() {
}

void ErrorCommand::buildResponse() {
  this->setErrorStatus();
  this->appendNameAndValue("msg", "'unknown command'");
}
