/*-----------------------------------------------------------------*/
/* Author: Lucas                                                  */
/*                                                                 */
/* Created: 2015-12-25                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* This file is for the ultrasonic sensor(s)                       */
/*                                                                 
/* -> da darf dein Text noch rein :b
 * Something with measurements :D
 * 
 * summary: check, ignore and smooth
/* after getting data from the sensor(s), the programm has
/* to check if the value has no special characters and is 
/* incorrect measurement (= irgendwelche Sonderzeichen oder 
/* Fehler, die nicht aus Zahlen bestehen)
/* The second assignment is, to ignore runaways (Ausreiﬂer entfernen)
/* and the third is, to smooth the measurements               
 * 
 * The increase / velocity will be calculated in this file as well
 */

#include <xc.h>
#include "main.h"
