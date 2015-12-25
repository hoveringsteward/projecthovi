#include <xc.h>
#include "spi.h"

void Fkt_send_spi(unsigned char data) {
    if(SSP1IF == 1) {
        __delay_ms(2);
        SSP1IF = 0;
    }
    SSP1BUF = data;
    while(SSP1IF == 0);
    SSP1IF = 0;
}