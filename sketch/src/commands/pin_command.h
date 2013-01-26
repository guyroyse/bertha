#ifndef pin_command_h
#define pin_command_h

#include "command.h"

class PinCommand : public Command {
 
  public:
    PinCommand(CommandParser*);

  protected:
    Pin* getPin();
};

#endif
