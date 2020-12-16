#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>


RF24 radio(9,10); // CE, CSN
const uint64_t pipe = 0xE8E8F0F0E1LL;



void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}

void loop(void){
  if (radio.available()){
    bool done = false;  
      
    //data hier ontvangen
   
   
      }
   }
}
