#include <Stepper.h>
#define STEPS 200

// create an instance of stepper class
Stepper stepper(STEPS, 8, 9, 10, 11);

int counter = 0; // store steps number since last change of direction
int multiplier = 1; // a basic multiplier

void setup() 
{ 
  stepper.setSpeed(30); // set the speed at 30 RPM
} 

void loop()
{

  // move randomly from at least 1 step
  stepper.step(multiplier);

  // counting how many steps already moved
  // then if we reach a whole turn, reset counter and go backward
  if (counter < STEPS)  counter++ ;
  else { 
    counter = 0; 
    multiplier *= -1;
  }
}
