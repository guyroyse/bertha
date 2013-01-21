#ifndef pin_command_h
#define pin_command_h

#include "command.h"
#include "buffer.h"
#include "pin.h"

class PinCommand : public Command {
 
  int _pin;
  
  public:
    PinCommand(Buffer);

  protected:
    Pin* getPin();
};

#endif
