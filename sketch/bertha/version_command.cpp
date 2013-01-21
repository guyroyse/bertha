#include "version_command.h"
#include "buffer.h"

void VersionCommand::executeInternal(Buffer* response) {
  response->append("v1.0.0");
}
