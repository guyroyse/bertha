#ifndef commands_h
#define commands_h

#include "pin.h"
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

class PinModeCommand : public Command {
  
  Pin pin;
  
  public:  
    PinModeCommand(Buffer);
    void executeInternal(Buffer*);
};

class DigitalWriteCommand : public Command {
  
  Pin pin;
  
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
