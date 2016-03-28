/*
 * File:   lcd_main.c
 * Author: Gaensebluemchen
 *
 * Created on 26. März 2016, 13:09
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

#define RS RA0
#define R_W RA1
#define E RA2

#define DB0 RB0
#define DB1 RB1
#define DB2 RB2
#define DB3 RB3
#define DB4 RB4
#define DB5 RB5
#define DB6 RB6
#define DB7 RB7

#define _XTAL_FREQ 4000000

// Prototypes
void port(unsigned char c);
void cmd(unsigned char c);

char* nickname;

void init_LCD() {
    port(0x00);
    RS = 0;
    __delay_ms(25);
    cmd(0x30);
    __delay_ms(5);
    cmd(0x30);
    __delay_ms(15);
    cmd(0x30);
    cmd(0x38); //function set
    cmd(0x0C); //display on,cursor off,blink off
    cmd(0x01); //clear display
    cmd(0x06); //entry mode, set increment
}

void init() {
    // Versorungsspannung = 1 / 0 Volt = 0
    PORTA = 0;
    PORTB = 0;

    // Input = 1 / Output = 0
    TRISA = 0;
    TRISB = 0;

    // Analog = 1 / Digital = 0
    ANSELA = 0;
    ANSELB = 0;

    //Frequenz 4MHz
    OSCCON = 0b01101011;

    //init LCD screen
    init_LCD();
}

void port(unsigned char c) {
    if (c & 1) DB0 = 1;
    else DB0 = 0;
    if (c & 2) DB1 = 1;
    else DB1 = 0;
    if (c & 4) DB2 = 1;
    else DB2 = 0;
    if (c & 8) DB3 = 1;
    else DB3 = 0;
    if (c & 16) DB4 = 1;
    else DB4 = 0;
    if (c & 32) DB5 = 1;
    else DB5 = 0;
    if (c & 64) DB6 = 1;
    else DB6 = 0;
    if (c & 128) DB7 = 1;
    else DB7 = 0;
}

void cmd(unsigned char c) {
    RS = 0;
    port(c); //data send
    E = 1;
    __delay_ms(5);
    E = 0;
}

void clear() {
    cmd(1);
}

void cursor(unsigned char a, unsigned char b) {
    if (a == 1)
        cmd(0x80 + b);
    else if (a == 2)
        cmd(0xC0 + b);
}

void write_letter(unsigned char c) {
    RS = 1; //
    port(c); // letters send
    E = 1; //
    __delay_ms(5);
    E = 0; //
}

void write_words(unsigned char *c) {
    int j;
    for (j = 0; c[j] != '\0'; j++)
        write_letter(c[j]);
}

void main(void) {

    init();

    while (1) {
        // row 1, position 0
        cursor(1, 0);
        write_words("Guten Appetit");
        __delay_ms(2000);

        // row 2, position 0
        cursor(2, 0);
        nickname = "Hovi";
        write_words(nickname);
        __delay_ms(2000);
    }

    return;
}
