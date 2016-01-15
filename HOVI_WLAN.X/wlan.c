#include <xc.h>
#include "main.h"

/* This function checks for special bytes that indicate certain parts   */
/* of the transmission from the server to the HC, depending on that     */
/* the received bytes are stored for the following two purposes:        */
/*  *) storing the path to the table                                    */
/*  *) storing the name of the guest that should receive the order      */
/*----------------------------------------------------------------------*/
void UartStore(void) {
    received = UartReceive();
    if(received == '<') {
        received = UartReceive();
        if(received == '<') {
            receiving_ok = 1;
            c_path = 0;
        }
    }else if(received == 0x04) {  /* EOT received; transmission ended by
                                   * host, reset counter for storing */
        c_path = 0;
        path_name = 0;
        receiving_ok = 0;
    }else if(received == 0x17){ // ETB received, further characters are name
        NAME:
        c_name = 0;
        path_name = 1;
    }else if(received == '>') { /* entered if first ending of cc '>'
                                 * transmission is received */
        received = UartReceive();   // reading next byte
        if(received == '>'){    /* entered if second ending of cc '>'
                                 * transmission is received */
            numb_cc = c_path;
            receiving_ok = 0;
        }else {     // ending was not complete, send error
            UartSendError();
        }
    }else if(received == 0x1D) {    // Tableindicator received
        numb_cc_table = c_path;
    }else if(receiving_ok == 1){    // receiving cc/path or name
        if(path_name == 0) {    // entered for storing path
            a_path[c_path].lower_cc = received;
            received = UartReceive();
            a_path[c_path].higher_cc = received;
            c_path++;
            if(c_path > 20) {
                UartSendOverflow();
                c_path = 0;
            }
        }else if(path_name == 1) {  // entered for storing name
            a_name[c_name] = received;
            c_name++;
            if(c_name > 32) {
                UartSendOverflow();
                c_name = 0;
            }
        }
    }else {     // entered if receiving is not allowed -> no startkondition
        UartDump();
    }
}

/* This function sends a special byte to the server to indicate */
/* that an overflow occured -> too much data has been sent      */
/*--------------------------------------------------------------*/
void UartSendOverflow(void) {
    UartSend(0x11);     // Device control 1; Used to indicate Overflow
}

void UartSendError(void) {
    UartSend(0x15);     /* NAK, error while receiving such as incorrect
                         * number of cc etc; data needs to be resent */
}

void UartDump(void) {
    unsigned char dumpdata;
    dumpdata = UartReceive();
}
