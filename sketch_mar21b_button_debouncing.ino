// Declare the Analog pin on the Arduino board
int buttonPin = A0;

void setup() {
    // Establish the Serial connection with a baud rate of 9600 
  Serial.begin(9600);
}

void loop(){
  // Read the value of the input. It can vary from 0 - 1023
  int buttonValue = analogRead(buttonPin);
    if (buttonValue < 100){
    // A value under 200 represents no button pushed
    Serial.println("0");
  } else if (buttonValue >= 100 && buttonValue < 200){
    // A value between 200 - 300 represents the third button
    Serial.println("S3");
  } else if (buttonValue >= 200 && buttonValue < 300){
    // A value between 300 - 400 represents the second button
    Serial.println("S2");
  } else if (buttonValue >= 300){
    // A value greater than 400 represents the first button
    Serial.println("S1");
  }

  // Delays the execution to allow time for the Serial transmission
  delay(1000);
}
