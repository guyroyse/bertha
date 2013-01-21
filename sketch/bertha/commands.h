#ifndef commands_h
#define commands_h

#include "pins.h"
#include "buffer.h"
#include "arduino.h"

class Command {
  
  public:
    Buffer execute();
    
  protected:
    virtual void executeInternal(Buffer*) = 0;
    
  private:
    Buffer response;
    
};

class VersionCommand : public Command {
  public:
    VersionCommand() {};
    void executeInternal(Buffer*);
};

class SetPinModeCommand : public Command {
  
  int _pin;
  PinMode _mode;
  
  public:  
    SetPinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

class QueryPinModeCommand : public Command {
  
  int _pin;
  
  public:  
    QueryPinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

class DigitalWriteCommand : public Command {
  
  int _pin, _value;
  
  public:
    DigitalWriteCommand(Buffer);
    void executeInternal(Buffer*);
};

class ErrorCommand : public Command {
  public:
    ErrorCommand() {};
    void executeInternal(Buffer*);
};

class CommandFactory {
  public:
    static Command* createCommand(Buffer);
};

#endif
