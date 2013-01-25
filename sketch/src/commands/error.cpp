#include "error.h"

void ErrorCommand::executeInternal(BerthaBuffer* response) {
  response->append("ERR msg='unknown command'");
}
