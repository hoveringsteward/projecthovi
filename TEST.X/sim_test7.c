/*
 * File:   sim_test7.c
 * Author: Lucas
 *
 * Created on 11. Februar 2016, 16:09
 */


#include <xc.h>

#define VAR 5
unsigned char test_var = 50;

void TestFunction(signed char change) {
    test_var += change;
}

void main(void) {
    while(1) {
        TestFunction(-VAR);
    }
    return;
}
