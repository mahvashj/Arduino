#include <ShiftOutX.h>
#include <ShiftPinNo.h>

int CLOCK_595 = 4;    // first 595 clock pin connecting to pin 4
int LATCH_595 = 3;    // first 595 latch pin connecting to pin 3
int DATA_595 = 2;     // first 595 serial data input pin connecting to pin 2

int SR_Number = 2;    // number of shift registers in the chain

// instantiate and enabling the shiftOutX library with our circuit parameters
shiftOutX regGroupOne(LATCH_595, DATA_595, CLOCK_595, MSBFIRST, SR_Number);

// random groove machine variables
int counter = 0;
byte LeftChannel = B00000000 ;  // store left channel Leds infos
byte RightChannel = B00000000 ; // store right channel Leds infos

void setup() {
  // NO MORE setup for each digital pin of the Arduino
  // EVERYTHING is made by the library :-)
}

void loop(){ 

  if (Serial.available() > 0) {
    LeftChannel = (byte)Serial.parseInt();
    RightChannel = (byte)Serial.parseInt();


    unsigned short int data; // declaring the data container as a very local variable
    data = ( LeftChannel << 8 ) | RightChannel; // aggregating the 2 read bytes
    shiftOut_16(DATA_595, CLOCK_595, MSBFIRST, data);  // pushing the whole data to SRs

    // make a short pause before changing LEDs states
    delay(2);
  }
}
