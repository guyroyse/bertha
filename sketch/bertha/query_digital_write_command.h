#ifndef query_digital_write_command_h
#define query_digital_write_command_h

#include "pin_command.h"
#include "buffer.h"

class QueryDigitalWriteCommand : public PinCommand {
  
  public:  
    QueryDigitalWriteCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
