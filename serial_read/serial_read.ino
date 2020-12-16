#include <AltSoftSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

AltSoftSerial altSerial;

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
// const int requestPin = 4;

const int numChars = 1024; // zou mogelijk kleiner kunnen
char receivedChars [numChars]; // buffer met de data, moet nog opgesplits worden in 32byte data sets + frame nummers
boolean newData = false;


void setup() {
  Serial.begin(115200);
  delay(1000);
  altSerial.begin(115200);
  delay(1000);
  radio.begin();
  radio.openWritingPipe(pipe);
 }

void loop(){
    recvWithStartEndMarkers();
    showNewData();
      // const uint8_t i;
   }

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static int ndx = 0;
  char startMarker = '/';
  char endMarker = '!';
  const byte endMarkerOffset = 4;
  char rc;

  while (altSerial.available() > 0 && newData == false) {
    rc = altSerial.read();

    if (recvInProgress == true) {
      if ((ndx < endMarkerOffset) || ((ndx >= endMarkerOffset) && receivedChars[ndx - endMarkerOffset] != endMarker)) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars - 2) {
          ndx = numChars - 3; //allow room for last character of checksum + newline + null
          //shift last 4 characters back so that endMarker goes into correct position
          for (int i = 0; i < endMarkerOffset; i++) {
            receivedChars[ndx - endMarkerOffset + i] = receivedChars[ndx - endMarkerOffset + i + 1];
          }
        }
      } else {
        receivedChars[ndx] = rc; // place endMarker at end of telegram
        ++ndx;
        receivedChars[ndx] = '\n'; // terminate the line
        ++ndx;
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
      receivedChars[ndx] = rc; // place startMarker at begin of telegram
      ndx++;
    }
  }
}

void showNewData() {
   //  const uint8_t i;
  if (newData == true) {
   Serial.print(receivedChars);


    
      
  //radio.write( ); // moet receivedChars gaan versturen 

  
  // radio.powerDown(); 
  // delay(200000);
  // radio.powerUp();

    newData = false; // activeren als de data verstuurd is
  }
} 
