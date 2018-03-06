int vPin = 9; 
int frValue = 0;  // stores the current feed value
int dirVar = 1; // stores the direction of the variation

void setup() {
}

void loop() {
  
  // test current value and change the direction if required
  if (frValue == 0 || frValue == 255) dirVar *= -1;
  
  analogWrite(vPin, frValue + dirVar);
  delay(30);
}
