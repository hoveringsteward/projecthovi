#include <xc.h>
#include "init.h"

void Fkt_init(void) {
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    TRISA = 0b00000000;
    TRISB = 0b00000010;
    ANSELA = 0;
    ANSELB = 0;
    OSCCON = 0b01101011;        //4MHz, INTOSC
    SDO1SEL = 1;
//////SPI
    SSP1STAT = 0b00000000;      //Rising edge;
    SSP1CON1 = 0b00100001;      //SPI Master FOSC/16
//    SSP1CON3 = 0b00000000;    //Only Bit 4 in slave mode
}