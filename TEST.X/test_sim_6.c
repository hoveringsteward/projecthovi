/*
 * File:   test_sim_6.c
 * Author: Lucas
 *
 * Created on 6. Januar 2016, 16:43
 */

#include <xc.h>




void main(void) {
    NOP();
    NOP();
    NOP();
    NAME:
    NOP();
    NOP();
    while(1) {
        NOP();
        NOP();
        goto NAME;
        NOP();
        NOP();
    }
    return;
}
