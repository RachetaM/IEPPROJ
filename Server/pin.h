#ifndef _PIN_H_
#define _PIN_H_
class Pin{
protected:
    int id;
    int direction;
public:
    void setDirection();
    int getDirection();
    void changeDirection();
    Pin(int id,int direction);
    ~Pin(void);
};
#endif // PIN_H
