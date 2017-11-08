#include "spiprogram.h"
#include "spi.h"
#include "bcm2835.h"
#include <stdio.h>

int spiExemple(){
    Spiclass *x = new Spiclass(BCM2835_SPI_MODE0,BCM2835_SPI_CLOCK_DIVIDER_65536,BCM2835_SPI_CS0,LOW,BCM2835_SPI_BIT_ORDER_MSBFIRST);
    if (!bcm2835_init())
       {
         printf("bcm2835_init failed. Are you running as root??\n");
         return 1;
       }
    if (!x->spiStart())
       {
         printf("bcm2835_spi_begin failed. Are you running as root??\n");
         return 1;
       }
    uint8_t send_data = 0x23;
    uint8_t read_data = x->transfer(send_data);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
      if (send_data != read_data)
        printf("Do you have the loopback from MOSI to MISO connected?\n");
    x->spiEnd();
    bcm2835_close();
    delete x;
}
