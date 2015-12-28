/* 
 * File:   2015-09-15_Labor_Ultraschallsensor.c
 * Author: Lucas
 *
 * Created on 15. September 2015, 08:47
 */


// PIC16F1827 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

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




#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

#define _XTAL_FREQ 4000000

#define trigger RB4
#define LED_RED RB3
#define LED_YELLOW RB2
#define LED_GREEN RB1

unsigned int time = 0;
float distance = 0;

void init(void) {
    PORTA = 0b00000000;
    PORTB = 0b00010010;     //RB4 is low active trigger of
                            //ultrasonnicmodule
                            //RB1 LED_GREEN is low active
    TRISA = 0b00000000;
    TRISB = 0b00000001;     //RB0 is echo from ultrasonnicmodule
    ANSELA = 0;
    ANSELB = 0;
    OSCCON = 0b01101011;    //4MHz
//TIMER1
    T1CON =  0b00000001;    //Source: Fosc/4, Prescaler: 1:1
    T1GCON = 0b11000000;    //T1G pin as Input, active high
}

void measure(void) {
    trigger = 0;
    while(TMR1GIF == 0);
    TMR1GIF = 0;
    time = 0;
    time = TMR1H;
    time <<= 8;
    time |= TMR1L;
    TMR1L = 0;
    TMR1H = 0;
    distance = 0;
    distance = ((0.000343 * time) / 2);
    trigger = 1;
    if(distance < 0.2) {
        LED_RED = 1;
        LED_YELLOW = 0;
        LED_GREEN = 1;
    }
    else if(distance >= 0.2 && distance < 0.5) {
        LED_RED = 0;
        LED_YELLOW = 1;
        LED_GREEN = 1;
    }
    else if(distance >= 0.5) {
        LED_RED = 0;
        LED_YELLOW = 0;
        LED_GREEN = 0;
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

