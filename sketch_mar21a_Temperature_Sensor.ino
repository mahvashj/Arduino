// Declare the LEDs in an array
int LED [5] = {2, 3, 4, 5, 6};
int sensorPin = A0; // Declare the used sensor pin

void setup(){
   // Start the Serial connection
  Serial.begin(9600); 
  // Set all LEDs as OUTPUTS 
  for (int i = 0; i < 5; i++){
    pinMode(LED[i], OUTPUT);
  }
}

void loop(){
  // Read the value of the sensor
  int val = analogRead(sensorPin);
  Serial.println(val); // Print it to the Serial
    // On the LM35 each degree Celsius equals 10 mV
  // 20C is represented by 200 mV which means 0.2 V / 5 V * 1023 = 41
  // Each degree is represented by an analogue value change of approximately 2
    // Set all LEDs off
  for (int i = 0; i < 5; i++){
    digitalWrite(LED[i], LOW);
  }

 if (val < 40 && val > 45){ // 20 - 22 C
    digitalWrite( LED[0], HIGH);
  } else if (val > 45 && val < 49){ // 22 - 24 C
    digitalWrite( LED[0], HIGH);
    digitalWrite( LED[1], HIGH);
  } else if (val > 49 && val < 53){ // 24 - 26 C
    digitalWrite( LED[0], HIGH);
    digitalWrite( LED[1], HIGH);
    digitalWrite( LED[2], HIGH);
  } else if (val > 53 && val < 57){ // 26 - 28 C
    digitalWrite( LED[0], HIGH);
    digitalWrite( LED[1], HIGH);
    digitalWrite( LED[2], HIGH);
    digitalWrite( LED[3], HIGH);
  } else if (val > 57){ // Over 28 C
    digitalWrite( LED[0], HIGH);
    digitalWrite( LED[1], HIGH);
    digitalWrite( LED[2], HIGH);
    digitalWrite( LED[3], HIGH);
    digitalWrite( LED[4], HIGH);
  }
  delay(100); // Small delay for the Serial to send
}
