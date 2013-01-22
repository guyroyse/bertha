#ifndef digital_read_command_h
#define digital_read_command_h

#include "pin_command.h"

class DigitalReadCommand : public PinCommand {
  
  public:
    DigitalReadCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
