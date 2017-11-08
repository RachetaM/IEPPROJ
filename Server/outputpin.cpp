#include "outputpin.h"
#include "bcm2835.h"
#include "Pin.h"
OutputPin::~OutputPin(void)
{

}

void OutputPin::settoPin(uint8_t level)
{
	if (level)
		bcm2835_gpio_set(level);
	else
		bcm2835_gpio_clr(level);
}

OutputPin::OutputPin(int id, int direction) :Pin(id, direction) {
    //set pin as output in register. we made this every time when a new output object is created
    volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPFSEL0 / 4 + (id / 10);
    uint8_t   shift = (id % 10) * 3;
    uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
    uint32_t  value = BCM2835_GPIO_FSEL_INPT << shift;
    bcm2835_peri_set_bits(paddr, value, mask);
}

int OutputPin::getDirection()
{
	return direction;
}
