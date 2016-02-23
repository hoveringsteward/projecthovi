/*-----------------------------------------------------------------*/
/* Author: Lucas                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/* 
 */

#include <xc.h>
#include "main.h"

#ifdef DEBUG
void SendDebugInfo(unsigned int debug_info) {
    for(unsigned char debug_info_counter = 0; debug_info_counter < 5; debug_info_counter++) {
        send_info[debug_info_counter] = (debug_info / (10 * debug_info_counter)) % 10;
        debug_info -= send_info[debug_info_counter];
    }
    for(signed char debug_send_counter = 4; debug_send_counter >= 0; debug_send_counter--) {
        unsigned char send = send_info[debug_send_counter];
        UartSendAscii(send);
    }
    UartSend(';');
}
#endif