//Line Following Code
#include <Arduino.h>
#include "constants.h"


void forward(int speed);

//Follow a straight line and then continue driving in that straight line when range less than some value
boolean lineFollow(){
  int certain = 0;
 
  while(digitalRead(leftbump) == 1 && digitalRead(rightbump)== 1){

   /* if(analogRead(IRpin) > 300){
        
        forward(PWMspeed*.8);
        //digitalWrite(E1,PWMspeed/2); //if close, cut 
        //digitalWrite(E2,speed/2);
    } 
*/
 //   digitalWrite(M1, HIGH); //go
  //  digitalWrite(M2, HIGH); 
     forward(PWMspeed);
    //while side sensors white, forward 
     while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH && digitalRead(leftbump) == 1 && digitalRead(rightbump)==1) //loop for when happy
     {
     
        if(analogRead(IRpin) > 350)
       certain +=1;
        else 
        {if(certain>0)
        certain  +=-10;
        }
        if(analogRead(IRpin) > 350 && certain >20)
        { 
    
          Serial.println(analogRead(IRpin));
        forward(PWMspeed*.8);
        while(digitalRead(leftbump) == 1 && digitalRead(rightbump)==1)
        {delay(10);}
        forward(0);
        return true;}
    
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


