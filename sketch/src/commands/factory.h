#ifndef command_factory_h
#define command_factory_h

#include "command.h"
#include "../bertha_buffer.h"

class CommandFactory {
  public:
    static Command* createCommand(BerthaBuffer);
};

#endif
