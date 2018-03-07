#include <LiquidCrystal.h>

String manyMessages[4];
int counter = 0;

// Initialize the library with pins number of the circuit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  // number of column and row of the LCD
  lcd.begin(16, 2);

  manyMessages[0] = "I am the Arduino";
  manyMessages[1] = "I can talk";
  manyMessages[2] = "I can feel";
  manyMessages[3] = "I can react";

  randomSeed(analogRead(0);
}

void loop() {

  // set the cursor to column 0 and row 0
  lcd.setCursor(0, 0);

  // for 5s each
  if (millis() - counter > 5000)
  {
    lcd.clear(); // clear the whole LCD
    lcd.print(manyMessages[random(4)]); // display a random message
    counter = millis();  // store the current time
  }

  // set the cursor to column 0 and row 1
  lcd.setCursor(0, 1);
  // print the value of millis() at each loop() execution
  lcd.print("up since: " + millis() + "ms");
}
