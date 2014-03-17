//Line Following Code
#include <Arduino.h>
#include "constants.h"


void forward(int speed);

//Follow a straight line and then continue driving in that straight line when range less than some value
boolean lineFollow(){
  
 
  while(digitalRead(leftbump) == 1 && digitalRead(rightbump)== 1){

    if(analogRead(IRpin) < 380){

        forward(PWMspeed/2);
        //digitalWrite(E1,PWMspeed/2); //if close, cut 
        //digitalWrite(E2,speed/2);
    } 

 //   digitalWrite(M1, HIGH); //go
  //  digitalWrite(M2, HIGH); 
     forward(PWMspeed);
    //while side sensors white, forward 
     while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH && analogRead(middle) && digitalRead(leftbump) == 0 && digitalRead(rightbump)==0) //loop for when happy
     {
     
        if(analogRead(IRpin) < 380)
        forward(PWMspeed/2);
    
        else
         forward(PWMspeed);
  } //end of the happy loop

    // Serial.print("\n");
    // Serial.print(leftval);
    // Serial.print("   ");
    // Serial.print(centerval);
    // Serial.print("   ");
    // Serial.print(rightval);
    
    //TODO - inneficient way to correct, do it on the fly more?
      //pause
    // analogWrite(E1, 0);
     //analogWrite(E2, 0);
     //delay(300);
     
      //if right black, turn until white then a fudge factor more
     while(analogRead(right) < RTHRESH)
     {
       
       //turn left wheel back
       digitalWrite(M1, LOW);
       analogWrite(E2,PWMspeed);
       analogWrite(E1,PWMspeed);
     }
     
     //same left   
     while(analogRead(left) < LTHRESH)
     {
       digitalWrite(M2, LOW);
       analogWrite(E1,PWMspeed);
       analogWrite(E2,PWMspeed);
     }
     
     delay(75); 
     
  }//end while
Serial.println("exiting linefollow");
} //end line follow



