#ifndef command_factory_h
#define command_factory_h

#include "../commands/commands.h"

class CommandFactory {
  public:
    static Command* createCommand(BerthaBuffer);
};

#endif
