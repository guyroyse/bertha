#ifndef query_analog_pin_h
#define query_analog_pin_h

#include "pin_command.h"

class QueryAnalogPinCommand : public Command {

  public:
    QueryAnalogPinCommand(CommandParser*);

    void updateBoard();
    void buildResponse();

  protected:
    AnalogPin* getPin();


};

#endif
