#ifndef buffer_h
#define buffer_h

#include "arduino.h"

const int BUFFER_SIZE = 64;

class Buffer {
  
  char _buffer[BUFFER_SIZE];
  
  public:
    Buffer();
    
    void empty();
    char* buffer() { return _buffer; };
    
    Buffer* append(char);
    Buffer* append(char*);
    Buffer* append(int);
    
    char* firstToken();
    char* nextToken();
    int nextInt();
    
  private:
    int size() { return BUFFER_SIZE; };
    int maxLength() { return size() - 1; };
    int length() { return strlen(buffer()); };
    int freeSpace() { return maxLength() - length(); };
    
};

#endif
