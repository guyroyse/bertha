#ifndef command_h
#define command_h

#include "buffer.h"

class Command {
  
  Buffer _response;

  public:
    Buffer execute();
    
  protected:
    virtual void executeInternal(Buffer*) = 0;
    
};

#endif
