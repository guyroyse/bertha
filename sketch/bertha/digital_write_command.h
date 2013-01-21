#ifndef digital_wirte_command_h
#define digital_wirte_command_h

#include "command.h"
#include "buffer.h"

class DigitalWriteCommand : public Command {
  
  int _pin, _value;
  
  public:
    DigitalWriteCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
