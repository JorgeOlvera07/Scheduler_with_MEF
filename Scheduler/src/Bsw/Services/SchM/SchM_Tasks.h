/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.h $
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
 * $Log: SchM_Tasks.h  $
  ============================================================================*/

#ifndef BSW_SERVICES_SCHM_SCHM_TASKS_H_
#define BSW_SERVICES_SCHM_SCHM_TASKS_H_

/* Includes */
/*============================================================================*/
#include "Std_Types.h"
#include "app_buttonscontrol.h"
#include "app_indicatorscontrol.h"
#include "app_windowcontrol.h"
#include "Dio.h"


/* Defines */
/*============================================================================*/

#define NumberOfCycles (uint32_t)2700

#define PINBKG      13  // Before: 9
#define PIN3P125MS  7
#define PIN6P25MS   17
#define PIN12P5MS   14
#define PIN25MS     15
#define PIN50MS     16
#define PIN100MS    3
#define PIN_1MS     7
#define PIN_2MS     17
#define LED_BLUE    0
#define LED_GREEN   16
#define BUTTON_UP   12
#define BUTTON_DOWN 13
#define PINOVERLOAD 14 // Before: 16

#define _1ms 1
#define _10ms 10
#define _500ms 500
#define _400ms 400
#define _1000ms 1000
#define _3000ms 3000
#define _5000ms 5000


/* Constants and types */
/*============================================================================*/

typedef struct {

	T_UBYTE bi1_flagAutomaticUp:1;
	T_UBYTE bi1_flagAutomaticDown:1;
	T_UBYTE bi1_flagSemiautomaticUp:1;
	T_UBYTE bi1_flagSemiautomaticDown:1;
	T_UBYTE bi1_flagUp:1;
	T_UBYTE bi1_flagDown:1;
	T_UBYTE bi1_FlagAntipinch:1;

}S_Structflags;


T_UWORD ruw_lpit0_ch0_counter1ms; /* LPIT0 chan 0 timeout counter */
T_UBYTE rub_Percentwindow;
S_Structflags rs_Fg;



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

extern void SchM_1MS_Task  ( void );
extern void SchM_2MS_Task ( void );

#endif /* BSW_SERVICES_SCHM_SCHM_TASKS_H_ */
 

/* Notice: the file ends with a blank new line to avoid compiler warnings */

