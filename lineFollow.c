//Line Following Code

//Follow a straight line and then continue driving in that straight line when range less than some value
lineFollow() {
  
  while(getRange() < 380)
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH); 
     
    //while side sensors white, forward 
     while(analogRead(right) > RTHRESH && analogRead(left) > LTHRESH && analogRead(center))
     {
      analogWrite(E1, speed);
      analogWrite(E2, speed);
     }
  
    // Serial.print("\n");
    // Serial.print(leftval);
    // Serial.print("   ");
    // Serial.print(centerval);
    // Serial.print("   ");
    // Serial.print(rightval);
    
    //TODO - inneficient way to correct, do it on the fly more?
      //pause
     analogWrite(E1, 0);
     analogWrite(E2, 0);
     delay(300);
     
      //if right black, turn until white then a fudge factor more
     while(analogRead(right) < RTHRESH)
     {
       //turn left wheel back
       digitalWrite(M2, LOW);
       analogWrite(E2,spd);
       analogWrite(E1,spd);
       turntime = 100;
     }
     
     //same left   
     while(analogRead(left) < LTHRESH)
     {
       digitalWrite(M1, LOW);
       analogWrite(E1,spd);
       analogWrite(E2,spd);
       turntime = 100;
     }
     
     delay(turntime); 
     
  }//end while

} //end line follow


int getRange()
{
  return(analogRead(IRpin)); 
}
   
