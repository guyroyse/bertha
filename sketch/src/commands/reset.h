#ifndef reset_command_h
#define reset_command_h

#include "command.h"

class ResetCommand : public Command {

  public:
    ResetCommand(CommandParser*);

    void updateBoard();
    void buildResponse();
};

#endif
