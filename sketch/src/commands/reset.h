#ifndef reset_command_h
#define reset_command_h

#include "command.h"
#include "../board/board.h"

class ResetCommand : public Command {

  public:
    void updateBoard();
    void buildResponse();
};

#endif
