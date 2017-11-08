#include "serial.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "uart.h"
Uart::Uart(char*path):Serial(){
    strcpy(this->path,path);
    desc=openFisier(path, O_RDWR | O_NOCTTY | O_NDELAY);
    if (desc == -1)
    {
        printf("Error - Unable to open UART. Ensure it is not in use by another application\n");
    }

    struct termios options;
    tcgetattr(desc, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; //<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(desc, TCIFLUSH);
    tcsetattr(desc, TCSANOW, &options);
}

Uart::~Uart(){
  closeFisier(desc);
}

Uart::closeFisier(int descriptor){
    int id=-1;
    id=close(descriptor);
    return id;
}

int Uart::openFisier(char *path, mode_t Mode){
    int id=-1;
    id=open(path,Mode);
    return id;
}

int Uart::readFisier(void *buf, size_t count){
    int id=-1;
    if (desc != -1)
    {
        id=read(desc,(void*)buf,count);
    }
    return id;

}

int Uart::writeFisier(const void *buf, size_t count){
    int id=-1;
    if (desc != -1)
    {
        id=write(desc,&buf[0],count);
    }
    return id;
}

