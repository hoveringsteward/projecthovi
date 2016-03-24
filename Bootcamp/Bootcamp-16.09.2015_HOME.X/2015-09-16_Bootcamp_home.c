/* 
 * File:   2015-09-16_Bootcamp_home.c
 * Author: Lucas
 *
 * Created on 16. September 2015, 17:26
 */

#include <stdio.h>
#include <stdlib.h>



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


/*
 * 
 */

#define _XTA_FREQ       1000000
#define Blue_up         RB0
#define Yellow_down     RB5
#define LED_YELLOW      RB2
#define LED_GREEN       RB1

unsigned int time =         32000;
unsigned int time_write =   0;

void init(void) {
    PORTA = 0;
    PORTB = 0b00100011;         //active low Buttons on RB5&0, RB1-LED active low
    TRISA = 0;
    TRISB = 0b00100001;         //Buttons in RB5&0
    ANSELA = 0;
    ANSELB = 0;
    nWPUEN = 0;
    WPUB = 0b00100001;          //Buttons in RB5&0
    OSCCON = 0b01011011;        //1MHz
    T1CON = 0b00110001;         //1:8 prescaler, Fosc/4
    CCP1CON = 0b00001011;       //Special event trigger
    GIE = 1;                    //Enabling global interrupts
    CCP1IE = 1;                 //Enabling interrupts of CCP1 module
}

void toggle(void) {
    LED_YELLOW = !LED_YELLOW;
    LED_GREEN = !LED_GREEN;
}

void check_buttons(void) {          //Is also possible as interrupt
    if (Blue_up == 0) {
        time += 2500;               //Adding 10ms
        time_write = time;
        CCPR1L = time_write;
        time_write >>= 8;
        CCPR1H = time_write;
    } else if (Yellow_down == 0) {
        time -= 2500;               //Subtracting 10ms
        time_write = time;
        CCPR1L = time_write;
        time_write >>= 8;
        CCPR1H = time_write;
    }
}

interrupt void isr() {              //Service routine for interrupts
    if(CCP1IF == 1) {               //TMR1 is reset automatically
        CCP1IF = 0;
        toggle();
    }
}

int main(int argc, char** argv) {
    init();
    while(1) {
        check_buttons();
    }
    return (EXIT_SUCCESS);
}

