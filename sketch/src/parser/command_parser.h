#ifndef command_parser_h
#define command_parser_h

#include "name_value.h"
#include "../io/bertha_buffer.h"

class CommandParser {

  char* _verb;
  NameValue* _arguments[8];

  public:
    CommandParser(BerthaBuffer);
    ~CommandParser();

    char* verb();
    char* argument(char* name);
    int argumentAsInt(char* name);

};

#endif
