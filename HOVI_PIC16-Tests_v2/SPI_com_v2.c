#include <pic16f1827.h>
#include "hovi_SPI_v2.h"

void send_SPI_char(unsigned char data) {
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = data;
    NOP();
    while (SSP1STATbits.BF == 1);
}


unsigned char exchange_SPI_char(unsigned char data) {
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = data;
    NOP();
    while (SSP1STATbits.BF == 1);
    return (SSP1BUF);
}

unsigned char exchange_SPI_2char(unsigned char data, unsigned char data2) {

    unsigned char SPI_word = 0;
    // BF = Buffer Full
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = data;
    NOP();
    while (SSP1STATbits.BF == 1);
    SPI_word = SSP1BUF;
    SPI_word <<= 8;
    SSP1CON1bits.WCOL = 0;
    SSP1BUF = data2;
    NOP();
    while (SSP1STATbits.BF == 1);
    SPI_word |= SSP1BUF;
    return (SPI_word);
}