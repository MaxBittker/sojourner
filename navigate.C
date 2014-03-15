  
/* navigate.c */

#include "lineFollow.c"
#include "approachBall.c"
#include "approachBucket.c"
#include "turn180.c"


boolean navigate(location start, location destination)  {
  
  if( start == centre) //begins at center
  {
    //TODO logic to spin past a certain number of lines, 
    
    switch(destination){
          case zero:
            while(AnalogRead(left)>LTHRESH && AnalogRead(middle)>MTHRESH && AnalogRead(right)>RTHRESH)
                {
                //spin right (possibly with speed as a function of time)
                }
                while(AnalogRead(middle)>MTHRESH)
                  {
                //spin right slowly 
                    if(AnalogRead(left)>LTHRESH)
                        {FIX IT} //went too far :(
                 }
            lineFollow();
            approachBall();
            return: navigate(destination,bucket);
            break;
          case one:
            lineFollow();
            approachBall();
            return: navigate(destination, bucket);
            break; 

          case two:
             while(AnalogRead(left)>LTHRESH && AnalogRead(middle)>MTHRESH && AnalogRead(right)>RTHRESH)
                {
                //spin left (possibly with speed as a function of time)
                }
                while(AnalogRead(middle)>MTHRESH)
                  {
                //spin right slowly 
                    if(AnalogRead(right)>RTHRESH)
                        {FIX IT} //went too far :(
                 }
            lineFollow();
            approachBall();
            return: navigate(destination,bucket);
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
    if(startLocation == bucket)//if we're at a basket location
      {
        switch(destination){
          case zero:
            pivot(-140);
            braveForray(0); //angle right
            lineFollow();
            approachBall();
            return: navigate(destination,bucket);
            break;
          case one:
        
            turn180();
            lineFollow();
            approachBall();
            return: navigate(destination, bucket);
            break; 

          case two:
            pivot(140);
            braveForray(1); //angle left
            lineFollow();
            approachBall();

            return: navigate(destination,bucket);
            break;

             default:
          //error
          return false;
          break;
        }
      }
    else //if we're at a ball location
      {
        
         switch (startLocation) {
      case zero: //bucket is to the right
          pivot(140);
          braveForray(1); //(angle left);
          lineFollow();
         return: approachBucket();

        break;
      case two:    //bucket is to the left

         pivot(-140);
         braveForray(0); //angle right
         lineFollow();

        return: approachBucket();

        break;
      case one:    //across from bucket

        turn180();
        lineFollow();
        
        return: approachBucket();
        break;

      default:
          //error
          return false;
          break;
        
      }
    
  }
  
}
