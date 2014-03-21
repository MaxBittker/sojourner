#include "constants.h"

#include <Servo.h>
extern Servo grip, tilt, pan;

void backward(int speed);

boolean approachBucket() {
  
  tilt.write(TILTup);
  
  lineFollow();
  
  grip.write(GRIPopen);
  
  backward(100);
  delay(100);
  backward(0);
    
  return (true);
  
}
 
