#include "exempleuart.h"
#include"uart.h"
#include "serial.h"

void uartexe(){
    Uart *x =new Uart("/dev/ttyAMA0");
    unsigned char tx_buffer[20];
    unsigned char *p_tx_buffer;
    unsigned char rx_buffer[256];
    int rx_length;
    int count ;
    p_tx_buffer = &tx_buffer[0];
    *p_tx_buffer++ = 'H';
    *p_tx_buffer++ = 'e';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'l';
    *p_tx_buffer++ = 'o';
    count=x->writeFisier(&tx_buffer[0], (p_tx_buffer - &tx_buffer[0]));
    if (count < 0)
       {
           printf("UART TX error\n");
       }
    rx_length = x->readFisier((void*)rx_buffer, 255);
    if (rx_length < 0)
       {
           /*eroare*/
       }
       else if (rx_length == 0)
       {
           /*nu există dată*/
       }
       else
       {
           rx_buffer[rx_length] = '\0';
           printf("%i bytes read : %s\n", rx_length, rx_buffer);
       }
    delete x;

}
