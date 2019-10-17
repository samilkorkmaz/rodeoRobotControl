//https://robolinkakademi.org/2019/10/02/rodeo-arduino-ile-engelden-kacan-robot-yapimi/
#include "obstacleAvoidance.h"
#define SPEED (100)
#define SPEED_TURN (70)
void Obstacle::avoid(dmoto robot) {
	//Serial.println(robot.distance());
	if (robot.distance() < 15) {
		robot.Backward(SPEED);
		delay(SPEED);
		robot.Right(SPEED_TURN,SPEED_TURN);
		delay(250);
	} else { 
		robot.Forward(SPEED);
	}
}
