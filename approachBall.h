//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

#include <Servo.h>
extern Servo grip, tilt, pan;
#include "constants.h"

void backward(int speed);
void forward(int speed);

boolean ObjGrab();
extern void waitButton();

boolean approachBall() {
  Serial.println("approaching ball" );
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  lineFollow();
  Serial.println("trying to grab");
  boolean ball = ObjGrab();
   Serial.println("grabbedball");
   
  if (ball == true) {

    backward(100);
    // Serial.println("backing up" );
    delay(50);
    forward(0);
    return (true) ;
  }
  
  //stop, wait for button press - so that can be returned to start
  if (ball == false){
    Serial.println("no ball");
    forward(0);
    waitButton();
    loop();
    //goto missedball;  
  }
}


boolean ObjGrab() {
  
  delay(100);
  tilt.write(TILTgrab); //move as fxn of for loop so slower
  delay(300);
  grip.write(GRIPclose);
  delay(100);
  
  if (analogRead(A5)>100){
    return(true);
  }
  else{
    return(false);
  }
 
}


