#ifndef SPI_H
#define SPI_H
#include "bcm2835.h"
#include "serial.h"
class Spiclass:public Serial{
private:
    uint8_t spiMode;
    uint16_t clockDivider;
    uint8_t chipSelect;
    uint8_t polarityMode;
    uint8_t bitOrder;
public:
    Spiclass(uint8_t spiMode,uint16_t clockDivider,uint8_t chipSelect,uint8_t polarityMode,uint8_t bitOrder);
    ~Spiclass();
    uint8_t transfer(uint8_t data);
    int spiStart();
    void spiEnd();
};
#endif // SPI_H
