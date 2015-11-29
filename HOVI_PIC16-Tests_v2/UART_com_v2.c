#include <pic16f1827.h>
#include "hovi_UART_v2.h"

void send_UART_char(unsigned char data) {
    while (PIR1bits.TXIF == 0);
    TXREG = data;
    NOP();
    while (PIR1bits.TXIF == 0);
}

void send_UART_word(unsigned int data) {
    while (PIR1bits.TXIF == 0);
    TXREG = data;
    data >>= 8;
    while (PIR1bits.TXIF == 0);
    TXREG = data;
    NOP();
    while (PIR1bits.TXIF == 0);
}