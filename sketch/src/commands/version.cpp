#include "version.h"

void VersionCommand::executeInternal(BerthaBuffer* response) {
  response->append("v1.0.0");
}
