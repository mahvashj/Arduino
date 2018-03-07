#include <Servo.h> 

Servo servo1;
Servo servo2;
Servo servo3;

int angle;

void setup() 
{ 
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
} 

void loop() 
{ 
  for(angle = 0; angle < 180; angle += 1)   
  {                                  
    servo1.write(angle);
    servo2.write(145-angle/2);
    servo3.write(180-angle);

    delay(25);                       
  }
}

