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
 * compares the height of the hex-rotor of the old and the new frame
 * compares the X and Y position and rotation of one colorobject in a frame with the same 
 * colorobject in the next frame
 * frame 1 - frame 0, respective old - new
/*---------------------------------------------------------------------------*/
void CompareFrames(void) {

    a_frame_dif[0].dif_height = a_frame[1].height - a_frame[0].height;

    if (a_frame[1].num == a_frame[0].num) { // ColorCode ID
        a_frame_dif[0].dif_pos_x = a_frame[1].pos_x - a_frame[0].pos_x;
        a_frame_dif[0].dif_pos_y = a_frame[1].pos_y - a_frame[0].pos_y;
        a_frame_dif[0].dif_angle = a_frame[1].angle - a_frame[0].angle;
        CheckAileron();
        CheckElevator();
        if (direction == 0) {
            CheckRudderAhead();
        } else {
            CheckRudderBack();
        }
    } else {
        // Check if the next ColorCode is "true"
        return; // No changes should be taken on outputs
    }
}
// </editor-fold>


// <editor-fold defaultstate="collapsed" desc="more beautiful code">



// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Aileron">

/* This function checks the changes that happen in x-direction
 * Based on the current position of the CC/Obj the ActAileron
 * function is called to change the pulsetime of the aileron pin
/*-----------------------------------------------------------*/
void CheckAileron(void) {

    // <editor-fold defaultstate="collapsed" desc="centered">
    if (a_frame[0].pos_x >= 150 && a_frame[0].pos_x <= 170) {
        /* CC/Obj nearly centered, no further actions taken */
        ActAileron(0); // keep doing
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].pos_x > 170) {
        /* CC/Obj is on the right side of the frame */
        if (a_frame[1].pos_x > a_frame[0].pos_x) {
            /* good: Old bigger than new, MC moving towards CC/Obj, moving right */
            if (a_frame_dif[0].dif_pos_x <= V_MAX) {
                if (a_frame_dif[0].dif_pos_x <= V_MIN) {
                    /* Velocity is very slow, increase */
                    ActAileron(-AIL_INC); // fly to the right
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else { // a_frame[0].pos_x < 150
        /* CC/Obj is on the left side of the frame */
        if (a_frame[1].pos_x < a_frame[0].pos_x) {
            /* good: Old smaller than new, MC moving towards CC/Obj, moving left */
            if (a_frame_dif[0].dif_pos_x >= -V_MAX) {
                if (a_frame_dif[0].dif_pos_x >= -V_MIN) {
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="front side">
    else if (a_frame[0].pos_y > 110) {
        /* CC/Obj is in front of the frame */
        if (a_frame[1].pos_y < a_frame[0].pos_y) {
            /* good: Old smaller than new, MC moving towards CC/Obj, moving forward */
            if (a_frame_dif[0].dif_pos_y >= -V_MAX) {
                if (a_frame_dif[0].dif_pos_y >= -V_MIN) {
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="back side">
    else { // a_frame[0].pos_y < 90
        /* CC/Obj is in the back of the frame */
        if (a_frame[1].pos_y > a_frame[0].pos_y) {
            /* Old bigger than new, MC moving towards CC/Obj, moving backwards */
            if (a_frame_dif[0].dif_pos_y <= V_MAX) {
                if (a_frame_dif[0].dif_pos_y <= V_MIN) {
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
            ActElevator(-ELE_INC); // fly backwards
        }
    }
    // </editor-fold>
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="AboveTableStart">

/* The Hexrotor flies above the table
 * the hexrotors height should be between 80 and 120cm
/*-----------------------------------------------------------*/
void AboveTableStart(void) {
    // CENTERED
    if (a_frame[0].height <= cm120 && a_frame[0].height >= cm80) { // between 0.8 and 1.2
        ActThrottle(0);
        // TO LOW
    } else if (a_frame[0].height < cm80) { // under 0.8
        if (a_frame[0].height < cm50) { // under 0.5
            if (a_frame_dif[0].dif_height >= - THR_MAX) {
                if (a_frame_dif[0].dif_height >= - THR_MIN) {
                    ActThrottle(THR_INC_MUCH); // increase much
                } else {
                    ActThrottle(0);
                }
            } else {
                ActThrottle(-THR_INC); // decrease - too fast
            }
        } else { // between 0.5m and 0.8m
            if (a_frame_dif[0].dif_height >= - THR_MAX) {
                if (a_frame_dif[0].dif_height >= - THR_MIN) {
                    ActThrottle(THR_INC); // increase
                } else {
                    ActThrottle(0);
                }
            } else {
                ActThrottle(-THR_INC); // decrease - too fast
            }
        }
        // TO HIGH
    } else { // over 1.2
        if (a_frame_dif[0].dif_height <= THR_MAX) {
            if (a_frame_dif[0].dif_height <= THR_MIN) {
                ActThrottle(-THR_INC); // decrease
            } else {
                ActThrottle(0);
            }
        } else {
            ActThrottle(THR_INC); // increase - too fast
        }
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="AboveTableLand">

/* The Hexrotor flies above the table
 * -> last colorcode + landing
 * Landing / Decreasing - has to check, if the height - difference is between
 * dec min and dec max
 * if landed: invert colorcodes, delay + fly back
/*-----------------------------------------------------------*/
void AboveTableLand(void) {
    if (a_frame[0].height >= 30) { // higher than 30cm
        if (a_frame[1].height > a_frame[0].height) {
            /* Old bigger than new, MC is decreasing */
            if (a_frame_dif[0].dif_height <= THR_MAX) {
                if (a_frame_dif[0].dif_height <= THR_MIN) {
                    /* Decrease is very slow, decrease more == increase less */
                    ActThrottle(-THR_INC);
                } else { /* Decrease is OK */
                    ActThrottle(0);
                }
            } else {/* Decrease is too high */
                ActThrottle(THR_INC); // slow down, decrease less == increase more
            }
        } else {
            /* Old smaller than new, MC is not decreasing */
            ActThrottle(-THR_INC); // decrease = increase less
        }
    } else { // good: lower than 30cm, landed - take a break
        // change the path-colorcode-array for coming home
        /* old saves the path, which the hexrotor flied
         * the new way, is the old way reserved (=umgekehrte Reihenfolge)
         */
        if (direction == 1) { // if it was on the way back to the base 
            direction = 0; // outgoing flight = fly to table
        } else {
            direction = 1; // flies back to base
        }
        int tmp = c_path - 1;
        for (int i = 0; i <= tmp; i++) {
            a_path_old[i].higher_cc = a_path[i].higher_cc;
            a_path_old[i].lower_cc = a_path[i].lower_cc;
        }
        for (int i = 0; i <= tmp; i++) {
            a_path[(tmp - i)].higher_cc = a_path_old[i].higher_cc;
            a_path[(tmp - i)].lower_cc = a_path_old[i].lower_cc;
        }
        // waiting 30 seconds, break for getting the cupcake
        for (int i = 0; i <= 10000; i++) {
            __delay_ms(3);
        }
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="AboveFloor">

/* Hexrotor flies above the floor
 * the hexrotors height should be between 180 and 220cm
/*------------------------------------------------------------*/
void AboveFloor(void) {
    if (a_frame[0].height <= cm220 && a_frame[0].height >= cm180) { // between 1.8 and 2.2
        ActThrottle(0);
    } else if (a_frame[0].height < cm180) { // under 1.8
        if (a_frame[0].height < cm100) { // under 1m
            ActThrottle(THR_INC_MUCH); // increase much
        } else { // between 1m and 1.8m
            ActThrottle(THR_INC); // increase
        }
    } else { // over 2.2
        ActThrottle(-THR_INC); // decrease
    }
}
// </editor-fold>

// <editor-fold defaultstate="collapsed" desc="Check Throttle">

/* This function checks the current flightheight 
 * Depending on the changes in the height and the total height
 * the ActThrottle function is called to make changes
/*------------------------------------------------------------*/
void CheckThrottle(void) {

    if (id_current_cc == 0) { // Table: start
        // check, if difference is more than 50cm, on the table
        table = 1;
        AboveTableStart();
    } else if (id_current_cc == 1) { // cahnge between table and floor
        seconddifference = storeheight - a_frame[0].height;
        if (a_frame_dif[0].dif_height < (-1 * cm50) || seconddifference < (-1 * cm50)) {

            storeheight = a_frame_dif[0].dif_height; // storeheight is the difference between the second last and the actuall height

            /* position.h:
             * bit storedif; // table / floor: if the difference was higher than 50cm the last time, it's 1
             * bit table = 0; // 1 table; 0 floor
             */
            if (storedif) { // if storedif is 1: it has detected the floor -> 2 times 50cm difference
                table = 0;
            } else { // if the difference is the first time higher than 50cm, it gets the value 1
                storedif = 1;
            }
        } else { // no difference higher than 
            storedif = 0;
            storeheight = 0;
        }
        if (table == 1) {
            AboveTableStart();
        } else {
            AboveFloor();
        }

    } else if (id_current_cc > 1 && id_current_cc < (c_path - 1)) { // Floor between 0 and n-1
        AboveFloor();
    } else { // prove, if hexrotor is on the table
        // check, if difference is more than 50cm, from floor to table
        seconddifference = storeheight - a_frame[0].height;
        if (a_frame_dif[0].dif_height > cm50 || seconddifference > cm50) {
            storeheight = a_frame_dif[0].dif_height; // storeheight is the difference between the second last and the actuall height
            /* bit storedif; // table / floor: if the difference was higher than 50cm the last time, it's 1
             * bit table; // 1 table; 0 floor */
            if (storedif) { // if storedif is 1: it has detected the floor -> 2 times 50cm difference
                table = 1;
            } else { // if the difference is the first time higher than 50cm, it gets the value 1
                storedif = 1;
            }
        } else { // no difference higher than 
            storedif = 0;
            storeheight = 0;
        }

        if (table == 1) {
            AboveTableLand();
        } else {
            AboveFloor();
        }
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].angle > 5) {
        /* CC/Obj Rotation is on the right side */
        if (a_frame[1].angle > a_frame[0].angle) {
            /* good: Old bigger than new, moving right */
            if (a_frame_dif[0].dif_angle <= W_MAX) { // if rotation difference is smaller than eg 2
                if (a_frame_dif[0].dif_angle <= W_MIN) { // if rotation difference is smaller than eg 1
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else {
        /* CC/Obj Rotation is on the left side -> everything is minus*/
        if (a_frame[1].angle < a_frame[0].angle) {
            /* good: old smaller than new, moving left */
            if (a_frame_dif[0].dif_angle <= -W_MAX) { // if rotation difference is smaller than eg -2
                if (a_frame_dif[0].dif_angle <= -W_MAX) { // if rotation difference is smaller than eg -1
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="right side">
    else if (a_frame[0].angle > -175) {
        /* CC/Obj Rotation is on the right side, everything is minus */
        if (a_frame[1].angle > a_frame[0].angle) {
            /* good: Old bigger than new, moving right */
            if (a_frame_dif[0].dif_angle <= W_MAX) { // if rotation difference is smaller than eg 2
                if (a_frame_dif[0].dif_angle <= W_MIN) { // if rotation difference is smaller than eg 1
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
    }// </editor-fold>
        // <editor-fold defaultstate="collapsed" desc="left side">
    else {
        /* CC/Obj Rotation is on the left side */
        if (a_frame[1].angle < a_frame[0].angle) {
            /* good: old smaller than new, moving left */
            if (a_frame_dif[0].dif_angle <= -W_MAX) { // if rotation difference is smaller than eg -2
                if (a_frame_dif[0].dif_angle <= -W_MAX) { // if rotation difference is smaller than eg -1
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

// <editor-fold defaultstate="collapsed" desc="Store Old">

/* This Function stores the last Frame
 ------------------------------------------------------------*/
void StoreAsOld(void) {
    a_frame[1].num = a_frame[0].num;
    a_frame[1].pos_x = a_frame[0].pos_x;
    a_frame[1].pos_y = a_frame[0].pos_y;
    a_frame[1].height = a_frame[0].height;
    a_frame[1].angle = a_frame[0].angle;
}
// </editor-fold>

