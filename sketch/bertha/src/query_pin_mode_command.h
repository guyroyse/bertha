#ifndef query_pin_mode_command_h
#define query_pin_mode_command_h

#include "pin_command.h"
#include "bertha_buffer.h"

class QueryPinModeCommand : public PinCommand {
  
  public:  
    QueryPinModeCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
