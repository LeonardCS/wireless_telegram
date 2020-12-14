#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

/*
This sketch receives strings from sending unit via nrf24 
and prints them out via serial.  The sketch waits until
it receives a specific value (2 in this case), then it 
prints the complete message and clears the message buffer.
*/

RF24 radio(9,10); // CE, CSN
const uint64_t pipe = 0xE8E8F0F0E1LL;
int msg[1];
int lastmsg = 1;
String theMessage = "";

void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop(void){
  if (radio.available()){
    bool done = false;  
      done = radio.read(msg, 1); 
      char theChar = msg[0];
      if (msg[0] != 2){
        theMessage.concat(theChar);
        }
      else {
       Serial.println(theMessage);
       theMessage= ""; 
      }
   }
}