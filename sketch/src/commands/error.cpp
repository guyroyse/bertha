#include "error.h"

void ErrorCommand::updateBoard() {
}

void ErrorCommand::buildResponse() {
  this->setErrorStatus();
  this->appendNameAndValue("msg", "'unknown command'");
}
