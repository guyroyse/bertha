#ifndef bertha_io_h
#define bertha_io_h

#include "buffer.h"
#include "arduino.h"

class BerthaIO {
  
  Buffer request;
  
  public:
    BerthaIO();
    void reset();
    Buffer nextRequest();
    void send(Buffer);
    
  private:
    boolean characterAvailable();
    char readCharacter();
    boolean endOfLine(char ch);
    
};

#endif
