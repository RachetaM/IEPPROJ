#include"outputpin.h"
#include "bcm2835.h"

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
