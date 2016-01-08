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

// <editor-fold defaultstate="collapsed" desc="Reading Object">
/*---------------------------------------------------------------------------*/
/* Retrieves Object from Pixy                                                */
/* Maximum tries for getting startcondition c = 254, retuns 0 if overrun      */
/* Returns a found Object in struct colorobject                              */
/* Searches for desired object des_obj by controlling with ProofObject()     */
/* Searches for specific objecttype by des_obj_type, desired object type     */
/*      des_obj_type = 0 => searches for normal objects                      */
/*      des_obj_type = 1 => searches for colorcodeobjects                    */
/* Maximum Objectss to dedect declared by max_obj                            */
/*---------------------------------------------------------------------------*/
unsigned char ReadObject(unsigned char des_obj_type, unsigned int des_obj, unsigned char max_obj){
    frame = 0;
    unsigned char c = 0;    // Counter for following while loop
    for(unsigned char c_obj = 0; c_obj < max_obj; c_obj++) {
        /* Routine for getting startcondition                                    */
        /* Returns 0 after 254 cycles without detecting an object                 */
        /*-----------------------------------------------------------------------*/
        if(frame == 1) {
            w = ExchangeSpiWord(PIXY_SYNC, DUMMY);
            if(w == PIXY_FRAME_OBJ) {
                a_color[c_obj].type = PIXY_FRAME_OBJ;
            }else if(w == PIXY_COLORCODE) {
                a_color[c_obj].type = PIXY_COLORCODE;
            }
        }
        while(frame == 0) {
            w = ExchangeSpiWord(PIXY_SYNC, DUMMY);
            if(lw == PIXY_FRAME_OBJ && w == PIXY_FRAME_OBJ) {
                frame = 1;
                obj_type = 0;
                a_color[c_obj].type = PIXY_FRAME_OBJ;
            } else if(lw == PIXY_FRAME_OBJ && w == PIXY_COLORCODE) {
                frame = 1;
                obj_type = 1;
                a_color[c_obj].type = PIXY_COLORCODE;
            } else if(w == 0 && lw == 0){
                frame = 0;
            }
            lw = w;
            c++;
            if(c > 254) {
                return 0;
            }
        }
        
        unsigned int checksum = ExchangeSpiWord(PIXY_SYNC, DUMMY);

        a_color[c_obj].num =    ExchangeSpiWord(PIXY_SYNC, DUMMY);
        a_color[c_obj].pos_x =  ExchangeSpiWord(PIXY_SYNC, DUMMY);
        a_color[c_obj].pos_y =  ExchangeSpiWord(PIXY_SYNC, DUMMY);
        a_color[c_obj].obj_width =  ExchangeSpiWord(PIXY_SYNC, DUMMY);
        a_color[c_obj].obj_height = ExchangeSpiWord(PIXY_SYNC, DUMMY);
        a_color[c_obj].angle =  ExchangeSpiWord(PIXY_SYNC, DUMMY);
    }
    return 1;
}
// </editor-fold>
