#include "version.h"

VersionCommand::VersionCommand(CommandParser* parser) : Command(parser) {
}

void VersionCommand::updateBoard() {
}

void VersionCommand::buildResponse() {
  this->setOkStatus();
  this->appendNameAndValue("version", "1.0.0");
}
