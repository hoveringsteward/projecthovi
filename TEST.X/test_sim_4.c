/*
 * File:   test_sim_4.c
 * Author: Lucas
 *
 * Created on 29. Dezember 2015, 15:28
 */


#include <xc.h>

unsigned char test = 0;
signed char n_test = 0;

#define TEST 10

void main(void) {
    test = TEST;
    n_test = -TEST;
    return;
}
