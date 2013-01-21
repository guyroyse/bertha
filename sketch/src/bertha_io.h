#ifndef bertha_io_h
#define bertha_io_h

#include "bertha_buffer.h"

class BerthaIO {
  
  BerthaBuffer request;
  
  public:
    BerthaIO();
    void reset();
    BerthaBuffer nextRequest();
    void send(BerthaBuffer);
    
  private:
    boolean characterAvailable();
    char readCharacter();
    boolean endOfLine(char ch);
    
};

#endif
