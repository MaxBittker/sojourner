// Enumeration of locations on the field of play, as well as two control signals (fail and restart)
typedef enum {bucket, zero, one, two, centre, fail, restart}location;  

#include <Arduino.h>

// Get location from BT
location getLoc(){
  
	int waitTime = 5000;
	long nowTime = millis();
  
	location target = fail;
	int ch = '?';
        
        // wait and read from BT when available for set waitTime, until character other than '?' received
	while((millis() - nowTime) < waitTime && ch == '?') {  
		if(Serial.available()) {
			ch = Serial.read();
                        Serial.write(ch);
                 } 
	}

        Serial.write(ch);
        
        // set location to return based on number input
	switch(ch) {
		case '0': target = zero;
				break;
		case '1': target = one;
				break;
		case '2': target = two;
				break;
                case 'C': target = restart;
                                 break;
	} 

	return target;
}
