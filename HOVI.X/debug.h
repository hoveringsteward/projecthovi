/* 
 * File:   debug.h
 * Author: Lucas
 *
 * Created on 16. Februar 2016, 10:22
 */

#ifndef DEBUG_H
#define	DEBUG_H

#include <xc.h>
#include "main.h"

#ifdef DEBUG
/*--------------------------------------------------------------------------*/
/* Prototypes of userroutines.                                              */ 
/*--------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Userroutines">
void SendDebugInfo(unsigned int debug_info);
// </editor-fold>

/*--------------------------------------------------------------------------*/
/* Uservariables                                                            */
/*--------------------------------------------------------------------------*/
// <editor-fold defaultstate="collapsed" desc="Uservariables">
unsigned char send_info[5];
// </editor-fold>
#endif


#endif	/* DEBUG_H */

