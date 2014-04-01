// File of constants that more than one of our other files need

//servo saved positions
#define GRIPclose 115
#define GRIPopen 80
#define TILThoriz 70
#define TILTgrab 75
#define TILTdrop 110
#define TILTup 160
#define PANcentre 100
#define PANleft 30

//motor pin values
#define E1 6
#define M1 7
#define E2 5
#define M2 4

//bumper pins
#define leftbump 2 //wait push button
#define rightbump 3

//line sensor pins
#define left A0
#define middle A1
#define right A2

//light thresholds for line folloring
#define LTHRESH 400
#define MTHRESH 400
#define RTHRESH 390

//encoder pin
#define re 12

//IR setup
#define IRpin A4

//main speed
#define PWMspeed 160

//encoder vs. angle - calibrated with a 90 degree turn
#define encCounts 11
#define turnAngle 90
