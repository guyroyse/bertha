#include "command.h"

Command::Command() {
  _board = Board::getInstance();
}

Board* Command::getBoard() {
  return _board;
}

BerthaBuffer Command::execute() {
  updateBoard();
  buildResponse();
  return _response;
}

void Command::setOkStatus() {
  this->setStatus("OK");
}

void Command::setErrorStatus() {
  this->setStatus("ERR");
}

void Command::appendNameAndValue(char* name, char* value) {
  this->appendName(name);
  _response.append(value);
}

void Command::appendNameAndValue(char* name, int value) {
  this->appendName(name);
  _response.append(value);
}

void Command::setStatus(char* status) {
  _response.append(status);
}

void Command::appendName(char* name) {
  _response.append(" ");
  _response.append(name);
  _response.append("=");
}

void Command::appendValue(char* value) {
  _response.append(value);
}
