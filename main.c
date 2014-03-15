//Group 35  (MB, MW, SW)

#include "enum_stuff.h"

#include <Servo.h>
Servo pan, grip, tilt;

//servo saved positions
#define GRIPclose 200
#define GRIPopen 80
#define TILThoriz 70
#define TILTup 160
#define PANcentre 90
#define PANleft 30

//set motor pin values
int E1 = 6;
int M1 = 7;
int E2 = 5;
int M2 = 4;

//set bumper pins
int leftbump = 2;   //wait push button
int rightbump = 3;

//Line Sensor pins
int left = A0;
int middle = A1;
int right = A2;

//uncalibrated!
#define LTHRESH 420
#define MTHRESH 475
#define RTHRESH 350

//encoder pins
int le = 11;
int re = 12;

//counters
int lec = 0;
int rec = 0;

//IR setup
int IRpin = A4;

int PWMspeed = 100;  //(40%)  (PWMspeed)

location currentPos = centre;
location destination;

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
  
  //interrupts
  attachInterrupt(0, leftEn, RISING);
  attachInterrupt(1, rightEn, RISING);
  
  //Serial.begin(9600);
  Serial.begin(115200);
  
  waitButton();
  
  //spin and find target - or take input

}


void loop(){
  
    destination = getLoc();
    if(destination == fail)
      destination = findLoc();
  
    //navigate(currentPos, destination);

}//end loop

void pivot(int angle)
{
  analogWrite(E1, PWMspeed);
  analogWrite(E2, PWMspeed); 
  
  delay(500);
  
  if (angle > 0)
  {
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);
  }  
  else if (angle < 0)
  {
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
  }

  delay(10*abs(angle));
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

