#ifndef _BLUETOOTH_CONTROL_HEADER_
#define _BLUETOOTH_CONTROL_HEADER_

#include <dmoto.h>
class ManualControl {
	public:
		void move(dmoto robot, char charPressed);
};

#endif
