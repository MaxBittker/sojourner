//Group 35  (MB, MW, SW)

#include "enum_stuff.h"
#include "lineFollow.h"
#include "navigate.h"
#include "approachBucket.h"
#include "approachBall.h"
#include "constants.h"

#include <Servo.h>
Servo pan, grip, tilt;

//counters
int lec = 0;
int rec = 0;

location currentPos = centre;
location mainDest;

void setup(){
  
  //servo pin assignment
  grip.attach(10);
  tilt.attach(9);
  pan.attach(8);
  
  //set servo high
  grip.write(GRIPopen);
  tilt.write(TILTup);
  pan.write(PANcentre);
  
  //motor pin assignmnet
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);
  
  //motor direction - forward
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  //light sensing pin input
  pinMode(left, INPUT);
  pinMode(middle, INPUT);
  pinMode(right, INPUT);
  pinMode(IRpin, INPUT);
  //interrupts
  attachInterrupt(11, leftEn, RISING);
  attachInterrupt(12, rightEn, RISING);
  
  //Serial.begin(9600);
  Serial.begin(115200);
 //grip.write(GRIPclose);
  waitButton();

}


void loop(){
  
    mainDest = getLoc();  //get loc from BT
    //if(destination == fail)
      //destination = findLoc(); //give up and find it yourself 
    if(mainDest !=fail)
     currentPos = navigate(currentPos, mainDest); // go there

}//end loop


//seems to slightly overroatet positively, and possibly under negatively
void pivot(int angle)
{
   
  delay(100);
  
  if (angle > 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  } else if (angle < 0) {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
  }

  lec = 0;
  rec = 0;
  
  float ratio = encCounts/(float)turnAngle;
  
  
  analogWrite(E1, PWMspeed*.7);
  analogWrite(E2, PWMspeed*.7);
    
  while(rec < (int)(abs(angle)*ratio)) {    
      int re_old = digitalRead(re);
      while(digitalRead(re) == re_old){}
      rec++;
  }
  
  forward(0);

}

void forward(int speed) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speed);
  analogWrite(E2, speed);  
}

void backward(int speed) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, speed);
  analogWrite(E2, speed);  
}

void waitButton(){
  
  while(digitalRead(leftbump))  //reads high on pushbtn when not pressed
  {} //do nothing
  
  while(!(digitalRead(leftbump)))
  {}
}


//  --- FUNCTIONS TO INCREMENT ENCODER  ---
void leftEn() {
  lec++;
}

void rightEn() {
  rec++;
}

