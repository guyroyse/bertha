#include "command.h"

BerthaBuffer Command::execute() {
  executeInternal(&_response);
  return _response;
}
