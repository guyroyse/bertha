#include "bertha_buffer.h"

BerthaBuffer::BerthaBuffer() {
  empty();
}

void BerthaBuffer::empty() {
  strncpy(buffer(), "", size());
}

BerthaBuffer* BerthaBuffer::append(char ch) {
  if (length() < maxLength())
    strncat(buffer(), &ch, 1);
  return this;
}

BerthaBuffer* BerthaBuffer::append(char* text) {
  if (freeSpace() > strlen(text)) {
    strncat(buffer(), text, freeSpace());
  }
  return this;
}

BerthaBuffer* BerthaBuffer::append(int i) {
  char temp[32];
  sprintf(temp, "%i", i);
  return append(temp);
}

char* BerthaBuffer::firstToken() {
  return strtok(buffer(), " ");
}

char* BerthaBuffer::nextToken() {
  return strtok(NULL, " ");
}

int BerthaBuffer::nextInt() {
  return atoi(strtok(NULL, " "));
}
