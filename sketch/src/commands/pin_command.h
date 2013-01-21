#ifndef pin_command_h
#define pin_command_h

#include "command.h"
#include "../board/board.h"

class PinCommand : public Command {
 
  int _pin;
  
  public:
    PinCommand(BerthaBuffer);

  protected:
    Pin* getPin();
};

#endif
