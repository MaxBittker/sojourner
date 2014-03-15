boolean approachBucket() {
  
  tilt.write(TILTup);
  
  lineFollow()
  
  grip.write(GRIPopen)
  
  backward(100)
    delay(100)
    backward(0)
    
  return (true)
 
