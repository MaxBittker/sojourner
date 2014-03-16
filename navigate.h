  
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
    
    switch(destination){
          case zero:
            while(analogRead(right)>RTHRESH)
                {
                //spin right while all sensors are white (possibly with speed as a function of time)
                  analogWrite(E1, speed/2);
                  analogWrite(E2, speed/2); 

                  digitalWrite(M1, LOW);
                  digitalWrite(M2, HIGH);
 
                }
                while(analogRead(middle)>MTHRESH) //while middle sensor reads white
                  {
                    analogWrite(E1, speed/4);
                    analogWrite(E2, speed)/4; 

                    if(analogRead(left)>LTHRESH){
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
             while(analogRead(left)>LTHRESH)
                {
                //spin left (possibly with speed as a function of time)
                    analogWrite(E1, speed/2);
                    analogWrite(E2, speed/2); 

                    digitalWrite(M1, HIGH);
                    digitalWrite(M2, LOW);
                }
                while(analogRead(middle)>MTHRESH)
                  {
                    analogWrite(E1, speed/4);
                    analogWrite(E2, speed)/4; 

                    if(analogRead(right)>RTHRESH){
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
  forward(speed);

   while(analogRead(left)>LTHRESH && analogRead(middle)>MTHRESH && analogRead(right)>RTHRESH){
{delay(10); //possibly reduce speed as a fn of time!
}
forward(speed/5);
 while(analogRead(middle)>MTHRESH)
 {delay(10)}
forward(0);
return;

   }

}
