#include <xc.h>
#include "main.h"

/* This function checks for special bytes that indicate certain parts   */
/* of the transmission from the server to the HC, depending on that     */
/* the received bytes are stored for the following two purposes:        */
/*  *) storing the path to the table                                    */
/*  *) storing the name of the guest that should receives the order     */
/*----------------------------------------------------------------------*/
void UartStore(void) {
    received = UartReceive();
    if(received == 0x04) {  // EOT received, start new counter for storing
        c_path = 0;
        path_name = 0;
    }else if(received == 0x17){ // ETB received, further characters are name
        c_name = 0;
        path_name = 1;
    }else {
        if(path_name == 0) {
            a_path[c_path] = received;
            c_path++;
            if(c_path > 20) {
                UartSendOverflow();
                c_path = 0;
            }
        }else if(path_name == 1) {
            a_name[c_name] = received;
            c_name++;
            if(c_name > 32) {
                UartSendOverflow();
                c_name = 0;
            }
        }
    }
}

/* This function sends a special byte to the server to indicate */
/* that an overflow occured                                     */
/*--------------------------------------------------------------*/
void UartSendOverflow(void) {
    UartSend(0x11);     // Device control 1; Used to indicate Overflow
}