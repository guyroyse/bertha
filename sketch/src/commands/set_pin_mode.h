#ifndef set_pin_mode_command_h
#define set_pin_mode_command_h

#include "pin_command.h"

class SetPinModeCommand : public PinCommand {
  
  int _pin;
  PinMode _mode;
  
  public:  
    SetPinModeCommand(BerthaBuffer);
    void executeInternal(BerthaBuffer*);
};

#endif
