#ifndef query_pin_command_h
#define query_pin_command_h

#include "pin_command.h"

class QueryPinCommand : public PinCommand {

  public:  
    QueryPinCommand(CommandParser*);

    void updateBoard();
    void buildResponse();
};

#endif
