/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: SchM_Tasks.c $
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
 * $Log: SchM_Tasks.c  $
  ============================================================================*/


/* Includes */
/*============================================================================*/
#include "SchM_Tasks.h"


/* Defines */
/*============================================================================*/



/* Constants and types */
/*============================================================================*/



/* Exported Variables */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

 void SchM_1MS_Task  ( ){
	 Dio_PortTooglePin(PORTCH_C, PIN_1MS);

	//Dio_PortSetPin(PORTCH_C, PIN_1MS);

	static unsigned char state = 0;
	ruw_lpit0_ch0_counter1ms++;
	//unsigned int i;

	switch(state){

	/*****************************************************    S T A T E      0   **************************************************/
	/*============================================================================================================================*/
	case 0:
	/* Acciones del estado 0 */
		ic_void_offIndicator_Up();
		ic_void_offIndicator_Down();

	/* Conditions */
		if((bc_T_UBYTE_statusButt_Up()==0) || (bc_T_UBYTE_statusButt_Down()==0)){ /* Condiciones para permanecer en state 0  */
			/* Acciones para permanecer en state 0 */
			state=0;
		}

		if(bc_T_UBYTE_statusButt_Up()||bc_T_UBYTE_statusButt_Down()){ /* Condiciones de la transicion state 0 - 1 */
			/* Acciones de la transicion state 0 -1 */
			state=1;
			ruw_lpit0_ch0_counter1ms=0;
		}

		break;
	/*============================================================================================================================*/

	/*****************************************************    S T A T E      1   **************************************************/
	/*============================================================================================================================*/
	case 1:
		/* Acciones del estado 1 */
		ic_void_offIndicator_Up();
		ic_void_offIndicator_Down();

		/* Conditions */

		if(bc_T_UBYTE_statusButt_Up()||bc_T_UBYTE_statusButt_Down()){ /* Condiciones para permanecer en state 1  */
			/* Acciones para permanecer en state 1 */
			state=1;
		}

		if((ruw_lpit0_ch0_counter1ms>=_10ms)&&(bc_T_UBYTE_statusButt_Up())){ /* Condiciones de la transicion state 1 - 2 */
			/* Acciones de la transicion state 1 - 2 */
			state=2;
			rs_Fg.bi1_flagUp=1;
		}

		if((ruw_lpit0_ch0_counter1ms>=_10ms)&&(bc_T_UBYTE_statusButt_Down())){ /* Condiciones de la transicion state 1 - 2 */
			/* Acciones de la transicion state 1 - 2 */
			state=2;
			rs_Fg.bi1_flagDown=1;
		}


		break;
	/*============================================================================================================================*/

	/*****************************************************    S T A T E      2   **************************************************/
	/*============================================================================================================================*/
	case 2:
		/* Acciones del estado 2 */
		if(rs_Fg.bi1_flagDown){ ic_void_onIndicator_Down();}
		if(rs_Fg.bi1_flagUp){ ic_void_onIndicator_Up();}

		/* Conditions */

		if((bc_T_UBYTE_statusButt_Up()==0) && (bc_T_UBYTE_statusButt_Down()==0)){ /* Condiciones para permanecer en state 2  */
			/* Acciones para permanecer en state 2 */
			state=2;
		}

		if(bc_T_UBYTE_statusButt_Up()||bc_T_UBYTE_statusButt_Down()){ /* Condiciones de la transicion state 2 - 3 */
			/* Acciones de la transicion state 2 - 3 */
			state=3;
		}

		break;
	/*============================================================================================================================*/

	/*****************************************************    S T A T E      3   **************************************************/
	/*============================================================================================================================*/
	case 3:
		/* Acciones del estado 3 */

		/* Conditions */
		if(rs_Fg.bi1_flagUp){

			if(bc_T_UBYTE_statusButt_Up()&&(ruw_lpit0_ch0_counter1ms>_500ms)){ /* Condiciones de la transicion state 3 - 5 */
				/* Acciones de la transicion state 3 - 5 */
				state=5;
				rs_Fg.bi1_flagSemiautomaticUp=1;
				ruw_lpit0_ch0_counter1ms=0;
			}

			if((bc_T_UBYTE_statusButt_Up()==0)&&(ruw_lpit0_ch0_counter1ms<_500ms)){ /* Condiciones de la transicion state 3 - 4 */
				/* Acciones de la transicion state 3 - 4 */
				state=4;
				rs_Fg.bi1_flagAutomaticUp=1;
				ruw_lpit0_ch0_counter1ms=0;
			}

		}

		if(rs_Fg.bi1_flagDown){

			if(bc_T_UBYTE_statusButt_Down()&&(ruw_lpit0_ch0_counter1ms>_500ms)){ /* Condiciones de la transicion state 3 - 5 */
				/* Acciones de la transicion state 3 - 5 */
				state=5;
				rs_Fg.bi1_flagSemiautomaticDown=1;
				ruw_lpit0_ch0_counter1ms=0;

			}

			if((bc_T_UBYTE_statusButt_Down()==0)&&(ruw_lpit0_ch0_counter1ms<_500ms)){ /* Condiciones de la transicion state 3 - 4 */
				/* Acciones de la transicion state 3 - 4 */
				state=4;
				rs_Fg.bi1_flagAutomaticDown=1;
				ruw_lpit0_ch0_counter1ms=0;
			}

		}
		break;
	/*============================================================================================================================*/

	/*****************************************************    S T A T E      4   **************************************************/
	/*============================================================================================================================*/
	case 4:
		/* Acciones del estado 4 */
		if(rs_Fg.bi1_flagAutomaticDown){
			if(rub_Percentwindow>=1){
				if(ruw_lpit0_ch0_counter1ms>=_400ms){
					wc_void_ControlWindowDown (&rub_Percentwindow);
					rub_Percentwindow--;
					ruw_lpit0_ch0_counter1ms=0;
				}

			}

		}

		if(rs_Fg.bi1_flagAutomaticUp){
			if(rub_Percentwindow<10){
				if(ruw_lpit0_ch0_counter1ms>=_400ms){
					rub_Percentwindow++;
					wc_void_ControlWindowUp (&rub_Percentwindow);
					ruw_lpit0_ch0_counter1ms=0;
				}

			}

		}

		/* Conditions */

		if(rs_Fg.bi1_flagAutomaticUp&&rub_Percentwindow==10){ /* Condiciones de la transicion state 4 - 0 */
			/* Acciones de la transicion state 4 - 0 */
			state=0;
			rs_Fg.bi1_flagAutomaticUp=0;
			rs_Fg.bi1_flagUp=0;
		}

		if(rs_Fg.bi1_flagAutomaticDown&&rub_Percentwindow==0){ /* Condiciones de la transicion state 4 - 0 */
			/* Acciones de la transicion state 4 - 0 */
			state=0;
			rs_Fg.bi1_flagAutomaticDown=0;
			rs_Fg.bi1_flagDown=0;
		}

		if((bc_T_UBYTE_statusButt_Up())||(bc_T_UBYTE_statusButt_Down())){ /* Condiciones de la transicion state 4 - 1 */
			/* Acciones de la transicion state 4 - 1 */
			state=1;
			rs_Fg.bi1_flagAutomaticDown=0;
			rs_Fg.bi1_flagDown=0;
			rs_Fg.bi1_flagAutomaticUp=0;
			rs_Fg.bi1_flagUp=0;
			ruw_lpit0_ch0_counter1ms=0;
		}


		break;
	/*============================================================================================================================*/


	/*****************************************************    S T A T E      5   **************************************************/
	/*============================================================================================================================*/
	case 5:
		/* Acciones del estado 5 */
		if(rs_Fg.bi1_flagSemiautomaticDown){
			if(bc_T_UBYTE_statusButt_Down()){
				if(ruw_lpit0_ch0_counter1ms>=_400ms){
					wc_void_ControlWindowDown (&rub_Percentwindow);
					rub_Percentwindow--;
					ruw_lpit0_ch0_counter1ms=0;
			}

				}

		}

		if(rs_Fg.bi1_flagSemiautomaticUp){
			if(bc_T_UBYTE_statusButt_Up()){
				if(ruw_lpit0_ch0_counter1ms>=_400ms){
					rub_Percentwindow++;
					wc_void_ControlWindowUp (&rub_Percentwindow);
					ruw_lpit0_ch0_counter1ms=0;
				}

			}

		}

		/* Conditions */

		if(rs_Fg.bi1_flagSemiautomaticUp&&rub_Percentwindow==10){ /* Condiciones de la transicion state 5 - 0 */
			/* Acciones de la transicion state 5 - 0 */
			state=0;
			rs_Fg.bi1_flagSemiautomaticUp=0;
			rs_Fg.bi1_flagUp=0;
		}

		if(rs_Fg.bi1_flagSemiautomaticDown&&rub_Percentwindow==0){ /* Condiciones de la transicion state 5 - 0 */
			/* Acciones de la transicion state 5 - 0 */
			state=0;
			rs_Fg.bi1_flagSemiautomaticDown=0;
			rs_Fg.bi1_flagDown=0;
		}

		if((bc_T_UBYTE_statusButt_Up()==0)&&(rs_Fg.bi1_flagSemiautomaticUp)){ /* Condiciones de la transicion state 5 - 0 */
			/* Acciones de la transicion state 5 - 0 */
			state=0;
			rs_Fg.bi1_flagSemiautomaticDown=0;
			rs_Fg.bi1_flagDown=0;
			rs_Fg.bi1_flagSemiautomaticUp=0;
			rs_Fg.bi1_flagUp=0;
		}

		if((bc_T_UBYTE_statusButt_Down()==0)&&(rs_Fg.bi1_flagSemiautomaticDown)){ /* Condiciones de la transicion state 5 - 0 */
			/* Acciones de la transicion state 5 - 0 */
			state=0;
			rs_Fg.bi1_flagSemiautomaticDown=0;
			rs_Fg.bi1_flagDown=0;
			rs_Fg.bi1_flagSemiautomaticUp=0;
			rs_Fg.bi1_flagUp=0;
		}




		break;
		/*============================================================================================================================*/





	/*****************************************************      D E F A U L T    **************************************************/
	/*============================================================================================================================*/
	default:
		break;
	/*============================================================================================================================*/


	 }

	/*Dio_PortTooglePin(PORTCH_C, PIN_1MS);
	Dio_PortSetPin(PORTCH_C, PIN_1MS);
	for(i=0; i<=7000;i++){}
	Dio_PortClearPin(PORTCH_C, PIN_1MS);
	*/
	//Dio_PortClearPin(PORTCH_C, PIN_1MS);

}



 void SchM_2MS_Task ()
{

	//unsigned int i;

	Dio_PortTooglePin(PORTCH_B, PIN_2MS);
/*
	Dio_PortSetPin(PORTCH_B, PIN_2MS);
	for(i=0; i<=5000;i++){}
	Dio_PortClearPin(PORTCH_B, PIN_2MS);
	*/

}


/* Notice: the file ends with a blank new line to avoid compiler warnings */



