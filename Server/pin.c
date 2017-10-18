#include"pin.h"
#include "bcm2835.h"


Pin::Pin(int id,int direction)
{
    this->id=id;
    this->direction=direction;
}

Pin::~Pin(void)
{

}

int Pin::getDirection()
{
    volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPLEV0/4 + id/32;
    uint8_t shift = id % 32;
    uint32_t value = bcm2835_peri_read(paddr);
    return (value & (1 << shift)) ? HIGH : LOW;
}
