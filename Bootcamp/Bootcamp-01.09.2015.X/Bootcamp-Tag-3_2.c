/*
 * File:   Bootcamp-Tag-3.c
 * Author: Lucas
 *
 * Created on 01. September 2015, 18:17
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

#define _XTAL_FREQ 4000000

#define TasterGelb RB5
#define TasterBlau RB0
#define LED_Rot    RB3
#define LED_Gelb   RB2
#define LED_Gruen  RB1

void init(void){
    PORTA = 0;
    PORTB = 0b00000010;
    TRISA = 0;
    TRISB = 0b00100001;
    ANSELA = 0;
    ANSELB = 0;
    nWPUEN = 0;
    WPUB = 0b00100001;
    OSCCON = 0b01101010;    //4MHz
}

void taster(void){
    while(1){
        LED_Rot = 1;
        NOP();
        LED_Rot = 0;
        NOP();
        NOP();
    }
    
}

int main(int argc, char** argv) {
    init();
    taster();
    return (EXIT_SUCCESS);
}

