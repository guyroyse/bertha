#ifndef command_factory_h
#define command_factory_h

#include "command.h"

#include "version.h"
#include "reset.h"
#include "query_pin.h"
#include "set_pin.h"
#include "error.h"

#include "command_parser.h"

class CommandFactory {
  public:
    static Command* createCommand(BerthaBuffer);
};

#endif
