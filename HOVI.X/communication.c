/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Diese Beschreibung dient als Beispieltext für eine
 * Filebeschreibung aus welcher klar hervorgehen soll was in
 * diesem File passiert und wozu dieses benötigt wird.
 */


#include <xc.h>
#include "main.h"

unsigned char ExchangeSpiByte(unsigned char byte1) {
    if (SSP1IF == 1) {
        __delay_us(100);
        SSP1IF = 0;
    }
    SSP1BUF = byte1;
    while (SSP1IF == 0);
    SSP1IF = 0;
    return (SSP1BUF);
}

unsigned int ExchangeSpiWord(unsigned char byte1, unsigned char byte2) {
    NOP();
    unsigned int SPI_word = 0;
    if (SSP1IF == 1) {
        __delay_us(100);
        SSP1IF = 0;
    }
    SSP1BUF = byte1;
    while (SSP1IF == 0);
    SSP1IF = 0;
    SPI_word = SSP1BUF;
    SPI_word <<= 8;
    SSP1BUF = byte2;
    while (SSP1IF == 0);
    SSP1IF = 0;
    SPI_word |= SSP1BUF;
    NOP();
    return (SPI_word);
}