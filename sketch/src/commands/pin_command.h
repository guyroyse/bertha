#ifndef pin_command_h
#define pin_command_h

#include "command.h"
#include "../bertha_buffer.h"
#include "../board/pin.h"

class PinCommand : public Command {
 
  int _pin;
  
  public:
    PinCommand(BerthaBuffer);

  protected:
    Pin* getPin();
};

#endif
