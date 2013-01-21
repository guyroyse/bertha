#ifndef digital_wirte_command_h
#define digital_wirte_command_h

#include "pin_command.h"
#include "buffer.h"

class DigitalWriteCommand : public PinCommand {
  
  int _pin, _value;
  
  public:
    DigitalWriteCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
