
#ifndef INPUTPIN_H
#define INPUTPIN_H
# include "Pin.h"
#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER
class InputPin :public Pin {
private:
    int pullResistor;
public:
    InputPin(int id, int direction, int pullResistor) :Pin(id, direction) {
        this->pullResistor = pullResistor;
    }
    ~InputPin(void);
    void setDirection();
};

#endif // INPUTPIN_H
