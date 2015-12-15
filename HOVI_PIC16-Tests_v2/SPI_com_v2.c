#include <pic16f1827.h>
#include "hovi_SPI_v2.h"

void SendSpiChar(unsigned char data) {
    if(SSP1IF == 1) {
        __delay_ms(2);
        SSP1IF = 0;
    }
    SSP1BUF = data;
    while(SSP1IF == 0);
    SSP1IF = 0;
}


unsigned char ExchangeSpiChar(unsigned char data) {
    if(SSP1IF == 1) {
        __delay_ms(2);
        SSP1IF = 0;
    }
    SSP1BUF = data;
    while(SSP1IF == 0);
    SSP1IF = 0;
    return (SSP1BUF);
}

unsigned char ExchangeSpi2char(unsigned char data, unsigned char data2) {
    NOP();
    unsigned int SPI_word = 0;
    if(SSP1IF == 1) {
        __delay_ms(2);
        SSP1IF = 0;
    }
    SSP1BUF = data;
    while(SSP1IF == 0);
    SSP1IF = 0;
    SPI_word = SSP1BUF;
    SPI_word <<= 8;
    SSP1BUF = data2;
    while(SSP1IF == 0);
    SSP1IF = 0;
    SPI_word |= SSP1BUF;
    NOP();
    if(SPI_word == PIXY_FRAME_OBJ) {
        NOP();
    }
    return (SPI_word);
}