//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

#include <Servo.h>
extern Servo grip, tilt, pan;
extern location destination;

void backward(int speed);
boolean ObjGrab();

boolean approachBall() {
  Serial.println("approaching ball" );
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  lineFollow();
  
  boolean ball = true;//ObjGrab();
   
  if (ball == true) {
    destination = bucket;
    backward(100);
     Serial.println("backing up" );
    delay(50);
    forward(0);
    return (true) ;
  }
  
  if (ball == false)
    forward(0); //stop
    //enter shuffle functions
  
}


boolean ObjGrab() {
  tilt.write(TILThoriz);
  delay(300);
  grip.write(GRIPclose);
  delay(300);
  
  if (analogRead(A5)>100){
    return(true);
  }
  else{
    return(false);
  }
 
}

