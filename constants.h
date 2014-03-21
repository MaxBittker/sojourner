
//servo saved positions
#define GRIPclose 200
#define GRIPopen 80
#define TILThoriz 70
#define TILTup 160
#define PANcentre 90
#define PANleft 30

//set motor pin values
#define E1 6
#define M1 7
#define E2 5
#define M2 4

//set bumper pins
#define leftbump 2 //wait push button
#define rightbump 3

//Line Sensor pins
#define left A0
#define middle A1
#define right A2

//calibrated to 331 table
//#define LTHRESH 430
//#define MTHRESH 400
//#define RTHRESH 350
#define LTHRESH 400
#define MTHRESH 400
#define RTHRESH 390

//encoder pins
#define le 11
#define re 12

//IR setup
#define IRpin A4

#define PWMspeed 100  //(40%)  (PWMspeed)


//encoder vs. angle
#define encCounts 11
#define turnAngle 90
