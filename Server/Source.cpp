#include<iostream>
#include<conio.h>
#include "Pin.h"
#include "outputpin.h"
#include "inputpin.h"
#include "bcm2835.h"
#include "Blink.h"
#include "pwmexewithclas.h"
#include "spiprogram.h"
using namespace std;

#define idpin RPI_GPIO_P1_11
int main()
{
    //blinkwithobjects();
    //exepwmwithclass();
    spiExemple();
    return 0;
}
