//Group 35  (MB, MW, SW)

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
int center = A1;
int right = A2;

//uncalibrated!
#define LTHRESH 420
#define CTHRESH 475
#define RTHRESH 350

//encoder pins
int le = 11;
int re = 12;

//counters
int lec = 0;
int rec = 0;

//IR setup
int IRpin = A4;

int speed = 100;  //(40%)  (PWMspeed)

enum location {one, two, three, bucket, centre};

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
  pinMode(center, INPUT);
  pinMode(right, INPUT);
  
  //interrupts
  attachInterrupt(0, leftEn, RISING);
  attachInterrupt(1, rightEn, RISING);
  
  Serial.begin(9600);
  
  waitButton();
  
  //spin and find target - or take input

}


void loop(){
  
  //wait for a while, get destination from bluetooth: destination = getLoc();
  
  // have a case for if that doesn't work: destination = findLoc();
  navigate(currentPos, destination);
  
  

}//end loop

int navigate(location start, location end) {
  
  //case statement to determine which direction to face and drive
  
  //lineFollow
  
}

location getLoc(){
  
  //function to get location from bluetooth
  
  
}

location findLoc(){
  
  location target;
  
  //accepts as an overide/wait the bluetooth command to know which target
  //OR drives forward and turns until it finds the blinking target
  
  return target;
  
}

void pivot(int angle)
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, PWMspeed);
  analogWrite(E2, PWMspeed); 
  
  delay(1500);
  
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

  analogWrite(E1, PWMspeed);
  analogWrite(E2, PWMspeed);
  delay(10*abs(angle));
}

void forward(int speed) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
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

