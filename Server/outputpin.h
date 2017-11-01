#ifndef _OUTPUTPIN_H_
#define _OUTPUTPIN_H_
#ifdef _MSC_VER
#pragma once
#include "Pin.h"
#endif  // _MSC_VER

class OutputPin :public Pin {
public:
    OutputPin(int id, int direction) :Pin(id, direction) {}
    ~OutputPin(void);
    void setDirection();
};
#endif // OUTPUTPIN_H
