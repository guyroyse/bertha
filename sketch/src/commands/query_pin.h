#ifndef query_pin_command_h
#define query_pin_command_h

#include "command.h"
#include "../board/board.h"

class QueryPinCommand : public Command {

  int _pin;
  
  public:  
    QueryPinCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
