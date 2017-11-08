
#ifndef INPUTPIN_H
#define INPUTPIN_H
# include "Pin.h"
#include"bcm2835.h"
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER
class InputPin :public Pin {
private:
     uint8_t pullupState;
public:
	InputPin(int id, int direction);
	~InputPin(void);
    void settoPin(uint8_t level);
    uint8_t getPullUp();
};

#endif // INPUTPIN_H
