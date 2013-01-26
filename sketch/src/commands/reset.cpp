#include "reset.h"

void ResetCommand::updateBoard() {
  this->getBoard()->reset();
}

void ResetCommand::buildResponse() {
  this->setOkStatus();
}
