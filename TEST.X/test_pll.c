/*
 * File:   test_pll.c
 * Author: Lucas
 *
 * Created on 2. Februar 2016, 21:58
 */


#include <xc.h>


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
#pragma config PLLEN = OFF       // PLL Enable (4x PLL enabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#define LED PORTBbits.RB3
#define _XTAL_FREQ 8000000

void Init(void) {
    //PORT
    PORTA = 0b00000000;
    PORTB = 0b00000010;
    //TRIS
    TRISA = 0b00000000;
    TRISB = 0b00100001;
    //ANSEL
    ANSELA = 0;
    ANSELB = 0;
    //OSCILLATOR
    OSCCON = 0b01110000;
    //TIMER
    T1CONbits.T1CKPS = 0b11;
    T1CONbits.TMR1CS = 0b00;
    T1CONbits.TMR1ON = 1;
}


void main(void) {
    Init();
    while(1) {
        LED = 1;
        __delay_us(1900);
        LED = 0;
        __delay_us(18100);
    }
    return;
}
