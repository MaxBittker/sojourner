#include <Servo.h>
extern Servo grip, tilt, pan;
#include "constants.h"

void backward(int speed);
void forward(int speed);

boolean ObjGrab();
extern void waitButton();

boolean approachBall() {
  Serial.println("Approaching Ball" ); //Serial Print for Testing
  grip.write(GRIPopen);
  tilt.write(TILTup);//Initialize gripper starting position
  lineFollow();
  Serial.println("Trying To Grab"); //Serial Print for Testing
  boolean ball = ObjGrab(); //Call Function to Grab Ball/Grip Sense
  
 
 //If ball is grabbed return true, continue navigating  
  if (ball == true) {
    Serial.println("Grabbed Ball");
    backward(100);
    delay(50);
    forward(0);
    return (true) ;
  }
  
//If ball is not grabbed return false, wait for reset
  if (ball == false){
    Serial.println("no ball");
    forward(0);
    return(false);
  }
}

//Function for grabbing the ball and grip sensing
boolean ObjGrab() {
  
  delay(100);
  tilt.write(TILTgrab);
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


