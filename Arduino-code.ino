
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 2; thisPin < 7; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
      case 'a':
        digitalWrite(8, HIGH);
        break;
      case 'b':
        digitalWrite(9, HIGH);
        break;
      case 'c':
        digitalWrite(10, HIGH);
        break;
      case 'd':
        digitalWrite(11, HIGH);
        break;
      case 'e':
        digitalWrite(12, HIGH);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 8; thisPin < 12; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}