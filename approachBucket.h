#include "constants.h"

#include <Servo.h>
extern Servo grip, tilt, pan;

void backward(int speed);

boolean approachBucket() {
  
  tilt.write(TILTup);
  
  lineFollow();
  
  //something so that it has time to take nudge functions
  
  delay(10);
  tilt.write(TILTdrop);
  delay(10);  
  grip.write(GRIPopen);
  
  backward(PWMspeed);
  delay(600);
  forward(0);
    
  return (true);
  
}
 
