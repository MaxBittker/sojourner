//recieves (destination,startLocation) from main

if( startLoc == 4) //begins at center
{
  //logic to spin past a certain number of lines, 
  
  
  lineFollow();
  //passes off control to an approach function
  approachBall();
  
  navigate(3,destination); //always goes to bucket (3) after it gets the ball
  
  return true; //returns to main after 
  
  }
  
else //6 cases
{
  if(startLocation == 3)//if we're at a basket location
    {
      
    }
  else //if we're at a ball location
    {
      
       switch (startLocation) {
    case 0: //bucket is to the left
    
      break;
    case 1:    //bucket is to the right
      
      break;
    case 2:    //across from bucket
      turn180();
      lineFollow();
      
      return: approachBucket();
      
      break;
   
    default:
      
      
    }
  
}
