/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                  */
/*                                                                 */
/* Created: 2017-02-06                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Display for error code and whishing "Guten Appetit" to the
 * guests; Name is sent by the digital menu
 * and for Error Messages
 */


// PIC16F1827 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include "main.h"


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
/*
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
*/
#define RS_LCD RA0 // reset?
#define R_W_LCD RA1 // read write?
#define E_LCD RA2 // enable?

#define DB0 RB0
#define DB1 RB1
#define DB2 RB2
#define DB3 RB3
#define DB4 RB4
#define DB5 RB5
#define DB6 RB6
#define DB7 RB7

#define _XTAL_FREQ 4000000


void init_LCD(void) {
    
    clear_LCD(); // added new line, if problems with testing
    
    port_LCD(0x00);
    RS_LCD = 0;
    __delay_ms(25);
    cmd_LCD(0x30);
    __delay_ms(5);
    cmd_LCD(0x30);
    __delay_ms(15);
    cmd_LCD(0x30);
    cmd_LCD(0x38); //function set
    cmd_LCD(0x0C); //display on,cursor off,blink off
    cmd_LCD(0x01); //clear display
    cmd_LCD(0x06); //entry mode, set increment
}

/*
void init() {
    // Versorungsspannung = 1 / 0 Volt = 0
    PORTA = 0;
    PORTB = 0;

    // Input = 1 / Output = 0
    TRISA = 0;
    TRISAbits.TRISA3 = 1;
    TRISB = 0;

    // Analog = 1 / Digital = 0
    ANSELA = 0;
    ANSELB = 0;

    //Frequenz 4MHz
    OSCCON = 0b01101011;
    init_LCD();
}
*/ 
void port_LCD (unsigned char a) {
    if (a & 1) DB0 = 1;
    else DB0 = 0;
    if (a & 2) DB1 = 1;
    else DB1 = 0;
    if (a & 4) DB2 = 1;
    else DB2 = 0;
    if (a & 8) DB3 = 1;
    else DB3 = 0;
    if (a & 16) DB4 = 1;
    else DB4 = 0;
    if (a & 32) DB5 = 1;
    else DB5 = 0;
    if (a & 64) DB6 = 1;
    else DB6 = 0;
    if (a & 128) DB7 = 1;
    else DB7 = 0;
}

void cmd_LCD(unsigned char a) {
    RS_LCD = 0; // => RS = 0
    port_LCD(a); //Data transfer
    E_LCD = 1; // => E = 1
    __delay_ms(5);
    E_LCD = 0; // => E = 0
}

void clear_LCD(void) {
    cmd_LCD(1);
}

void cursor_LCD(char a, char b) {
    if (a == 1)
        cmd_LCD(0x80 + b);
    else if (a == 2)
        cmd_LCD(0xC0 + b);
}

void write_letter_LCD(char a) {
    RS = 1; // => RS = 1
    port_LCD(a); //Data transfer
    E_LCD = 1; // => E = 1
    __delay_ms(4);
    E_LCD = 0; // => E = 04
}

void write_words_LCD(char *a) {
    int j;
    for (j = 0; a[j] != '\0'; j++)
        write_letter_LCD(a[j]);
}

//End LCD 8 Bit Interfacing Functions

void displayPrinter(char message[30], char name[30]) { // 'main'

    // message: Error message or Guten Appetit
    // name: Name of error or Name of guest
    // init();
    init_LCD();

    while (1) {
        cursor_LCD(1, 2);
        write_words_LCD(message);
        __delay_ms(2000);
        cursor_LCD(2, 4);
        write_words_LCD(name);
        __delay_ms(2000);
    }    
    // break??
    // if error message, maybe send code to admin interface
    return;
}
