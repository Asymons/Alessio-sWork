
#include <SPI.h>
#include <Ethernet.h>

 // the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
//the IP address for the shield:
byte ip[] = { 10, 0, 0, 177 };    
// the router's gateway address:
byte gateway[] = { 10, 0, 0, 1 };
// the subnet:
byte subnet[] = { 255, 255, 0, 0 };

// telnet defaults to port 23
EthernetServer server = EthernetServer(23);

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  // start listening for clients
  server.begin();
  // initialize the LED pins:
  for (int thisPin = 8; thisPin < 13; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void pinLight(int x){
  for (int thisPin = 8; thisPin < 8+x; thisPin++) {
      digitalWrite(thisPin, HIGH);
  }
}

void loop() {
  // read the sensor:
  EthernetClient client = server.available();
  if (client == true) {
    // read bytes from the incoming client and write them back
    // to any clients connected to the server:
    int inByte = client.read();
  }
    // do something different depending on the character received.
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
      case 'a':
        pinLight(1);
        break;
      case 'b':
        pinLight(2);
        break;
      case 'c':
        pinLight(3);
        break;
      case 'd':
        pinLight(4);
        break;
      case 'e':
        pinLight(5);
        break;
      default:
        // turn all the LEDs off:
        for (int thisPin = 8; thisPin < 13; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
