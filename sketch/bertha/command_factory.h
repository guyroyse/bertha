#ifndef command_factory_h
#define command_factory_h

#include "command.h"
#include "buffer.h"

class CommandFactory {
  public:
    static Command* createCommand(Buffer);
};

#endif
