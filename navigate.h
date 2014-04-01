
/* navigate.c */

boolean approachBall();
void pivot(int angle);
void forward(int speed);

boolean braveForray(int expectedDirection);
void Across(long wait, long gaptime);
void oneeighty();
boolean approachBucket();

extern void waitButton();
//a function which uses switch cases and helper functions to handle navigation from A to B
location navigate(location start, location destination)  {

  if( start == centre) //cases for starting at center
  {
     
    Serial.println("navigating from start to " ); //prints current journey
    Serial.print(destination-1); 

    switch(destination){
    case zero: 


      analogWrite(E1, PWMspeed*.6);
      analogWrite(E2, PWMspeed*.6); 

      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);

      delay(300); //get off line to make sure a line sensed isn't the one we were on

      while(analogRead(right)>RTHRESH)
      {
        //spin right while right sensor reads white (possibly with speed as a function of time)
        delay(5);

      }
      //Serial.println("right saw black" );
      while(analogRead(middle)>MTHRESH) //while middle sensor reads white
      { 
        delay(10);

        if(analogRead(left)<LTHRESH){
          Serial.println("left saw black,fixing" );
          digitalWrite(M1, HIGH); //a second chance if it misses the line
          digitalWrite(M2, LOW);
        }
      }
       forward(0);

      delay(100);
      //stop and wait for inertia to settle

      approachBall(); //passes off control to an approach function

      return navigate(destination, bucket);
      break;
    case one:
      approachBall();  //passes off control to an approach function
      return navigate(destination, bucket);
      break; 

    case two:
      analogWrite(E1, PWMspeed*.6);
      analogWrite(E2, PWMspeed*.6); 

      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      delay(300); //get off line  
      while(analogRead(left)>LTHRESH)
      {
        //spin left 
        delay(5);
      }
      //Serial.println("left saw black" );

      while(analogRead(middle)>MTHRESH)
      {
        delay(5);
        if(analogRead(right)<RTHRESH){
          Serial.println("right saw black,fixing" );
          digitalWrite(M1, LOW); //second chance if it misses
          digitalWrite(M2, HIGH);
        }
      }
      forward(0);
      delay(100);
       //passes off control to an approach function
      approachBall();
      return navigate(destination,bucket);
      break;

    default:
       Serial.println("fail" );
       return fail;
      break;

    }
    lineFollow();
    //passes off control to an approach function
    approachBall();

    navigate(destination,bucket); //always goes to bucket after it gets the ball

    return bucket; //returns to main after 

  }

  else //6 cases
  {
    if(start == bucket)//if we're at a basket location
    {
      switch(destination){
      case zero:
        Serial.println("navigating to zero");
        forward(0);
        pivot(-165);
       delay(300);
        braveForray(0); //angle right
        approachBall();
        return navigate(destination,bucket);
        break;
      case one:
        Serial.println("navigating to one");
        oneeighty();
        Across(1200,1000);
        approachBall();
        return navigate(destination, bucket);
        break; 

      case two:
        Serial.println("navigating to two");
        forward(0);
        pivot(150);
        delay(300);
        braveForray(1); //angle left
        approachBall();

        return navigate(destination,bucket);
        break;

      default:
        //error
        return fail;
        break;
      }
    }
    else //if we're at a ball location
    {

      switch (start) {
      case zero: //bucket is to the right
        pivot(160);
        braveForray(1); //(angle left);
        approachBucket();
        return bucket;
        break;
      case two:    //bucket is to the left
        pivot(-150);
        braveForray(0); //angle right
        approachBucket();
        return bucket;
        break;
      case one:    //across from bucket
        oneeighty();
        Across(1000,1000);
        approachBucket();
        return bucket;
        break;
      default:
        //error
        return fail;
        break;

      }

    }

  }
}  //end nav


boolean braveForray(int expectedDirection){ //0=right 1=left
  forward(PWMspeed);

  while(analogRead(left)>LTHRESH && analogRead(middle)>MTHRESH && analogRead(right)>RTHRESH){ //all white
    delay(10); //possibly reduce speed as a fn of time!
    forward(PWMspeed);
      

      if(expectedDirection == 0){ //expecting to turn right

       while(analogRead(right)>RTHRESH)
        delay(10); //wait for right sensor

      delay(200); // then overshoot
        //turn right

      analogWrite(E1, PWMspeed*.6);
      analogWrite(E2, PWMspeed*.6); 

      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);


      while(analogRead(middle)>MTHRESH) //while middle sensor reads white
        { 
          delay(5);

         if(analogRead(left)<LTHRESH){
            Serial.println("left saw black,fixing" );
            digitalWrite(M1, HIGH); //second chance if it misses
            digitalWrite(M2, LOW);
          }
       }

    }

    else
    {

      while(analogRead(left)>LTHRESH)
        delay(10);
        
      delay(200); // then overshoot
        //turn left

      analogWrite(E1, PWMspeed*.6);
      analogWrite(E2, PWMspeed*.6); 

      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);


      while(analogRead(middle)>MTHRESH) //while middle sensor reads white
      { 
        delay(5);

        if(analogRead(right)<RTHRESH){
          Serial.println("right saw black,fixing" );
          digitalWrite(M1, LOW); //second chance if it misses
          digitalWrite(M2, HIGH);
        }
      }
        
        
    }
 
    

  }
     forward(0);
	 delay(200);
   return(true);
}


void Across(long wait, long gaptime){
 long timestart = millis();
  while(millis() < timestart + wait){ 
		forward(PWMspeed);
		 
		//while side sensors white, forward - happy loop
		while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH) 
		{
			delay(10);
		
		} //end of the happy loop
		 
		  //if right black, turn until white then a fudge factor more
		  while(analogRead(right) < RTHRESH)
		 {
		   //turn left wheel back
		   //digitalWrite(M1, LOW);
		   analogWrite(E2,140);
		   analogWrite(E1,100);
		 }
		 
		 //same left   
		 while(analogRead(left) < LTHRESH)
		 {
		   digitalWrite(M2, LOW);
		   analogWrite(E1,100);
		   analogWrite(E2,140);
		 }

		 
		 delay(10); 
		 
	}//end while true
	Serial.println("starting Gap");

     
 while(millis() < timestart + wait +gaptime){ 
if(  analogRead(right) < RTHRESH && analogRead(left) < LTHRESH &&   analogRead(middle) < MTHRESH)
   delay(400);
    break;
}

	Serial.println("exiting Across");

}
void oneeighty( ){

 analogWrite(E1, PWMspeed*.65);
      analogWrite(E2, PWMspeed*.65); 

      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      delay(450); //get off line  
      while(analogRead(left)>LTHRESH)
      {
        //spin left 
        delay(5);
      }
      Serial.println("left saw black" );

      while(analogRead(middle)>MTHRESH)
      {
        delay(5);
        if(analogRead(right)<RTHRESH){
          Serial.println("right saw black,fixing" );
          digitalWrite(M1, LOW); //second chance if it misses
          digitalWrite(M2, HIGH);
        }
      }
            forward(0);
	      delay(200);

}
