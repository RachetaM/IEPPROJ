#include <QCoreApplication>
#include "bcm2835.h"
#define PIN 3

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

Pin::Pin(int id,int direction)
{
    this->id=id;
    this->direction=direction;
}

Pin::~Pin(void)
{

}


class OutputPin:public Pin{
public:
   OutputPin(int id,int direction):Pin(id,direction){};
    ~OutputPin(void);
   void setDirection();
};

OutputPin::~OutputPin(void)
{

}

void OutputPin::setDirection()
{

   volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPFSEL0/4 + (id/10);
    uint8_t   shift = (id % 10) * 3;
    uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
    uint32_t  value = BCM2835_GPIO_FSEL_OUTP << shift;
    bcm2835_peri_set_bits(paddr, value, mask);
}

int Pin::getDirection()
{
    volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPLEV0/4 + id/32;
    uint8_t shift = id % 32;
    uint32_t value = bcm2835_peri_read(paddr);
    return (value & (1 << shift)) ? HIGH : LOW;
}

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

void InputPin::setDirection()
{

}

InputPin::~InputPin(){

}

void Pin::changeDirection(){
    if(direction==1)
    {
        volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPFSEL0/4 + (id/10);
         uint8_t   shift = (id % 10) * 3;
         uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
         uint32_t  value = BCM2835_GPIO_FSEL_OUTP << shift;
         bcm2835_peri_set_bits(paddr, value, mask);
    }
    else
    {
        volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPFSEL0/4 + (id/10);
        uint8_t   shift = (id % 10) * 3;
        uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
        uint32_t  value = BCM2835_GPIO_FSEL_INPT << shift;
        bcm2835_peri_set_bits(paddr, value, mask);
    }
}

int main(int argc, char *argv[])
{/*
    QCoreApplication a(argc, argv);

    return a.exec();*/

/*Blink led*/
    if (!bcm2835_init())
         return 1;

       // Set the pin to be an output
       bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

       // Blink
       while (1)
       {
       // Turn it on
       bcm2835_gpio_write(PIN, HIGH);

       // wait a bit
       bcm2835_delay(500);

       // turn it off
       bcm2835_gpio_write(PIN, LOW);

       // wait a bit
       bcm2835_delay(500);
       }
       bcm2835_close();
       return 0;
}
