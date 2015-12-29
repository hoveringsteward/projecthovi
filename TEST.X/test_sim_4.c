/*
 * File:   test_sim_4.c
 * Author: Lucas
 *
 * Created on 29. Dezember 2015, 15:28
 */


#include <xc.h>

void main(void) {
    if(-4 > -3) {
        NOP();
    } else if (-4 < 3) {
        NOP();
    }
    return;
}
