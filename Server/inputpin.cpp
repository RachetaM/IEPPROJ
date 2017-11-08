#include "inputpin.h"
#include "bcm2835.h"
#include<stdio.h>
void settoPin(uint8_t level)
{

}

uint8_t InputPin::getPullUp()
{
	volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPLEV0 / 4 + id / 32;
	uint8_t shift = id % 32;
	uint32_t value = bcm2835_peri_read(paddr);
	return (value & (1 << shift)) ? HIGH : LOW;
}

InputPin::~InputPin() {

}

InputPin::InputPin(int id, int direction) :Pin(id, direction) {
	this->pullupState = getPullUp();
    //set pin as input in registers
    volatile uint32_t* paddr = bcm2835_gpio + BCM2835_GPFSEL0 / 4 + (id / 10);
    uint8_t   shift = (id % 10) * 3;
    uint32_t  mask = BCM2835_GPIO_FSEL_MASK << shift;
    uint32_t  value = BCM2835_GPIO_FSEL_OUTP << shift;
    bcm2835_peri_set_bits(paddr, value, mask);
}
