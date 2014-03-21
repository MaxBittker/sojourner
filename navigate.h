  
/* navigate.c */

boolean approachBall();
void pivot(int angle);
void forward(int speed);

boolean braveForray(int expectedDirection);
boolean approachBucket();

boolean navigate(location start, location destination)  {
  
  if( start == centre) //begins at center
  {
    //TODO logic to spin past a certain number of lines, 
    Serial.println("navigating from start to " );
    Serial.print(destination-1);
    
    switch(destination){
          case zero:
                  analogWrite(E1, PWMspeed);
                  analogWrite(E2, PWMspeed); 

                  digitalWrite(M1, LOW);
                  digitalWrite(M2, HIGH);
                  
                  
                  delay(300); //get off line
            while(analogRead(right)>RTHRESH)
                {
                //spin right while right sensor reads white (possibly with speed as a function of time)
                delay(5);
 
                }
                Serial.println("right saw black" );
                while(analogRead(middle)>MTHRESH) //while middle sensor reads white
                  { 
                   delay(15);

                    if(analogRead(left)<LTHRESH){
                       Serial.println("left saw black,fixing" );
                       digitalWrite(M1, HIGH); //second chance if it misses
                       digitalWrite(M2, LOW);}
                 }
                   
            //lineFollow();
            approachBall();
            return navigate(destination,bucket);
            break;
          case one:
           // lineFollow();
            approachBall();
            return navigate(destination, bucket);
            break; 

          case two:
               analogWrite(E1, PWMspeed);
                    analogWrite(E2, PWMspeed); 

                    digitalWrite(M1, HIGH);
                    digitalWrite(M2, LOW);
                delay(300); //get off line  
             while(analogRead(left)>LTHRESH)
                {
                //spin left (possibly with speed as a function of time)
                 delay(10);
              }
              Serial.println("left saw black" );
              
                while(analogRead(middle)>MTHRESH)
                  {
                 delay(10);
                    if(analogRead(right)<RTHRESH){
                                           Serial.println("right saw black,fixing" );
                       digitalWrite(M1, LOW); //second chance if it misses
                       digitalWrite(M2, HIGH);}
                 }
            //lineFollow();
            approachBall();
            return navigate(destination,bucket);
            break;

          default:
          //error
          return false;
          break;

    }
    lineFollow();
    //passes off control to an approach function
    approachBall();
    
    navigate(destination,bucket); //always goes to bucket after it gets the ball
    
    return true; //returns to main after 
    
    }
    
  else //6 cases
  {
    if(start == bucket)//if we're at a basket location
      {
        switch(destination){
          case zero:
            pivot(-140);
            braveForray(0); //angle right
           // lineFollow();
            approachBall();
            return navigate(destination,bucket);
            break;
          case one:
        
            pivot(180);
           // lineFollow();
            approachBall();
            return navigate(destination, bucket);
            break; 

          case two:
            pivot(140);
            braveForray(1); //angle left
           // lineFollow();
            approachBall();

            return navigate(destination,bucket);
            break;

             default:
          //error
          return false;
          break;
        }
      }
    else //if we're at a ball location
      {
        
         switch (start) {
      case zero: //bucket is to the right
          pivot(140);
          braveForray(1); //(angle left);
         // lineFollow();
         return approachBucket();

        break;
      case two:    //bucket is to the left

         pivot(-140);
         braveForray(0); //angle right
         //lineFollow();

        return approachBucket();

        break;
      case one:    //across from bucket

        pivot(180);
       // lineFollow();
        
        return approachBucket();
        break;

      default:
          //error
          return false;
          break;
        
      }
    
  }
  
}
}  //end nav probably


boolean braveForray(int expectedDirection){
  forward(PWMspeed);

   while(analogRead(left)>LTHRESH && analogRead(middle)>MTHRESH && analogRead(right)>RTHRESH){
{delay(10); //possibly reduce speed as a fn of time!
}
forward(PWMspeed/5);
 while(analogRead(middle)>MTHRESH)
 {delay(10);}
forward(0);
return(true);

   }

}
