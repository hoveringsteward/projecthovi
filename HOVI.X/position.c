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


// <editor-fold defaultstate="collapsed" desc="Compare Frames">
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
        CheckAileron();
        CheckElevator();
        CheckThrottle();
        if(direction == 0) {
            CheckRudderAhead();
        }else {
            CheckRudderBack();
        }
    }else {
        return 0;   // No changes should be taken on outputs
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Aileron">
/* This function checks the changes that happen in x-direction
 * Based on the current position of the CC/Obj the ActAileron
 * function is called to change the pulsetime of the aileron pin
/*-----------------------------------------------------------*/
void CheckAileron(void) {
    /* Two oft the used constants DES_X_MIN, DES_X_MAX; */
    
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
                if(a_frame_dif[0].pos_x <= V_MIN) {
                /* Velocity is very slow, increase */
                    ActAileron(-AIL_INC);
                }else {
                /* Velocity is OK */
                    ActAileron(0);
                }
            }else {
            /* Velocity is too high */
                ActAileron(AIL_INC); // slow down, bit more left
            }
        }else {
        /* Old smaller than new, MC moving away from CC/Obj */
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
        /* As soon as the right direction is achieved, velocity is */
        /* limited by the previous function */
            ActAileron(AIL_INC);  // fly to the left side
        }
    }
    // </editor-fold>
    return;
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Elevator">
/* This function checks the changes that happen in y-direction
 * Based on the current position of the CC/Obj the ActElevator
 * function is called to change the pulsetime of the elevator pin
/*-----------------------------------------------------------*/
void CheckElevator(void) {
    // <editor-fold defaultstate="collapsed" desc="centered">
    if(a_frame[0].pos_y >= 90 && a_frame[0].pos_y <= 110) {
    /* CC/Obj nearly centered, no further actions taken */
        ActElevator(0);   // keep doing
    }
    // </editor-fold>
    // <editor-fold defaultstate="collapsed" desc="front side">
    else if(a_frame[0].pos_y > 110) {
    /* CC/Obj is in front of the frame */
        if(a_frame[1].pos_y < a_frame[0].pos_y) {
        /* Old smaller than new, MC moving towards CC/Obj, moving forward */
            if(a_frame_dif[0].pos_y >= -V_MAX) {
                if(a_frame_dif[0].pos_y >= -V_MIN) {
                /* Velocity is very slow, increase */
                    ActElevator(ELE_INC);
                }else {
                /* Velocity is OK */
                    ActElevator(0);
                }
            }else {
            /* Velocity is too high */
                ActElevator(-ELE_INC); // slow down, bit more backward
            }
        }else {
        /* Old smaller than new, MC moving away from CC/Obj */
        /* Moving in the wrong direction */
        /* Dif is positive, HC needs to get back in right direction */
        /* As soon as the right direction is achieved, velocity is */
        /* limited by the previous function */
            ActElevator(ELE_INC); // fly forward
        }
    }
    // </editor-fold>
    // <editor-fold defaultstate="collapsed" desc="back side">
    else { // a_frame[0].pos_y < 90
    /* CC/Obj is in the back of the frame */
        if(a_frame[1].pos_y > a_frame[0].pos_y) {
        /* Old bigger than new, MC moving towards CC/Obj, moving backwards */
            if(a_frame_dif[0].pos_y <= V_MAX) {
                if(a_frame_dif[0].pos_y <= V_MIN) {
                /* Velocity is very slow, increase */
                    ActElevator(-ELE_INC);
                }else {
                /* Velocity is OK */
                    ActElevator(0); // keep doing
                }
            }else {
            /* Velocity is too high */
                ActElevator(ELE_INC); // slow down, bit more forward
            }
        }else {
        /* Old smaller than new, MC moving away from CC/Obj */
        /* Moving in the wrong direction */
        /* Dif is negative, HC needs to get back in right direction */
        /* As soon as the right direction is achieved, velocity is */
        /* limited by the previous function */
            ActElevator(-ELE_INC);  // fly to the left backwards
        }
    }
    // </editor-fold>
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Throttle">
/* This function checks the current flightheight 
 * Depending on the changes in the height and the total height
 * the ActThrottle function is called to make changes
/*------------------------------------------------------------*/
void CheckThrottle(void) {
    
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Rudder Ahead">
/* 
 * 
/*------------------------------------------------------------*/
void CheckRudderAhead(void) {
    
    if(a_frame[0].angle >= -5 && a_frame[0].angle <= 5 ){
        ActRudder(0);        
    }else if(a_frame[0].angle < -5){ // Rotation is too much on the "left" side
        ActRudder(-RUD_INC); // - to the right
    }else{ // Rotation is too much on the "right" side
        ActRudder(RUD_INC); // + to the left
    }
    
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Rudder Back">
/*
 * 
/*------------------------------------------------------------*/
void CheckRudderBack(void) {
    
    if(a_frame[0].angle <= - 175 || a_frame[0].angle >= 175){
        ActRudder(0);        
    }else if(a_frame[0].angle < 175){ // Rotation is too much on the "left" side
        ActRudder(-RUD_INC); // - to the right
    }else{ // Rotation is too much on the "right" side
        ActRudder(RUD_INC); // + to the left 
    }
    
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
