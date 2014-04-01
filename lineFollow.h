//Line Following Code
#include <Arduino.h>
#include "constants.h"

void forward(int speed);

//Follow a straight line and then continue driving in that straight line when range less than some value, until bump wall
boolean lineFollow(){
	int certain = 0;
	
	while(true){
		forward(PWMspeed*1.2);
		 
		//while side sensors white, forward - happy loop

		//while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH ) 
		//{
			//because random high value spikes
			if(analogRead(IRpin) > 380)		//if it thinks it's close
				certain += 1;				//increase certainty
			else if(certain>0)				//if not close, reduce certainty (butnot below 0)
				certain -= 10;
			
			//if high IR value and high certainty
			if((analogRead(IRpin) > 380 && certain >10)|| digitalRead(leftbump) == 0 || digitalRead(rightbump)== 0)   // the "if we're close" loop (doesn't leave till bumpers happen)
			{ 
				Serial.println(analogRead(IRpin));
				forward(PWMspeed*.8);	//slow down
				
				//wait for touch - active low sensors

				while(digitalRead(leftbump) == 1 && digitalRead(rightbump)==1) //while both bumpers are no
                    {            //modified linefollow:
					if(!(analogRead(right) < RTHRESH && analogRead(left) < LTHRESH)) //if we're not on the horizontal line 
							{

								while(analogRead(right) < RTHRESH)
								 {
								  
								   analogWrite(E2,115);
								   analogWrite(E1,100);
								 }
								 
								   
								 while(analogRead(left) < LTHRESH)
								 {
								   digitalWrite(M2, LOW);
								   analogWrite(E1,100);
								   analogWrite(E2,115);
								 }
							}	 		

                                 delay(5); //so not insane amount of loops
                     }
                    forward(0);		//stop on touch
				return true; 

                }     		
				
			
		 //end of the happy loop
		 
		  //if right black, turn until white then a fudge factor more
		 while(analogRead(right) < RTHRESH)
		 {
		   //turn left wheel back
		   //digitalWrite(M1, LOW);
		   analogWrite(E2,120);
		   analogWrite(E1,100);
		 }
		 
		 //same left   
		 while(analogRead(left) < LTHRESH)
		 {
		   digitalWrite(M2, LOW);
		   analogWrite(E1,100);
		   analogWrite(E2,120);
		 }
		 
		 delay(10); 
		 
	}//end while true

	Serial.println("exiting linefollow");
} //end line follow


