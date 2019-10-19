//Rodeo Kodlama Robotu. https://www.robolinkmarket.com/rodeo-kodlama-robotu-bt.html
#include <dmoto.h> //https://github.com/RobolinkTeknoloji/dMoto.lib/blob/master/dmoto.h
#include <SoftwareSerial.h> 

#include "lineFollow.h"
#include "towardsLight.h"
#include "obstacleAvoidance.h"
#include "ManualControl.h"

#define NO_COMMAND     ('0')
#define FOLLOW_LINE    ('E')
#define FOLLOW_LIGHT   ('T')
#define AVOID_OBSTACLE ('A')
#define MANUAL_CONTROL ('M')

#define MODE_IDLE           (0)
#define MODE_FOLLOW_LINE    (1)
#define MODE_FOLLOW_LIGHT   (2)
#define MODE_AVOID_OBSTACLE (3)
#define MODE_MANUAL_CONTROL (4)

SoftwareSerial myBlue(0, 1); // RX, TX pins of Arduino Nano. 

dmoto robot;
/*Line line;
Light light;
Obstacle obstacle;*/
ManualControl manual;

int runningMode = MODE_IDLE;
int prevRunningMode = MODE_IDLE;
char charPressed = NO_COMMAND;
char prevCharPressed = NO_COMMAND;

void setup() {
	myBlue.begin(9600); // For Bluetooth	
	//Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor
	
	robot.pinSet();
	robot.Stop();

 pinMode(btEnablePin,OUTPUT); 
 digitalWrite(btEnablePin,LOW);
}

void buzzWithParams(int freq_Hz, int duration_ms) {
	tone(buzzerPin, freq_Hz); //buzzer pin is defined and set to output in dmoto lib
	delay(duration_ms);
	noTone(buzzerPin);
}

void buzz() {
	buzzWithParams(2000, 1000);
}

void loop() {
  delay(10);
  charPressed = NO_COMMAND;
  if(myBlue.available() > 0){ // Checks whether data is coming from the bluetooth
		charPressed = myBlue.read(); // Reads the data from bluetooth
   runningMode = MODE_MANUAL_CONTROL; //TODO
    /*if (NO_COMMAND == charPressed) {
			runningMode = MODE_IDLE;
		}
		if (FOLLOW_LINE == charPressed) {
			runningMode = MODE_FOLLOW_LINE;
		}
		if (FOLLOW_LIGHT == charPressed) {
			runningMode = MODE_FOLLOW_LIGHT;
		}
		if (AVOID_OBSTACLE == charPressed) {
			runningMode = MODE_AVOID_OBSTACLE;
		}
		if (MANUAL_CONTROL == charPressed) {
			runningMode = MODE_MANUAL_CONTROL;
		}*/
		/*if(runningMode != prevRunningMode) {
			robot.Stop();
			buzz();			
			prevRunningMode = runningMode;
		}*/
	}

  /*if(MODE_IDLE == runningMode) {
    digitalWrite(ledPin, HIGH);
    buzz();
    digitalWrite(ledPin, LOW);
    delay(1000);
  }*/
  
	/*if(MODE_FOLLOW_LINE == runningMode) {
		line.follow(robot);
	}
	if(MODE_FOLLOW_LIGHT == runningMode) {
		light.moveTowards(robot);
	}
	if(MODE_AVOID_OBSTACLE == runningMode) {
		obstacle.avoid(robot);
	}*/
	if(MODE_MANUAL_CONTROL == runningMode) {
    if(NO_COMMAND != charPressed) {
		  /*if(MODE_MANUAL_CONTROL != charPressed) {//After robot is set to manual mode, a direction char must have been pressed 
			  if(charPressed != prevCharPressed) {
				  buzzWithParams(1500, 10);
				  prevCharPressed = charPressed;
			  }*/                   
			  manual.move(robot, charPressed);  
		  }
    } else {
      robot.Stop();
    }
}
