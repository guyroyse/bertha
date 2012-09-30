String command = "";
boolean commandAvailable = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (commandAvailable) {
    String response = processCommand(command);
    returnResponse(response);
    resetCommand();
  }
}

String processCommand(String command) {
  if (command.equals("VERSION"))
    return "1.0.0";
  else
    return "ERROR";
}

void returnResponse(String response) {
  Serial.println(response);
}

void resetCommand() {
  command = "";
  commandAvailable = false;
}


void serialEvent() {
  while (characterAvailable()) {
    char ch = readCharacter();
    if (endOfLine(ch)) {
      commandAvailable = true;
    } else {
      appendCharacter(ch);
    }
  }
}

boolean characterAvailable() {
  return Serial.available();
}

char readCharacter() {
  return (char) Serial.read();
}

boolean endOfLine(char ch) {
  return ch == '\n';
}

void appendCharacter(char ch) {
    command += ch;
}
