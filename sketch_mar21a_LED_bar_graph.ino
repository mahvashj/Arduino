/* LED bar graph */
const int analogPin = A1; // pin for potentiometer 
const int ledCount = 8; // number of LEDs
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // pins attached to LEDs

void setup() {
   // setting ledPins array to output:
   for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      pinMode(ledPins[thisLed], OUTPUT);
   }
}

void loop() {
   // reading the potentiometer:
   int sensorReading = analogRead(analogPin);
   // map the result to a range from 0 to the number of LEDs:
   int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
   // LED arraay loop:
   for (int thisLed = 0; thisLed < ledCount; thisLed++) {
      /* if the array element's index is less than ledLevel,
      turn the pin for this element on:*/
      if (thisLed < ledLevel) {
         digitalWrite(ledPins[thisLed], HIGH);
      }else { // turn off all pins higher than the ledLevel:
         digitalWrite(ledPins[thisLed], LOW);
      }
   }
} 
