#include "command.h"

#include "bertha_buffer.h"

BerthaBuffer Command::execute() {
  executeInternal(&_response);
  return _response;
}
