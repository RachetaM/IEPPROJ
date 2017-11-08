
#ifndef PIN
#define PIN
#include "bcm2835.h"
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER
class Pin {
protected:
	int id;
	int direction;
public:
    void settoPin(uint8_t level);
	void changeDirection();
	Pin(int id, int direction);
	~Pin(void);

};
	// Contents of the header file here
#endif  // HEADER_FILE

