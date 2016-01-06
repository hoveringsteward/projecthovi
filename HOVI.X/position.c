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
 * 
 * a_frame[0] is the newest frame
 * a_frame[1] is the last frame
 * a_frame_diff[0] = old - new
 * 
 */

#include <xc.h>
#include "main.h"


// <editor-fold defaultstate="collapsed" desc="Compare Frames">

/* compareFrames
 * compares the X and Y position of one colorobject in a frame with the same 
 * colorobject in the next frame
 * frame 1 - frame 0, respective old - new
/*---------------------------------------------------------------------------*/
void CompareFrames(void) {
    a_frame_dif[0].height = a_frame[1].height - a_frame[0].height;

    if (a_frame[1].num == a_frame[0].num) {
        a_frame_dif[0].pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
        a_frame_dif[0].pos_y = a_frame[1].pos_y - a_frame[0].pos_y;
        a_frame_dif[0].angle = a_frame[1].angle - a_frame[0].angle;
        CheckAileron();
        CheckElevator();

        if (direction == 0) {
            CheckRudderAhead();
        } else {
            CheckRudderBack();
        }
    } else {
        return 0; // No changes should be taken on outputs
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
    if (a_frame[0].pos_x >= 150 && a_frame[0].pos_x <= 170) {
        /* CC/Obj nearly centered, no further actions taken */
        ActAileron(0); // keep doing
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].pos_x > 170) {
        /* CC/Obj is on the right side of the frame */
        if (a_frame[1].pos_x > a_frame[0].pos_x) {
            /* Old bigger than new, MC moving towards CC/Obj, moving right */
            if (a_frame_dif[0].pos_x <= V_MAX) {
                if (a_frame_dif[0].pos_x <= V_MIN) {
                    /* Velocity is very slow, increase */
                    ActAileron(-AIL_INC);
                } else {
                    /* Velocity is OK */
                    ActAileron(0);
                }
            } else {
                /* Velocity is too high */
                ActAileron(AIL_INC); // slow down, bit more left
            }
        } else {
            /* Old smaller than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is negative, HC needs to get back in right direction */
            /* As soon as the right direction is achieved, velocity is */
            /* limited by the previous function */
            ActAileron(-AIL_INC); // fly to the right
        }
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else { // a_frame[0].pos_x < 150
        /* CC/Obj is on the left side of the frame */
        if (a_frame[1].pos_x < a_frame[0].pos_x) {
            /* Old smaller than new, MC moving towards CC/Obj, moving left */
            if (a_frame_dif[0].pos_x >= -V_MAX) {
                if (a_frame_dif[0].pos_x >= -V_MIN) {
                    /* Velocity is very slow, increase */
                    ActAileron(AIL_INC);
                } else {
                    /* Velocity is OK */
                    ActAileron(0); // keep doing
                }
            } else {
                /* Velocity is too high */
                ActAileron(-AIL_INC); // slow down, bit more right
            }
        } else {
            /* Old bigger than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is positive, HC needs to get back in right direction */
            /* As soon as the right direction is achieved, velocity is */
            /* limited by the previous function */
            ActAileron(AIL_INC); // fly to the left side
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
    if (a_frame[0].pos_y >= 90 && a_frame[0].pos_y <= 110) {
        /* CC/Obj nearly centered, no further actions taken */
        ActElevator(0); // keep doing
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="front side">
    else if (a_frame[0].pos_y > 110) {
        /* CC/Obj is in front of the frame */
        if (a_frame[1].pos_y < a_frame[0].pos_y) {
            /* Old smaller than new, MC moving towards CC/Obj, moving forward */
            if (a_frame_dif[0].pos_y >= -V_MAX) {
                if (a_frame_dif[0].pos_y >= -V_MIN) {
                    /* Velocity is very slow, increase */
                    ActElevator(ELE_INC);
                } else {
                    /* Velocity is OK */
                    ActElevator(0);
                }
            } else {
                /* Velocity is too high */
                ActElevator(-ELE_INC); // slow down, bit more backward
            }
        } else {
            /* Old smaller than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is positive, HC needs to get back in right direction */
            /* As soon as the right direction is achieved, velocity is */
            /* limited by the previous function */
            ActElevator(ELE_INC); // fly forward
        }
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="back side">
    else { // a_frame[0].pos_y < 90
        /* CC/Obj is in the back of the frame */
        if (a_frame[1].pos_y > a_frame[0].pos_y) {
            /* Old bigger than new, MC moving towards CC/Obj, moving backwards */
            if (a_frame_dif[0].pos_y <= V_MAX) {
                if (a_frame_dif[0].pos_y <= V_MIN) {
                    /* Velocity is very slow, increase */
                    ActElevator(-ELE_INC);
                } else {
                    /* Velocity is OK */
                    ActElevator(0); // keep doing
                }
            } else {
                /* Velocity is too high */
                ActElevator(ELE_INC); // slow down, bit more forward
            }
        } else {
            /* Old smaller than new, MC moving away from CC/Obj */
            /* Moving in the wrong direction */
            /* Dif is negative, HC needs to get back in right direction */
            /* As soon as the right direction is achieved, velocity is */
            /* limited by the previous function */
            ActElevator(-ELE_INC); // fly to the left backwards
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

    int zweiMminus20 = 41982;
    int zweiMplus20 = 51310;
    int oneM = 23323;
    time_height;
    bit ntable_floor = 0; // 0 = table, 1 = floor
    bit tabe_allowed = 0; // 0 = no , 1 = yes 

    if (ntable_floor) { // Floor

        if (a_frame[0].height <= zweiMplus20 && a_frame[0].height >= zweiMminus20) {
            ActThrottle(0);
        } else if (a_frame[0].height < zweiMminus20) { // under 1.8

            // mit letztem Frame vergleichen -> für vergleich tisch / Boden (?))

            if (a_frame[0].height < oneM) { // under 1m
                ActThrottle(); // increase much
            } else { // between 1m and 1.8m
                ActThrottle(); // increase
            }
        } else { // over 2.2m
            ActThrottle(); // decrease 
        }
    } else { // Table
        // starten / landen
        ActThrottle(); // increase much
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Rudder Ahead">

/* The rotation is checked, if it's between -5 and +5, if not,
 * ActRudder has to increase / decrease
 * The new and the last frame are always compared, if the hexrotor
 * does, what he is supposed to do, in this way, we can check
 * if the transformation of the two frames is between W_MAX and 
 * W_MIN; if W_MAX is too high, it should slow down
/*------------------------------------------------------------*/
void CheckRudderAhead(void) {
    // <editor-fold defaultstate="collapsed" desc="centered">
    if (a_frame[0].angle >= -5 && a_frame[0].angle <= 5) {
        ActRudder(0);
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].angle > 5) {
        /* CC/Obj Rotation is on the right side */
        if (a_frame[1].angle > a_frame[0].angle) {
            /* good: Old bigger than new, moving right */
            if (a_frame_dif[0].angle <= W_MAX) { // if rotation difference is smaller than eg 2
                if (a_frame_dif[0].angle <= W_MIN) { // if rotation difference is smaller than eg 1
                    ActRudder(-RUD_INC); // - to the right
                } else {
                    ActRudder(0); // good: Rudder is between W_MIN and W_MAX
                }
            } else {
                // Omega (W -> W_MAX) is too high
                ActRudder(RUD_INC); // slow down, less right
            }
        } else {
            /* wrong rudder-direction, ... */
            ActRudder(-RUD_INC); // - to the right
        }
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else {
        /* CC/Obj Rotation is on the left side -> everything is minus*/
        if (a_frame[1].angle < a_frame[0].angle) {
            /* good: old smaller than new, moving left */
            if (a_frame_dif[0].angle <= -W_MAX) { // if rotation difference is smaller than eg -2
                if (a_frame_dif[0].angle <= -W_MAX) { // if rotation difference is smaller than eg -1
                    ActRudder(RUD_INC); // + to the left
                } else {
                    ActRudder(0); // good: Rudder is between W_MIN and W_MAX
                }
            } else {
                // Omega is too low (minus side)
                ActRudder(-RUD_INC); // slow down, less left
            }
        } else {
            /* wrong rudder-direction, ... */
            ActRudder(RUD_INC); // + to the left
        }
    }
    // </editor-fold> 
}
// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="Check Rudder Back">

/* The rotation is checked, if it's over 175 and under -175, if not,
 * ActRudder has to increase / decrease
 * The new and the last frame are always compared, if the hexrotor
 * does, what he is supposed to do, in this way, we can check
 * if the transformation of the two frames is between W_MAX and 
 * W_MIN; if W_MAX is too high, it should slow down
/*------------------------------------------------------------*/
void CheckRudderBack(void) {

    // <editor-fold defaultstate="collapsed" desc="centered">
    if (a_frame[0].angle <= -175 || a_frame[0].angle >= 175) {
        ActRudder(0); // do nothing - it's perfect      
    }        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].angle > -175) {
        /* CC/Obj Rotation is on the right side, everything is minus */
        if (a_frame[1].angle > a_frame[0].angle) {
            /* good: Old bigger than new, moving right */
            if (a_frame_dif[0].angle <= W_MAX) { // if rotation difference is smaller than eg 2
                if (a_frame_dif[0].angle <= W_MIN) { // if rotation difference is smaller than eg 1
                    ActRudder(-RUD_INC); // - to the right
                } else {
                    ActRudder(0); // good: Rudder is between W_MIN and W_MAX
                }
            } else {
                // Omega is too high
                ActRudder(RUD_INC); // slow down, less right
            }
        } else {
            /* wrong rudder-direction, ... */
            ActRudder(-RUD_INC); // - to the right
        }
    }
        // </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else {
        /* CC/Obj Rotation is on the left side */
        if (a_frame[1].angle < a_frame[0].angle) {
            /* good: old smaller than new, moving left */
            if (a_frame_dif[0].angle <= -W_MAX) { // if rotation difference is smaller than eg -2
                if (a_frame_dif[0].angle <= -W_MAX) { // if rotation difference is smaller than eg -1
                    ActRudder(RUD_INC); // + to the left
                } else {
                    ActRudder(0); // good: Rudder is between W_MIN and W_MAX
                }
            } else {
                // Omega is too low = too much on the left side
                ActRudder(-RUD_INC); // slow down, less left
            }
        } else {
            /* wrong rudder-direction, ... */
            ActRudder(RUD_INC); // + to the left
        }
    }
    // </editor-fold>


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
