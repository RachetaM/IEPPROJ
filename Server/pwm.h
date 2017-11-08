#ifndef PWM_H
#define PWM_H
#include "bcm2835.h"
class PWM{
private :
    int freq, factor;

public :
    PWM(int freq, int factor);
    ~PWM(void);
    int getFreq();
    int getFactor();
    void setFreq(int frecv);
    void setFactor(int factorsec,uint8_t channel);
    void setRange(uint8_t channel);
    void setMode(uint8_t channel, uint8_t markspace, uint8_t enabled);
};
#endif // PWM_H
