#include "ManualControl.h"

#define MOVE_STOP     ('S')
#define MOVE_FORWARD  ('F')
#define MOVE_BACKWARD ('B')
#define MOVE_LEFT     ('L')
#define MOVE_RIGHT    ('R')

#define SPEED (100)

void ManualControl::move(dmoto robot, char charPressed) {
	if(MOVE_FORWARD == charPressed) {
		robot.Forward(SPEED);
	}
	if(MOVE_BACKWARD == charPressed) {
		robot.Backward(SPEED);
	}
	if(MOVE_LEFT == charPressed) {
		robot.Right(SPEED,SPEED);
	}
	if(MOVE_RIGHT == charPressed) {
		robot.Left(SPEED,SPEED);
	}
	if(MOVE_STOP == charPressed) {
		robot.Stop();
	}
}
