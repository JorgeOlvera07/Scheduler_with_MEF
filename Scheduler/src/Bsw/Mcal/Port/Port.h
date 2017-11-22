/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Port.h $
 * $Revision: 3 $
 * $Author: Jorge Alberto Olvera Contreras, Luis Eduardo Archundia Picazzo $
 * $Date: 17/11/2017 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \
    
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  AUTHOR             |      VERSION       |        DESCRIPTION              */
/*----------------------------------------------------------------------------*/
/*  Luis Archundia     |         3          |                                 */
/*  Jorge Olvera       |         3          |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Port.h  $
  ============================================================================*/

#ifndef BSW_MCAL_PORT_PORT_H_
#define BSW_MCAL_PORT_PORT_H_

/* Includes */
/*============================================================================*/

#include "Std_Types.h"


/* Defines */
/*============================================================================*/

#define PINBKG      13  // Before: 9
#define PIN3P125MS  7
#define PIN6P25MS   17
#define PIN12P5MS   14
#define PIN25MS     15
#define PIN50MS     16
#define PIN100MS    3
#define PIN_1MS    7
#define PIN_2MS    17
#define PINOVERLOAD 14 // Before: 16

/* Constants and types */
/*============================================================================*/



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

void PORT_init (void);

#endif /* BSW_MCAL_PORT_PORT_H_ */
  

/* Notice: the file ends with a blank new line to avoid compiler warnings */







