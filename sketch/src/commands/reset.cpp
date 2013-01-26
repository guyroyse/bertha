#include "reset.h"

ResetCommand::ResetCommand(CommandParser* parser) : Command(parser) {
}

void ResetCommand::updateBoard() {
  this->getBoard()->reset();
}

void ResetCommand::buildResponse() {
  this->setOkStatus();
}
