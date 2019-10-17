//https://robolinkakademi.org/2019/10/03/rodeo-arduino-ile-isik-izleyen-robot-yapimi/
#include "towardsLight.h";

Light::Light() {
	ldrRemove = 0;
}

void Light::moveTowards(dmoto robot) {
	ldrRemove = abs(robot.LdrRightValue() - robot.LdrLeftValue());  
	/*Serial.print(robot.LdrRightValue());  
	Serial.print("  ");  
	Serial.print(robot.LdrLeftValue());  
	Serial.print("  ");  
	Serial.println(ldrRemove);*/  
	delay(30);  
	if (robot.LdrRightValue() > robot.LdrLeftValue() && ldrRemove > 80) {  
		robot.Left(150,70);
	}  
	if (robot.LdrRightValue() < robot.LdrLeftValue() && ldrRemove > 80) {  
		robot.Right(70,150);
	}  
	if (ldrRemove < 80) {  
		robot.Forward(150);
	}
}