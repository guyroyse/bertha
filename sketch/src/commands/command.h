#ifndef command_h
#define command_h

#include "../io/bertha_buffer.h"

class Command {
  
  BerthaBuffer _response;

  public:
    BerthaBuffer execute();
    
  protected:
    virtual void executeInternal(BerthaBuffer*) = 0;
    
};

#endif
