#include <xc.h>
#include "init.h"


/*---------------------------------------------------------------------------*/
/* Beginning of userroutines.                                                   */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Initfunctions">

/* Calls all needed inits                                                    */
/*---------------------------------------------------------------------------*/
void Fkt_Init(void) {
    Fkt_InitPort();
    Fkt_InitTris();
    Fkt_InitAnsel();
    Fkt_InitOsc();
    Fkt_InitUart();
    Fkt_InitSpi();
    Fkt_InitTimer();
    Fkt_InitInterrupt();
}

void Fkt_InitPort(void) {
    PORTA = 0b00010000;
    PORTB = 0b00001000;
    PORTC = 0b00000000;
    PORTD = 0b00001000;
    PORTE = 0b00000000;
}

void Fkt_InitTris(void) {
    TRISA = 0b00000000;
    TRISB = 0b00010000;
    TRISC = 0b10010001;
    TRISD = 0b01010000;
    TRISE = 0b00000000;
}

void Fkt_InitAnsel(void) {
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    ANSELE = 0b00000000;
}

void Fkt_InitOsc(void) {
    OSCCON = 0b01110111;    // 16MHz, INTOSC, stable HFOSC, Internal osc-block
}

void Fkt_InitUart(void) {
    
}

void Fkt_InitSpi(void) {
    
}

void Fkt_InitTimer(void) {
    /* Timer 3, used to measure time of gaer signal                          */
    /*-----------------------------------------------------------------------*/
//    T3CON = 0b000000111;    // source fosc/4, 1:1, no sync, 16-Bit Mode, TMR3 on
//    T3GCON = 0b110000000;   // high active, no toggle, no single pulse, gatepin
    //GE, GPOL, GTM, GSPM, GGOnDONE, GVAL, GSS
    T3GCONbits.TMR3GE = 1;
    T3GCONbits.T3GSPM = 0;
    T3GCONbits.T3GTM = 0;
    T3GCONbits.T3GPOL = 1;
    T3GCONbits.T3GSS = 0b00;
    
    T3CONbits.TMR3CS = 0b00;
    T3CONbits.T3CKPS = 0b00;
    T3CONbits.nT3SYNC = 1;
    T3CONbits.TMR3ON = 1;
}

void Fkt_InitInterrupt(void) {
    GIE = 1;
    PEIE = 1;
    /* Enabling interrupt for Timer 3 gate                                   */
    TMR3GIE = 1;        // Direct access due to conflicts with PIE3bits.TMR3GIE
    TMR3IE = 1;
    
}
// </editor-fold>
