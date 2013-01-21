#include "error_command.h"
#include "bertha_buffer.h"

void ErrorCommand::executeInternal(BerthaBuffer* response) {
  response->append("ERR: unknown command");
}
