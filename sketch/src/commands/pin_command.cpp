#include "pin_command.h"

PinCommand::PinCommand(BerthaBuffer request) {
  _pin = request.nextInt();
}

Pin* PinCommand::getPin() {
  Board* board = Board::getInstance();
  return board->getPin(_pin);
};
