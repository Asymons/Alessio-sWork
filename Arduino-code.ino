

void setup() {
  Serial.begin(9600);
  for (int thisPin = 8; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void pinLight(int x){
  for (int thisPin = 8; thisPin < 8+x; thisPin++) {
      digitalWrite(thisPin, HIGH);
  }
  for(int thisPin = 8-1+x; thisPin < 13; thisPin++){
      digitalWrite(thisPin,LOW);
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
      case '1':
        pinLight(2);
        break;
      case '2':
        pinLight(3);
        break;
      case '3':
        pinLight(4);
        break;
      case '4':
        pinLight(5);
        break;
      case '5':
        pinLight(6);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 8; thisPin < 13; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
