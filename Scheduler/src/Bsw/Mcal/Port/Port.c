/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Port.c $
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
 * $Log: Port.c  $
  ============================================================================*/


/* Includes */
/*============================================================================*/

#include "General.h"          /* include peripheral declarations */
#include "Port.h"


/* Defines */
/*============================================================================*/



/* Constants and types */
/*============================================================================*/



/* Exported Variables */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void PORT_init (void) {


  //------------------PORTB
  PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT B */

  //Initialize PIN6P25MS
  PTB->PDDR |= 1<<PIN6P25MS; /* Port D0: Data Direction= output */
  PORTB->PCR[PIN6P25MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTB->PCOR |= 1<<PIN6P25MS; /* Clear pin*/

  //Initialize PIN12P5MS
  PTB->PDDR |= 1<<PIN12P5MS; /* Port D0: Data Direction= output */
  PORTB->PCR[PIN12P5MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTB->PCOR |= 1<<PIN12P5MS; /* Clear pin*/

  //Initialize PIN25MS
  PTB->PDDR |= 1<<PIN25MS; /* Port D0: Data Direction= output */
  PORTB->PCR[PIN25MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTB->PCOR |= 1<<PIN25MS; /* Clear pin*/

  //Initialize PIN50MS
  PTB->PDDR |= 1<<PIN50MS; /* Port D0: Data Direction= output */
  PORTB->PCR[PIN50MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTB->PCOR |= 1<<PIN50MS; /* Clear pin*/



  //------------------PORTC
  PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT C */

  //Initialize PIN_2MS
  PTC->PDDR |= 1<<PIN_2MS; /* Port D0: Data Direction= output */
  PORTC->PCR[PIN_2MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTC->PCOR |= 1<<PIN_2MS; /* Clear pin*/

  //Initialize PIN_1MS
  PTC->PDDR |= 1<<PIN_1MS; /* Port D0: Data Direction= output */
  PORTC->PCR[PIN_1MS] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTC->PCOR |= 1<<PIN_1MS; /* Clear pin*/

  //Initialize BUTTON_UP
  PTC->PDDR &= ~(1<<12); /* Port C12: Data Direction= input (default) */
  PORTC->PCR[12] = 0x00000110; /* Port C12: MUX = GPIO, input filter enabled */

  //Initialize BUTTON_DOWN
  PTC->PDDR &= ~(1<<13); /* Port C13: Data Direction= input (default) */
  PORTC->PCR[13] = 0x00000110; /* Port C13: MUX = GPIO, input filter enabled */



  //------------------PORTE
  PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

  //Initialize BKG
  PTE->PDDR |= 1<<PINBKG; /* Port D0: Data Direction= output */
  PORTE->PCR[PINBKG] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTE->PCOR |= 1<<PINBKG; /* Clear pin*/

  //Initialize OVERLOAD
  PTE->PDDR |= 1<<PINOVERLOAD; /* Port D0: Data Direction= output */
  PORTE->PCR[PINOVERLOAD] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
  PTE->PCOR |= 1<<PINOVERLOAD; /* Clear pin*/


  //------------------PORTD
  //**************************************************
  PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */

  PTD->PDDR |= 1<<0;            /* Port D0:  Data Direction= output */
  PORTD->PCR[0] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
  PTD->PSOR |= 1<<0; /* Clear pin*/

  PTD->PDDR |= 1<<16;            /* Port D0:  Data Direction= output */
  PORTD->PCR[16] =  0x00000100;  /* Port D0:  MUX = ALT1, GPIO (to blue LED on EVB) */
  PTD->PSOR |= 1<<16; /* Clear pin*/
}


/* Notice: the file ends with a blank new line to avoid compiler warnings */


