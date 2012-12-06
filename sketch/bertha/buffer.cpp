#include "buffer.h"

Buffer::Buffer() {
  empty();
}

void Buffer::empty() {
  strncpy(buffer(), "", size());
}

Buffer* Buffer::append(char ch) {
  if (length() < maxLength())
    strncat(buffer(), &ch, 1);
  return this;
}

Buffer* Buffer::append(char* text) {
  if (freeSpace() > strlen(text)) {
    strncat(buffer(), text, freeSpace());
  }
  return this;
}

Buffer* Buffer::append(int i) {
  char temp[32];
  sprintf(temp, "%i", i);
  return append(temp);
}

char* Buffer::firstToken() {
  return strtok(buffer(), " ");
}

char* Buffer::nextToken() {
  return strtok(NULL, " ");
}

int Buffer::nextInt() {
  return atoi(strtok(NULL, " "));
}
