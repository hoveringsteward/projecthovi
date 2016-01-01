/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/*
 * The functions in this file calculate the change of Object-Koordinates
 * between two frames taken. Based on the changes between those frames
 * different actions are taken to control the Hexrotor via the functions
 * declared in actors.c
 */

#include <xc.h>
#include "main.h"
#include "position.h"
#include "actors.h"



// <editor-fold defaultstate="collapsed" desc="compare Frames">
/* compareFrames
 * compares the X and Y position of one colorobject in a frame with the same 
 * colorobject in the next frame
 * 2nd frame - 1st frame, respective old - new
/*---------------------------------------------------------------------------*/
bit CompareFrames(void) {
    a_frame_dif[0].height = a_frame[1].height - a_frame[0].height;
    
    if(a_frame[1].num == a_frame[0].num) {
        a_frame_dif[0].pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
        a_frame_dif[0].pos_y = a_frame[1].pos_y - a_frame[0].pos_y;
        a_frame_dif[0].angle = a_frame[1].angle - a_frame[0].angle;
    }else {
        return 0;   // No changes should be taken on outputs
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="compare Frames">
/* compareFrames
 * compares the X position of one colorobject in a frame with the same 
 * colorobject in the next frame
 * 2nd frame - 1st frame, respective old - new
 * the difference is only checked if the same colorcodes are stored
/*---------------------------------------------------------------------------*/
bit CheckAileron(void) {
    /* Two oft the used constants DES_X_MIN, DES_X_MAX; */
    
    if(a_frame[1].num == a_frame[0].num) {
        // <editor-fold defaultstate="collapsed" desc="centered">
        if(a_frame[0].pos_x >= 150 && a_frame[0].pos_x <= 170) {
        /* CC/Obj nearly centered, no further actions taken */
            ActAileron(0);   // keep doing
        }
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
        else if(a_frame[0].pos_x > 170) {
        /* CC/Obj is on the right side of the frame */
            if(a_frame[1].pos_x > a_frame[0].pos_x) {
            /* Old bigger than new, MC moving towards CC/Obj, moving right */
                if(a_frame_dif[0].pos_x <= V_MAX) {
                /* Velocity is OK */
                    ActAileron(0); // keep doing
                }else if(a_frame_dif[0].pos_x <= V_MIN) {
                /* Velocity is very slow, increase */
                    ActAileron(-AIL_INC);
                }else {
                /* Velocity is too high */
                    ActAileron(AIL_INC); // slow down, bit more left
                }
            }else {
            /* Ols smaller than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is negative, HC needs to get back in right direction */
            /* As soon as the right direction is achieved, velocity is */
            /* limited by the previous function */
                ActAileron(-AIL_INC); // fly to the right
            }
        }
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
        else { // a_frame[0].pos_x < 150
        /* CC/Obj is on the left side of the frame */
            if(a_frame[1].pos_x < a_frame[0].pos_x) {
            /* Old smaller than new, MC moving towards CC/Obj, moving left */
                if(a_frame_dif[0].pos_x >= -V_MAX) {
                    if(a_frame_dif[0].pos_x >= -V_MIN) {
                    /* Velocity is very slow, increase */
                        ActAileron(AIL_INC);
                    }else {
                    /* Velocity is OK */
                        ActAileron(0); // keep doing
                    }
                }else {
                /* Velocity is too high */
                    ActAileron(-AIL_INC); // slow down, bit more right
                }
            }else {
            /* Old bigger than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is positive, HC needs to get back in right direction */
            /* As soon as the right direction is aachieved, velocity is */
            /* limited by the previous function */
                ActAileron(AIL_INC);  // fly to the left side
            }
        }
        // </editor-fold>

//        {
//            int tmp = dif_old - dif;
//            if(tmp > 0){ // am richtigen Weg
//                ActAileron(); // Zahl wie viel er schneller/langsamer werden soll
//            }else{
//                ActAileron(); // am falschen Weg
//            }         
//        }
        
        
//        a_frame_dif[0].pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
        return 1;
    }else {
        return 0; 
    }

    
//    if(pos_x > 170){
//         LEDleft = 0;
//         LEDright = 1;
//     }else if(pos_x < 150){
//         LEDleft = 1;
//         LEDright = 0;   
//     }else if(pos_x >= 150 && pos_x <= 170){
//         LEDleft = 0;
//         LEDright = 0;  
//     }else{
//         LEDleft = 1;
//         LEDright = 1; 
//     }
    
    
     
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="store old">
/*
 *
 ------------------------------------------------------------*/
void StoreAsOld(void) {
    a_frame[1].num = a_frame[0].num;
    a_frame[1].pos_x = a_frame[0].pos_x;
    a_frame[1].pos_y = a_frame[0].pos_y;
    a_frame[1].height = a_frame[0].height;
    a_frame[1].angle = a_frame[0].angle;
}
// </editor-fold>
