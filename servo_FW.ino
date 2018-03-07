#include <Servo.h>

Servo theServo;  
int angle = 0;  

void setup() 
{ 
  theServo.attach(9);  
} 


void loop() 
{ 
  for(angle = 0; angle < 180; angle += 1)   
  {                                  
   theServo.write(angle);               
    delay(20);                       
  } 
  for(angle = 180; angle >= 1; angle -=1)     
  {                                
    theServo.write(angle);              
    delay(20);                       
  } 
}
