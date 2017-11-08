#include "Pin.h"
#include "bcm2835.h"
#include "pwm.h"
#include "inputpin.h"
#include "outputpin.h"

#define pin1 RPI_GPIO_P1_12
#define pin2 RPI_GPIO_P1_15
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024

int exepwmwithclass(){

   //Set input pin for button
   InputPin  *c = new InputPin(pin2,BCM2835_GPIO_FSEL_INPT);
   //Set output pin for led
   OutputPin *a = new OutputPin(pin1, BCM2835_GPIO_FSEL_ALT5);
   //PWM declare with a freq and a range
   PWM *p = new PWM (BCM2835_PWM_CLOCK_DIVIDER_16,RANGE);
   int factorumplere=0;
   //save freqvency.
   p->setMode(PWM_CHANNEL,1,1);
   //save range
   p->setRange(PWM_CHANNEL);
   while(1)
   {
       //check if the button is pressed
       while(c->getPullUp())
       {
           if(c->getPullUp())
           {
               //increase data which is send with 10
               factorumplere+=10;
               //set facotr to chennel
               p->setFactor(factorumplere,PWM_CHANNEL);
               bcm2835_delay(1);
           }
       }
   }
   bcm2835_close();
   //destructors are called because we didn't need these objectes.
   delete a;
   delete c;
   delete p;
   return 0;
}
