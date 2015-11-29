/*
 * File:   Pixy_SPI-Test.c
 * Author: Lucas
 *
 * Created on 6. November 2015, 13:21
 */

#include "hovi_v2.h"
#include <pic.h>

// PIC16F1827 Configuration Bit Settings

// 'C' source line config statements


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)



void init() {
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    TRISA = 0b00000001;
    TRISB = 0b00000110;
    ANSELA = 0;
    ANSELB = 0;
    OSCCON = 0b01101011;
    APFCON0bits.RXDTSEL = 1;
//////SPI
    SSP1STAT = 0b00000000;      //Rising edge;
    SSP1CON1 = 0b00000001;      //FOSC/16
//    SSP1CON3 = 0b00000000;    //Only Bit 4 in slave mode
//////UART
    SPBRGH = 0;
    SPBRGL = 25;
    BRGH = 1;
    BRG16 = 0;
    TXSTAbits.SYNC = 0;
    RCSTAbits.SPEN = 1;
    TXSTAbits.TXEN = 1;
    RCSTAbits.CREN = 1;
}

void main(void) {
    init();
    while (1) {
        get_frame();
        send_UART_word(exchange_SPI_2char(PIXY_SYNC, DUMMY));
        set_LED();
        
    }
    return;
}