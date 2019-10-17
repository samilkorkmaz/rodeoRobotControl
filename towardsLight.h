//https://robolinkakademi.org/2019/10/03/rodeo-arduino-ile-isik-izleyen-robot-yapimi/
#ifndef _TOWARDS_LIGHT_HEADER_
#define _TOWARDS_LIGHT_HEADER_

#include <dmoto.h>
class Light {
	public:
		Light();
		void moveTowards(dmoto robot);
	private:
		float ldrRemove;
};

#endif
