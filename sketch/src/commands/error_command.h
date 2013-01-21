#ifndef error_command_h
#define error_command_h

#include "../bertha_buffer.h"
#include "command.h"

class ErrorCommand : public Command {
  public:
    void executeInternal(BerthaBuffer*);
};

#endif
