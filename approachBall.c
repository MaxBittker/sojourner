//when navigate returns a 1 and destination=0,1 or 2 - incoming (so case check outside)

boolean approachBall() {
  
  grip.write(GRIPopen);
  tilt.write(TILTup);
  
  //line follow until BOTH BUMPERS are hit (range finder to control speed?)
  
  boolean ball = ObjGrab();
   
  if (ball == true) {
    destination=3
    backup (small amount to allow turning)
  }
  
  if (ball == false)
    pause and enter shuffle functions by bluetooth
  
}


boolean ObjGrab() {
  tilt.write(TILThoriz);
  close gripper etc...
}


