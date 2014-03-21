//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)
#include nudge.h
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
  
  while (ball == false){
    backward(0); //stop
    
    direction = getDirection();
    if(direction == success)
    return(true);
    else (){
      grip.write(GRIPopen);
      tilt.write(TILTup);
      if(direction==left)
      pivot(-5);
      else if (direction==right)
      pivot(5);
      else if (direction==bigleft)
      pivot(-10);
      else if (direction==bigright)
      pivot(10);
      ball=ObjGrab();
      
    }
  }

}


boolean ObjGrab() {
  tilt.write(TILThoriz);
  delay(300)
  grip.write(GRIPclose);
  delay(300)
  
  if (analogRead(A5)>100){
    return(true);
  }
  else{
    return(false);
  }
 
}


