//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

boolean approachBall() {
  
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  linefollow()
  
  boolean ball = ObjGrab();
   
  if (ball == true) {
    destination=3
    backup (small amount to allow turning)
    return (true) 
  }
  
  if (ball == false)
    pause and enter shuffle functions by bluetooth
  
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


