//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

boolean approachBall() {
  
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  lineFollow()
  
  boolean ball = ObjGrab();
   
  if (ball == true) {
    destination=3
    backward(100)
    delay(100)
    backward(0)
    return (true) 
  }
  
  if (ball == false)
    backward(0) //stop
    //enter shuffle functions
  
}


boolean ObjGrab() {
  tilt.write(TILThoriz);
  grip.write(GRIPclose)
  
  if (pressureSensor==true){
    return(true)
  }
  else(){
    return(false)
  }
 
}


