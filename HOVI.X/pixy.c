/*-----------------------------------------------------------------*/
/* Author: Lucas                                                   */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* The file is used to detect colorcodes, compare it to
 * the wantet codes, which are sent from the server.
 * 
 * The Colorcodes have to be checked, if the position and 
 * rotation is right             */

#include <xc.h>
#include "main.h"

unsigned char ReadObject(unsigned char des_obj_type, unsigned int des_obj, unsigned char max_obj){
    frame = 0;
    
    for(unsigned char c_obj = 0; c_obj < max_obj; c_obj++) {
        /* Routine for getting startcondition                                    */
        /* Returns 0 after 10 cycles without detecting an object                 */
        /*-----------------------------------------------------------------------*/
        
        while(frame == 0) {
            w = ExchangeSpi2char(PIXY_SYNC, DUMMY);
            if(lw == PIXY_FRAME_OBJ && w == PIXY_FRAME_OBJ) {
                frame = 1;
                obj_type = 0;
            } else if(lw == PIXY_FRAME_OBJ && w == PIXY_COLORCODE) {
                frame = 1;
                obj_type = 1;
            } else if(w == 0 && lw == 0){
                frame = 0;
            }
            lw = w;
            c++;
            if(c > 254) {
                return 0;
            }
        }

        unsigned int checksum = ExchangeSpi2char(PIXY_SYNC, DUMMY);


        afarben[c_obj].num =    ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].pos_x =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].pos_y =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].width =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].height = ExchangeSpi2char(PIXY_SYNC, DUMMY);
        afarben[c_obj].angle =  ExchangeSpi2char(PIXY_SYNC, DUMMY);
    
}