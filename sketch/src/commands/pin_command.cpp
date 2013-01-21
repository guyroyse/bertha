#include "pin_command.h"

#include "../bertha_buffer.h"
#include "../board/board.h"

PinCommand::PinCommand(BerthaBuffer request) {
  _pin = request.nextInt();
}

Pin* PinCommand::getPin() {
  Board* board = Board::getInstance();
  return board->getPin(_pin);
};
