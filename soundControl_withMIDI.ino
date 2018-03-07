#include <MIDI.h>
#include <MozziGuts.h>
#include <utils.h> 
#include <Oscil.h> 
#include <Line.h> 
#include <tables/sin2048_int8.h> 

#define CONTROL_RATE 128 // 2^x

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> aSin(SIN2048_DATA);

// for envelope
Line <unsigned int> aGain;
unsigned int release_control_steps = CONTROL_RATE; 
unsigned int release_audio_steps = 16384; 
int fade_counter;

float vol= 1. ; 

unsigned int freq; 


void HandleControlChange(byte channel, byte CCnumber, byte value) { 
  switch(CCnumber){
    case 100:
      vol = map(value,0, 127, 0., 1.);
    break;
  }
}

void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  freq = mtof(pitch);
  aGain.set(velocity<<8); // might need a fade-in to avoid clicks

}


void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  aGain.set(0,release_audio_steps);
  fade_counter = release_control_steps;
}

void setup() {
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  MIDI.setHandleControlChange(HandleControlChange);   
  MIDI.setHandleNoteOn(HandleNoteOn);  
  MIDI.setHandleNoteOff(HandleNoteOff);
  aSin.setFreq(440u); 
  startMozzi(CONTROL_RATE); 
}

void updateControl(){
  // Ideally, call MIDI.read the fastest you can for real-time performance.
  // In practice, there is a balance required between real-time 
  // audio generation and a responsive midi control rate.
  MIDI.read();
  if (fade_counter-- <=0) aGain.set(0,0,2); // a line along 0
}

int updateAudio(){
  return (int) ((aGain.next()>>8) * aSin.next() * vol )>>8; 
  }
  
void loop() {
    audioHook(); // required here
}
  
