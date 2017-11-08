#include "Blink.h"
#include "Pin.h"
#include "outputpin.h"
#include "inputpin.h"
#include "bcm2835.h"
using namespace std;

#define idpin RPI_GPIO_P1_11
int blinkwithobjects()
{
    OutputPin *x = new OutputPin(idpin, BCM2835_GPIO_FSEL_OUTP);
	if (!bcm2835_init())
		return 1;
	while (1)
	{
        x->settoPin(HIGH);
		bcm2835_delay(500);
        x->settoPin(LOW);
		bcm2835_delay(500);
	}
	bcm2835_close();
    delete x;
	return 0;
}
