typedef enum {bucket, zero, one, two, centre, fail, restart}location; //counts ccw from 0  

#include <Arduino.h>

//function to get location from bluetooth
location getLoc(){
  
	int waitTime = 5000;
	long nowTime = millis();
  
	location target = fail;
	int ch = '?';
  
	while((millis() - nowTime) < waitTime && ch == '?') {  
		if(Serial.available()) {
			ch = Serial.read();
                        Serial.write(ch);
                 } 
	}

        Serial.write(ch);
    
	switch(ch) {
		case '0': target = zero;
				break;
		case '1': target = one;
				break;
		case '2': target = two;
				break;
                case 'c': target = restart;
                                 break;
	} 

	return target;
  
}

////doesn't need to be written yet b/c only used if bluetooth fails
//location findLoc(){
//  
//  location target = fail;
//  
//  //drives forward and turns until it finds the blinking target
//  
//  return target;
//  
//}

