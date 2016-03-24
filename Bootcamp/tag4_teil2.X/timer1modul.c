/* 
 * File:   timer1modul.c
 * Author: PRINCESS
 *
 * Created on 02. September 2015, 18:38
 */

#include <stdio.h>
#include <stdlib.h>

#define LedRot RB3 // auf 1 damits geht -> active high
#define PinTrig RB4 // output active low

/*
 * 
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


#define _XTAL_FREQ 4000000


unsigned int timebreak = 0;
unsigned int zeit = 0;
float s = 0;

void init(){

    //0 = 0 Volt, 1 = Versorgungsspannung
    PORTA = 0;
    PORTB = 0b00010000;
    //1=input/0=output
    TRISA = 0;
    TRISB = 0b00000001;
    //0= digital, 1= analog
    ANSELA = 0;
    ANSELB = 0;
    // Frequenz für PIC
    OSCCON = 0b01101011; // 4MHz - Messgenauigkeit
    // Timer
    T1CON = 0b000000001; // bis ca. 65ms
    T1GCON = 0b11000000;
    TMR1GIF = 0;
    
    
    
}

void timer(void){
    
    
    
    while(1){
        
        
      /*  
        timebreak = 33286;
        
        TMR1L = timebreak;
        timebreak >>= 8; // rechtsshift
        TMR1H = timebreak;
        
        TMR1ON = 1; // Timer einschalten
        
        while(TMR1IF == 0); // Timer 1 Iterrupt Flag macht nix, wenns nicht voll ist
        
        TMR1IF = 0;
        
      */  
        // LedRot ^= LedRot; // ändert status auf das jeweils andere -> XOR
        // wenn 0 auf 1 || wenn 1 auf 0
        
        
        PinTrig = 0;
        
        while(TMR1GIF == 0);
        TMR1GIF = 0;
        zeit = TMR1H;
        zeit <<= 8;
        zeit |= TMR1L;
        TMR1H = 0;
        TMR1L = 0;
        
        PinTrig = 1;
        
        s = (0.000343 * zeit);
        NOP();
        if(s > 1){
            LedRot = 1;
        }else{
            LedRot = 0;
        }

        __delay_ms(200);
        NOP();
    }
    
}


int main(int argc, char** argv) {

    
    init();
    
    timer();
    
    
    return (EXIT_SUCCESS);
}

