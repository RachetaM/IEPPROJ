#include "spi.h"
#include "bcm2835.h"
#include "serial.h"

Spiclass::Spiclass(uint8_t spiMode, uint16_t clockDivider, uint8_t chipSelect, uint8_t polarityMode, uint8_t bitOrder):Serial(){
    this->spiMode=spiMode;
    this->chipSelect=chipSelect;
    this->clockDivider=clockDivider;
    this->polarityMode=polarityMode;
    this->bitOrder=bitOrder;

    //SPI configuration
    bcm2835_spi_setBitOrder(bitOrder);      // The default
    bcm2835_spi_setDataMode(spiMode);       // The default
    bcm2835_spi_setClockDivider(clockDivider); // The default
    bcm2835_spi_chipSelect(chipSelect);        // The default
    bcm2835_spi_setChipSelectPolarity(chipSelect, polarityMode);// The default
}

int Spiclass::spiStart(){
   return bcm2835_spi_begin();
}

void Spiclass::spiEnd(){
    bcm2835_spi_end();
}

uint8_t Spiclass::transfer(uint8_t data){
   return bcm2835_spi_transfer(data);
}

Spiclass::~Spiclass(){

}
