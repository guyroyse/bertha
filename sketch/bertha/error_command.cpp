#include "error_command.h"
#include "buffer.h"

void ErrorCommand::executeInternal(Buffer* response) {
  response->append("ERR: unknown command");
}
