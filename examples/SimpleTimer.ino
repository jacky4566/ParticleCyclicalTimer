//This timer will return true between the hours of 8:43 and 21:40 Local time. 

#include "ParticleCyclicalTimer/ParticleCyclicalTimer.h"

cycleTimer timer1((byte)8,(byte)43, (byte)21, (byte)40);

void setup()
{
Time.zone(-6);
}
void loop(){
	Serial.print(Time.hour(Time.now()));
	Serial.print(":");
	Serial.print(Time.minute(Time.now()));
	Serial.print(":");
	Serial.println(Time.second(Time.now()));

	if (timer1.isActive()){
		Serial.println("Timer active");
	}

	delay(1000);
}
