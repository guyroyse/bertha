#ifndef version_command_h
#define version_command_h

#include "command.h"

class VersionCommand : public Command {
  public:
    void executeInternal(BerthaBuffer*);
};

#endif
