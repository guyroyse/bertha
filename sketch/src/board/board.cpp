#include "board.h"

Board* Board::_instance = 0;

Board::Board() {
  for (int pin = 0; pin < PIN_COUNT; pin++)
    _pins[pin] = new Pin(pin);
}

Board::~Board() {
  for (int pin = 0; pin < PIN_COUNT; pin++)
    delete _pins[pin];
  delete _instance;
}

Board* Board::getInstance() {
  if (!_instance) _instance = new Board();
  return _instance;
}

Pin* Board::getPin(int pin) {
  return _pins[pin];
}

void Board::reset() {
  for (int pin = 0; pin < PIN_COUNT; pin++) {
    getPin(pin)->reset();
  }
}
