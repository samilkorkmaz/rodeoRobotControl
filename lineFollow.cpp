//https://robolinkakademi.org/2019/09/26/rodeoarduino-ile-robot-izleyen-robot-yapimi/
#include "lineFollow.h"

void Line::follow(dmoto robot) {
	/*Serial.print(robot.sensor1());
	Serial.print(robot.sensor2());
	Serial.println(robot.sensor3());*/
	delay(10);

	if (robot.sensor1() == 0 && robot.sensor2() == 1 && robot.sensor3() == 0) {
		robot.Forward(80);
	}
	if (robot.sensor1() == 1 && robot.sensor2() == 1 && robot.sensor3() == 1) {
		robot.Forward(80);
	}
	if (robot.sensor1() == 0 && robot.sensor2() == 0 && robot.sensor3() == 0) {
		robot.Forward(80);
	}
	if (robot.sensor1() == 1 && robot.sensor2() == 0 && robot.sensor3() == 0) {
		robot.Right(0,80);
	}
	if (robot.sensor1() == 1 && robot.sensor2() == 1 && robot.sensor3() == 0) {
		robot.Right(0,80);
	}
    if (robot.sensor1() == 0 && robot.sensor2() == 0 && robot.sensor3() == 1) {
		robot.Left(80,0);
    }
    if (robot.sensor1() == 0 && robot.sensor2() == 1 && robot.sensor3() == 1) {
		robot.Left(80,0);
    }  
}
