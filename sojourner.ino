////////////////////////////
// ELEC299 - Winter2014
////////////////////////////
// Sojouner
//
// Group #: 35    (aka team 20)
//
// Group Members:
//    Morgan Williams  (10049857)
//    Max Bittker      (10049561)
//    Sam Webb         (
//
/////////////////////////////

//our other code files
#include "enum_stuff.h"
#include "lineFollow.h"
#include "navigate.h"
#include "approachBucket.h"
#include "approachBall.h"
#include "constants.h"

// Servo Setup
#include <Servo.h>
Servo pan, grip, tilt;

// encoder counters
int lec = 0;
int rec = 0;

location currentPos = centre;
location mainDest;

void setup(){
  
  //servo pin assignment
  grip.attach(10);
  tilt.attach(9);
  pan.attach(8);
  
  //set servo high, open, centered
  grip.write(GRIPopen);
  tilt.write(TILTup);
  pan.write(PANcentre);
  
  //motor pin assignmnet
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);
  
  //set motors forward and off
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  
  //light sensing pin assignment
  pinMode(left, INPUT);
  pinMode(middle, INPUT);
  pinMode(right, INPUT);
  pinMode(IRpin, INPUT);
  
  Serial.begin(115200);
}


void loop(){
  
    mainDest = getLoc();  //get location from BlueTooth
    
    //if the command to reset from the centre is called
    if (mainDest == restart) {
        Serial.println("restarting");
        currentPos = centre;
        mainDest = getLoc();
    }
    
    //if gets a location from BT
    if(mainDest !=fail)
       currentPos = navigate(currentPos, mainDest); // go to given location

}//end loop

// Pivot a given angle in degrees, either positive or negative
void pivot(int angle) 
{
  delay(100);
  
  // choose direction based on +/- of angle
  if (angle > 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  } else if (angle < 0) {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
  }

  int rec = 0;
  
  //calculate ratio of encoder counts to degrees of rotation
  float ratio = encCounts/(float)turnAngle;
  
  //set moto speed to 70% of max
  analogWrite(E1, PWMspeed*.7);
  analogWrite(E2, PWMspeed*.7);
    
  //turn the number of degrees
  while(rec < (int)(abs(angle)*ratio)) {    
      int re_old = digitalRead(re);
      while(digitalRead(re) == re_old){}
      rec++;    //increment every time the encoder changes
  }
  
  forward(0);
}

// Drive forward at a given speed
void forward(int speed) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, speed);
  analogWrite(E2, speed);  
}

// Drive backward at a given speed
void backward(int speed) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, speed);
  analogWrite(E2, speed);  
}
