#include "command.h"

#include "buffer.h"

Buffer Command::execute() {
  executeInternal(&_response);
  return _response;
}
