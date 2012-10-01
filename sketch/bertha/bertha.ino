/*
 * Globals and constants
 */

const int BUFFER_SIZE = 64;
const int MAX_SIZE = BUFFER_SIZE - 1;

char command[BUFFER_SIZE];
boolean commandAvailable = false;

void resetCommand() {
  strncpy(command, "", BUFFER_SIZE);
  commandAvailable = false;
}


/*
 * Startup
 */
 
void setup() {
  Serial.begin(9600);
  resetCommand();
}


/*
 * The serial event and helpers
 */

// fires every time there is data available
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
  if (strlen(command) < MAX_SIZE)
    strncat(command, &ch, 1);
}


/*
 * Main loop and helpers
 */

void loop() {
  char response[BUFFER_SIZE];
  if (commandAvailable) {
    processCommand(command, response);
    Serial.println(response);
    resetCommand();
  }
}

void processCommand(char* commandText, char* response) {
  
  char* command = parseCommand(commandText);
  
  if (!strcmp("version", command)) {
    processVersion(response);
  } else if (!strcmp("pinMode", command)) {
    processPinMode(response);
  } else if (!strcmp("digitalWrite", command)) {
    processDigitalWrite(response);
  } else {
    strncpy(response, "ERR: unknown command", BUFFER_SIZE);
  }

}

void processVersion(char* response) {
  strncpy(response, "v1.0.0", MAX_SIZE);
}

void processPinMode(char* response) {
  int pin = parseInt();
  pinMode(pin, OUTPUT);
  snprintf(response, BUFFER_SIZE, "OK: pin %i set to OUTPUT", pin);
}

void processDigitalWrite(char* response) {
  int pin = parseInt();
  int value = parseInt();  
  digitalWrite(pin, value);
  snprintf(response, BUFFER_SIZE, "OK: pin %i set to %i", pin, value);
}

char* parseCommand(char* commandText) {
  return strtok(commandText, " ");
}

int parseInt() {
  return atoi(strtok(NULL, " "));
}
