// Declare the Analog pin on the Arduino board
int buttonPin = A0;

void setup() {
   Serial.begin(9600);
}

void loop(){
  // Read the value of the input; vary from 0 - 1023
  int buttonValue = analogRead(buttonPin);
    if (buttonValue < 100){
    // A value under 100 represents no button pushed
    Serial.println("0");
  } else if (buttonValue >= 100 && buttonValue < 200){
    // A value between 100 - 200 represents the third button
    Serial.println("S3");
  } else if (buttonValue >= 200 && buttonValue < 300){
    // A value between 200 - 300 represents the second button
    Serial.println("S2");
  } else if (buttonValue >= 300){
    // A value greater than 300 represents the first button
    Serial.println("S1");
  }

  // Delays the execution to allow time for the Serial transmission
  delay(1000);
}
