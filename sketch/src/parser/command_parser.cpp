#include "command_parser.h"

CommandParser::CommandParser(BerthaBuffer request) {

  for(int i = 0; i < 8; i++)
    _arguments[i] = 0;

  _verb = request.parseVerb();

  char* name = request.nextName();
  char* value = request.nextValue();

  int index = 0;

  while (name && value && index < 8) {
    _arguments[index] = new NameValue(name, value);
    name = request.nextName();
    value = request.nextValue();
    index++;
  }

}

CommandParser::~CommandParser() {
  for (int i = 0; i < 8; i++)
    if (_arguments[i])
      delete _arguments[i];
}

char* CommandParser::verb() {
  return _verb;
}

char* CommandParser::argument(char* name) {
  for (int i = 0; i < 8; i++) {
    char* currentName = _arguments[i]->name();
    if (!strcmp(currentName, name))
      return _arguments[i]->value();
  }
  return 0;
}

int CommandParser::argumentAsInt(char* name) {
  return atoi(this->argument(name));
}
