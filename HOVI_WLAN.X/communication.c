#include <xc.h>
#include "main.h"

void UartSend(unsigned char data) {
    if(TX1IF == 1) {
        __delay_us(200);
    }
    TXREG1 = data;
    while(TX1IF == 1);
}

unsigned char UartReceive(void) {
    if(RCSTA1bits.OERR == 1) {  // Error occured, restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
    }
    return RCREG1;
}
