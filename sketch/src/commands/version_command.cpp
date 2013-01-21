#include "version_command.h"
#include "../bertha_buffer.h"

void VersionCommand::executeInternal(BerthaBuffer* response) {
  response->append("v1.0.0");
}
