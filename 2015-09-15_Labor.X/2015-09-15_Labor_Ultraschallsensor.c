/* 
 * File:   2015-09-15_Labor_Ultraschallsensor.c
 * Author: Lucas
 *
 * Created on 15. September 2015, 08:47
 */


#include <xc.h>

/*---------------------------------------------------------------------------*/
/* Beginning of ConfigurationBits.                                           */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="ConfigurationBits">
// Configuration bits: selected in the GUI
// CONFIG1H
#pragma config IESO = OFF    // Internal/External Oscillator Switchover bit->Oscillator Switchover mode disabled
#pragma config PLLCFG = OFF    // 4X PLL Enable->Oscillator used directly
#pragma config PRICLKEN = OFF    // Primary clock enable bit->Primary clock can be disabled by software
#pragma config FOSC = INTIO67    // Oscillator Selection bits->Internal oscillator block
#pragma config FCMEN = OFF    // Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor disabled

// CONFIG2L
#pragma config BOREN = SBORDIS    // Brown-out Reset Enable bits->Brown-out Reset enabled in hardware only (SBOREN is disabled)
#pragma config BORV = 190    // Brown Out Reset Voltage bits->VBOR set to 1.90 V nominal
#pragma config PWRTEN = OFF    // Power-up Timer Enable bit->Power up timer disabled

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits->1:32768
#pragma config WDTEN = OFF    // Watchdog Timer Enable bits->Watch dog timer is always disabled. SWDTEN has no effect.

// CONFIG3H
#pragma config CCP2MX = PORTC1    // CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config P2BMX = PORTD2    // ECCP2 B output mux bit->P2B is on RD2
#pragma config HFOFST = ON    // HFINTOSC Fast Start-up->HFINTOSC output and ready status are not delayed by the oscillator stable status
#pragma config PBADEN = ON    // PORTB A/D Enable bit->PORTB<5:0> pins are configured as analog input channels on Reset
#pragma config CCP3MX = PORTB5    // P3A/CCP3 Mux bit->P3A/CCP3 input/output is multiplexed with RB5
#pragma config MCLRE = EXTMCLR    // MCLR Pin Enable bit->MCLR pin enabled, RE3 input pin disabled
#pragma config T3CMX = PORTC0    // Timer3 Clock input mux bit->T3CKI is on RC0

// CONFIG4L
#pragma config LVP = OFF    // Single-Supply ICSP Enable bit->Single-Supply ICSP disabled
#pragma config STVREN = ON    // Stack Full/Underflow Reset Enable bit->Stack full/underflow will cause Reset
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF    // Background Debug->Disabled

// CONFIG5L
#pragma config CP2 = OFF    // Code Protection Block 2->Block 2 (008000-00BFFFh) not code-protected
#pragma config CP1 = OFF    // Code Protection Block 1->Block 1 (004000-007FFFh) not code-protected
#pragma config CP3 = OFF    // Code Protection Block 3->Block 3 (00C000-00FFFFh) not code-protected
#pragma config CP0 = OFF    // Code Protection Block 0->Block 0 (000800-003FFFh) not code-protected

// CONFIG5H
#pragma config CPB = OFF    // Boot Block Code Protection bit->Boot block (000000-0007FFh) not code-protected
#pragma config CPD = OFF    // Data EEPROM Code Protection bit->Data EEPROM not code-protected

// CONFIG6L
#pragma config WRT0 = OFF    // Write Protection Block 0->Block 0 (000800-003FFFh) not write-protected
#pragma config WRT1 = OFF    // Write Protection Block 1->Block 1 (004000-007FFFh) not write-protected
#pragma config WRT2 = OFF    // Write Protection Block 2->Block 2 (008000-00BFFFh) not write-protected
#pragma config WRT3 = OFF    // Write Protection Block 3->Block 3 (00C000-00FFFFh) not write-protected

// CONFIG6H
#pragma config WRTC = OFF    // Configuration Register Write Protection bit->Configuration registers (300000-3000FFh) not write-protected
#pragma config WRTD = OFF    // Data EEPROM Write Protection bit->Data EEPROM not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block (000000-0007FFh) not write-protected

// CONFIG7L
#pragma config EBTR3 = OFF    // Table Read Protection Block 3->Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF    // Table Read Protection Block 1->Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF    // Table Read Protection Block 2->Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
#pragma config EBTR0 = OFF    // Table Read Protection Block 0->Block 0 (000800-003FFFh) not protected from table reads executed in other blocks

// CONFIG7H
#pragma config EBTRB = OFF    // Boot Block Table Read Protection bit->Boot Block (000000-0007FFh) not protected from table reads executed in other blocks
// </editor-fold>



#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

#define _XTAL_FREQ 4000000

#define trigger PORTBbits.RB3
#define LED_RED PORTBbits.RB2
//#define LED_YELLOW RB2
//#define LED_GREEN RB1

unsigned int time = 0;
float distance = 0;

void init(void) {
    PORTA = 0b00000000;
    PORTB = 0b00001000;
    PORTC = 0b00000000;
    PORTD = 0b00001000;
    PORTE = 0b00000000;
    TRISA = 0b00000000;
    TRISB = 0b00010000;
    TRISC = 0b10010001;
    TRISD = 0b01010000;
    TRISE = 0b00000000;
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    ANSELE = 0b00000000;
    OSCCON = 0b01110111;
//    GIE = 1;
//    PEIE = 1;
//    /* Enabling interrupt for Timer 3 gate                              */
//    TMR3GIE = 1;
    
    T5GCONbits.TMR5GE = 1;
    T5GCONbits.T5GSPM = 0;
    T5GCONbits.T5GTM =  0;
    T5GCONbits.T5GPOL = 1;
    T5GCONbits.T5GSS =  0b00;
    //Timer 5 Controlregister
    T5CONbits.TMR5CS =  0b00;
    T5CONbits.T5CKPS =  0b00;
    T5CONbits.nT5SYNC = 1;
    T5CONbits.TMR5ON =  1;
}

void measure(void) {
    trigger = 0;
    while(TMR5GIF == 0);
    TMR5GIF = 0;
    time = 0;
    time = TMR5H;
    time <<= 8;
    time |= TMR5L;
    TMR5L = 0;
    TMR5H = 0;
    distance = 0;
    distance = ((0.000343 * time) / 2);
    trigger = 1;
    if(distance < 0.2) {
        LED_RED = 1;
    }
    else if(distance >= 0.2 && distance < 0.5) {
        LED_RED = 0;
    }
    else if(distance >= 0.5) {
        LED_RED = 0;
    }
    __delay_ms(20);
    NOP();
}

int main(int argc, char** argv) {
    init();
    while (1) {
        measure();
    }
    return (EXIT_SUCCESS);
}

