#pragma once
#include "PWM.h"
#include "bcm2835.h"

PWM ::~PWM(){

}

int PWM :: getFreq(){
    return freq;
}

int PWM :: getFactor(){
    return factor;
}

int PWM ::PWM(int freq, int factor){
    this->freq=freq;
    this->factor=factor;
}

void PWM :: setFactor(int factorsec){
    int scalat=0;
    scalat=freq*factorsec/100;
    if (   bcm2835_clk == MAP_FAILED
         || bcm2835_pwm == MAP_FAILED)
      return; /* bcm2835_init() failed or not root */

    if (channel == 0)
        bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM0_DATA, scalat);
    else if (channel == 1)
        bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM1_DATA, scalat);
}

void PWM :: setFreq(){
    if (   bcm2835_clk == MAP_FAILED
        || bcm2835_pwm == MAP_FAILED)
      return; /* bcm2835_init() failed or not root */

    /* From Gerts code */
    freq &= 0xfff;
    /* Stop PWM clock */
    bcm2835_peri_write(bcm2835_clk + BCM2835_PWMCLK_CNTL, BCM2835_PWM_PASSWRD | 0x01);
    bcm2835_delay(110); /* Prevents clock going slow */
    /* Wait for the clock to be not busy */
    while ((bcm2835_peri_read(bcm2835_clk + BCM2835_PWMCLK_CNTL) & 0x80) != 0)
    bcm2835_delay(1);
    /* set the clock divider and enable PWM clock */
    bcm2835_peri_write(bcm2835_clk + BCM2835_PWMCLK_DIV, BCM2835_PWM_PASSWRD | (freq << 12));
    bcm2835_peri_write(bcm2835_clk + BCM2835_PWMCLK_CNTL, BCM2835_PWM_PASSWRD | 0x11); /* Source=osc and enable */
}

void PWM :: setRange(){
    if (   bcm2835_clk == MAP_FAILED
         || bcm2835_pwm == MAP_FAILED)
      return; /* bcm2835_init() failed or not root */

    if (channel == 0)
        bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM0_RANGE, factor);
    else if (channel == 1)
        bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM1_RANGE, factor);
}

void PWM :: setMode(uint8_t channel, uint8_t markspace, uint8_t enabled){
    if (   bcm2835_clk == MAP_FAILED
         || bcm2835_pwm == MAP_FAILED)
      return; /* bcm2835_init() failed or not root */

    uint32_t control = bcm2835_peri_read(bcm2835_pwm + BCM2835_PWM_CONTROL);

    if (channel == 0)
      {
        if (markspace)
      control |= BCM2835_PWM0_MS_MODE;
        else
      control &= ~BCM2835_PWM0_MS_MODE;
        if (enabled)
      control |= BCM2835_PWM0_ENABLE;
        else
      control &= ~BCM2835_PWM0_ENABLE;
      }
    else if (channel == 1)
      {
        if (markspace)
      control |= BCM2835_PWM1_MS_MODE;
        else
      control &= ~BCM2835_PWM1_MS_MODE;
        if (enabled)
      control |= BCM2835_PWM1_ENABLE;
        else
      control &= ~BCM2835_PWM1_ENABLE;
      }

    /* If you use the barrier here, wierd things happen, and the commands dont work */
    bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM_CONTROL, control);
    /*  bcm2835_peri_write_nb(bcm2835_pwm + BCM2835_PWM_CONTROL, BCM2835_PWM0_ENABLE | BCM2835_PWM1_ENABLE | BCM2835_PWM0_MS_MODE | BCM2835_PWM1_MS_MODE); */
}
