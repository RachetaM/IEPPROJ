#ifndef PWM_H
#define PWM_H

class PWM{
private :
    int freq, factor;

public :
    PWM(int freq, int factor);
    ~PWM(void);
    int getFreq();
    int getFactor();
    void setFreq();
    void setFactor(int factorsec);
    void setRange();
    void setMode(uint8_t channel, uint8_t markspace, uint8_t enabled);
};


#endif // PWM_H
