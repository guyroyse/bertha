#ifndef version_command_h
#define version_command_h

#include "command.h"
#include "buffer.h"

class VersionCommand : public Command {
  public:
    void executeInternal(Buffer*);
};

#endif
