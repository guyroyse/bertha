#include "board.h"

Board* Board::_instance = 0;

Board::Board() {
  for (int i = 0; i < 13; i++)
    _pins[i] = new Pin(i + 1);
}

Board::~Board() {
  for (int i = 0; i < 13; i++)
    delete _pins[i];
  delete _instance;
}
    
Board* Board::getInstance() {
  if (!_instance) _instance = new Board();
  return _instance;
}

Pin* Board::getPin(int pin) {
  return _pins[pin - 1];
}
