  
/* navigate.c */

boolean approachBall();
void pivot(int angle);
boolean braveForray(int expectedDirection);
boolean approachBucket();

boolean navigate(location start, location destination)  {
  
  if( start == centre) //begins at center
  {
    //TODO logic to spin past a certain number of lines, 
    
    switch(destination){
          case zero:
            while(analogRead(left)>LTHRESH && analogRead(middle)>MTHRESH && analogRead(right)>RTHRESH)
                {
                //spin right (possibly with speed as a function of time)
                }
                while(analogRead(middle)>MTHRESH)
                  {
                //spin right slowly 
                    if(analogRead(left)>LTHRESH){}
                        //{//FIX IT //went too far :(
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
             while(analogRead(left)>LTHRESH && analogRead(middle)>MTHRESH && analogRead(right)>RTHRESH)
                {
                //spin left (possibly with speed as a function of time)
                }
                while(analogRead(middle)>MTHRESH)
                  {
                //spin right slowly 
                    if(analogRead(right)>RTHRESH){}
                        //{FIX IT} //went too far :(
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
  //TODO
}
