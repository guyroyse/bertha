#include "version.h"

void VersionCommand::executeInternal(BerthaBuffer* response) {
  response->append("OK version=1.0.0");
}
