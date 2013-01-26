#ifndef command_h
#define command_h

#include "../io/bertha_buffer.h"
#include "../board/board.h"
#include "command_parser.h"

class Command {
  
  BerthaBuffer _response;
  Board* _board;
  CommandParser* _parser;

  public:
    Command(CommandParser* parser);
    ~Command();

    BerthaBuffer execute();
    
  protected:
    Board* getBoard();
    CommandParser* getParser();

    virtual void updateBoard() = 0;
    virtual void buildResponse() = 0;
    
    void setOkStatus();
    void setErrorStatus();
    void appendNameAndValue(char* name, char* value);
    void appendNameAndValue(char* name, int value);

  private:
    void setStatus(char* status);
    void appendName(char* name);
    void appendValue(char* value);

};

#endif
