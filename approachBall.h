//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

#include <Servo.h>
extern Servo grip, tilt, pan;
extern location destination;

void backward(int speed);
boolean ObjGrab();

boolean approachBall() {
  
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  lineFollow();
  
  boolean ball = ObjGrab();
   
  if (ball == true) {
    destination = bucket;
    backward(100);
    delay(100);
    backward(0);
    return (true) ;
  }
  
  if (ball == false)
    backward(0); //stop
    //enter shuffle functions
  
}


boolean ObjGrab() {
  tilt.write(TILThoriz);
  grip.write(GRIPclose);
  
  if (analogRead(A5)>100){
    return(true);
  }
  else{
    return(false);
  }
 
}


