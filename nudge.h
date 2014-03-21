enum nudge{left, right, success,bigleft, bigright, fail};  

#include <Arduino.h>

//function to get command from bluetooth
nudge getDirection(){
  
	int waitTime = 5000;
	long nowTime = millis();
  
	nudge direction = fail;
	int ch = '?';
  
	while((millis() - nowTime) < waitTime && ch == '?') {  
		if(Serial.available()) {
			ch = Serial.read();
                        Serial.write(ch);
                 } 
	}

        Serial.write(ch);
    
	switch(ch) {
		case 'l': direction = left;
				break;
		case 'r': direction = right;
				break;
		case 's': target = success; //ball has been caught
				break;
		case 'L':direction=bigleft;
		    break;
		case 'R':direction=bigright;
		    break;
	} 

	return direction;
  
}
