#ifndef _OUTPUTPIN_H_
#define _OUTPUTPIN_H_
#include "Pin.h"
#include "bcm2835.h"
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

class OutputPin :public Pin {
public:
	OutputPin(int id, int direction);
	int getDirection();
	~OutputPin(void);
    void settoPin(uint8_t level);
};
#endif // OUTPUTPIN_H
