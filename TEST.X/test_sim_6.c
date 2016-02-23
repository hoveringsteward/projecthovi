/*
 * File:   test_sim_6.c
 * Author: Lucas
 *
 * Created on 6. Januar 2016, 16:43
 */

#include <xc.h>


unsigned int test = 10;

void main(void) {
    
    while(1) {
        test -= 5;
    }
    return;
}
