#include "bertha_io.h"

BerthaIO::BerthaIO() {
  Serial.begin(9600);
}

void BerthaIO::reset() {
  request.empty();
}

BerthaBuffer BerthaIO::nextRequest() {
  while (true) {
    if (characterAvailable()) {
      char ch = readCharacter();
      if (endOfLine(ch)) {
        return request;
      } else {
        request.append(ch);
      }
    }
  }
}

void BerthaIO::send(BerthaBuffer response) {
  Serial.println(response.buffer());
}

boolean BerthaIO::characterAvailable() {
  return Serial.available();
}

char BerthaIO::readCharacter() {
  return (char) Serial.read();
}

boolean BerthaIO::endOfLine(char ch) {
  return ch == '\n';
}

