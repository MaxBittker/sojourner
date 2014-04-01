#include "constants.h"

#include <Servo.h>
extern Servo grip, tilt, pan;
void backward(int speed);
void forward(int speed);

boolean approachBucket() 
{
  tilt.write(TILTup); //Raise Gripper 
  lineFollow();//lineFollow exits when bumper is hit
  delay(10);
  tilt.write(TILTdrop); //Lower Gripper
  delay(10);  
  grip.write(GRIPopen); //Drop Ball
  backward(PWMspeed); //Back up to prevent collisions with goal
  delay(300);
  forward(0);
    
  return (true);
}
 
