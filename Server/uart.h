#ifndef UART_H
#define UART_H
#include "serial.h"
#include <unistd.h>
#include <fcntl.h>
class Uart:public Serial{
private:
    char path[20];
    int desc;


public:
    Uart(char*path);
    ~Uart();
    int openFisier(char*path,mode_t Mode);
    int writeFisier(const void *buf, size_t count);
    int readFisier(void *buf, size_t count);
    int closeFisier(int descriptor);

};
#endif // UART_H
