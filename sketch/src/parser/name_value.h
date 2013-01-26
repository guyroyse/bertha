#ifndef name_value_h
#define name_value_h

class NameValue {

  char* _name;
  char* _value;

  public:
    NameValue(char*, char*);

    char* name();
    char* value();

};

#endif
