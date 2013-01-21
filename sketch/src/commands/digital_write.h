#ifndef digital_write_command_h
#define digital_write_command_h

#include "pin_command.h"

class DigitalWriteCommand : public PinCommand {
  
  int _pin, _value;
  
  public:
    DigitalWriteCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
