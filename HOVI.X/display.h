/*-----------------------------------------------------------------*/
/* Author: Chrisy                                                   */
/*                                                                 */
/* Created: 2017-02-06                                             */
/* Project: HOVI.X                                                 */
/*                                                                 */
/* Header File from display                                        */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <xc.h>
#include "main.h"


/*---------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                               */ 
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
void init_LCD(void);
void port_LCD (unsigned char a);
void cmd_LCD(unsigned char a);
void clear_LCD(void);
void cursor_LCD(char a, char b);
void write_letter_LCD(char a);
void write_words_LCD(char *a);
void displayPrinter(char message[30], char name[30]); // like main
// </editor-fold>


/*---------------------------------------------------------------------------*/
/* Beginning of uservariables.     empty                                     */
/*---------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Uservariables">

// </editor-fold>


#endif	/* DISPLAY_H */

