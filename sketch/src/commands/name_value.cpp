#include "name_value.h"

NameValue::NameValue(char* name, char* value) {
  _name = name;
  _value = value;
}

char* NameValue::name() {
  return _name;
}

char* NameValue::value() {
  return _value;
}
