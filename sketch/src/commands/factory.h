#ifndef command_factory_h
#define command_factory_h

#include "command.h"

#include "version.h"
#include "query_pin.h"
#include "set_pin_mode.h"
#include "query_pin_mode.h"
#include "digital_write.h"
#include "query_digital_write.h"
#include "digital_read.h"
#include "error.h"

class CommandFactory {
  public:
    static Command* createCommand(BerthaBuffer);
};

#endif
