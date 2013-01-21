#ifndef query_pin_mode_command_h
#define query_pin_mode_command_h

#include "command.h"
#include "buffer.h"

class QueryPinModeCommand : public Command {
  
  int _pin;
  
  public:  
    QueryPinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
