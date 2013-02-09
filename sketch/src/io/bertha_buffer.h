#ifndef buffer_h
#define buffer_h

#include "Arduino.h"

const int BUFFER_SIZE = 64;

class BerthaBuffer {
  
  char _buffer[BUFFER_SIZE];
  
  public:
    BerthaBuffer();
    
    void empty();
    char* buffer() { return _buffer; };
    
    void set(const char*);

    BerthaBuffer* append(char);
    BerthaBuffer* append(const char*);
    BerthaBuffer* append(int);
    
    char* nextToken();
    int nextInt();

    char* parseVerb();
    char* nextName();
    char* nextValue();
    
  private:
    int size() { return BUFFER_SIZE; };
    int maxLength() { return size() - 1; };
    int length() { return strlen(buffer()); };
    int freeSpace() { return maxLength() - length(); };
    
};

#endif
