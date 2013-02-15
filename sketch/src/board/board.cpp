#include "board.h"

Board* Board::_instance = 0;

Board::Board() {
  int pin;
  for (pin = 0; pin < PIN_COUNT; pin++)
    _digitalPins[pin] = new DigitalPin(pin);
  for (pin = 0; pin < ANALOG_PIN_COUNT; pin++)
    _analogPins[pin] = new AnalogPin(pin);
}

Board::~Board() {
  for (int pin = 0; pin < PIN_COUNT; pin++)
    delete _digitalPins[pin];
  for (int pin = 0; pin < ANALOG_PIN_COUNT; pin++)
    delete _analogPins[pin];
  delete _instance;
}

Board* Board::getInstance() {
  if (!_instance) _instance = new Board();
  return _instance;
}

DigitalPin* Board::getDigitalPin(int pin) {
  return _digitalPins[pin];
}

AnalogPin* Board::getAnalogPin(int pin) {
  return _analogPins[pin];
}

void Board::reset() {
  for (int pin = 0; pin < PIN_COUNT; pin++) {
    this->getDigitalPin(pin)->reset();
  }
}
