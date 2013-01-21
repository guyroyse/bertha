#ifndef set_pin_mode_command_h
#define set_pin_mode_command_h

#include "command.h"
#include "pin_mode.h"
#include "buffer.h"

class SetPinModeCommand : public Command {
  
  int _pin;
  PinMode _mode;
  
  public:  
    SetPinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

#endif
