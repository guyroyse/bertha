#ifndef query_pin_mode_command_h
#define query_pin_mode_command_h

#include "pin_command.h"
#include "buffer.h"

class QueryPinModeCommand : public PinCommand {
  
  public:  
    QueryPinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
