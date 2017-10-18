#ifndef _INPUTPIN_H_
#define _INPUTPIN_H_
class InputPin:public Pin{
private:
    int pullResistor;
public:
    InputPin(int id, int direction, int pullResistor):Pin(id,direction)
    {
        this->pullResistor=pullResistor;
    }
    ~InputPin(void);
    void setDirection();
};
#endif // INPUTPIN_H
