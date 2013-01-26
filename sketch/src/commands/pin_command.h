#ifndef pin_command_h
#define pin_command_h

#include "command.h"
#include "command_parser.h"
#include "../board/board.h"

class PinCommand : public Command {
 
  CommandParser* _parser;
  int _pin;
  
  public:
    PinCommand(CommandParser*);
    ~PinCommand();

  protected:
    Pin* getPin();
};

#endif
