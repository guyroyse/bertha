#ifndef digital_wirte_command_h
#define digital_wirte_command_h

#include "pin_command.h"
#include "../bertha_buffer.h"

class DigitalWriteCommand : public PinCommand {
  
  int _pin, _value;
  
  public:
    DigitalWriteCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
