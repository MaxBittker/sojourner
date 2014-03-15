//Line Following Code

//Follow a straight line and then continue driving in that straight line when range less than some value
lineFollow() {
  
  while(digitalRead(leftBump) == 0 && digitalRead(rightBump)==0){

    if(getRange() < 380){

forward(speed/2);
//digitalWrite(E1,speed/2); //if close, cut speed
//digitalWrite(E2,speed/2);
    } 

 //   digitalWrite(M1, HIGH); //go
  //  digitalWrite(M2, HIGH); 
     forward(speed);
    //while side sensors white, forward 
     while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH && analogRead(center) && digitalRead(leftBump) == 0 && digitalRead(rightBump)==0) //loop for when happy
     {
     
        if(getRange() < 380)
        forward(speed/2);
    
        else
         forward(speed);
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
       digitalWrite(M2, LOW);
       analogWrite(E2,speed);
       analogWrite(E1,speed);
       turntime = 100;
     }
     
     //same left   
     while(analogRead(left) < LTHRESH)
     {
       digitalWrite(M1, LOW);
       analogWrite(E1,speed);
       analogWrite(E2,speed);
       turntime = 100;
     }
     
     delay(turntime); 
     
  }//end while

} //end line follow


int getRange()
{
  return(analogRead(IRpin)); 
}
   
