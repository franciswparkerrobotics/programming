#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S4,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightRear,     tmotorTetrix, openLoop, reversed)
//#pragma systemfile
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 * $Id: hitechnic-irseeker-v2-test1.c 133 2013-03-10 15:15:38Z xander $
 */

#include "drivers/hitechnic-irseeker-v2.h"
#include "Autonomous/AutonomousDirections.h"
// global variables
//int dirAC_A = 0;
int dirDC_A = 0;
//int dir_A = 0;
//int dir_B = 0;
  /*
/*
int dcS1_A, acS1_A = 0;
int dcS2_A, acS2_A = 0;
int dcS3_A, acS3_A = 0;
int dcS4_A, acS4_A = 0;
int dcS5_A, acS5_A = 0;
*/

//int dirAC_B = 0;
int dirDC_B = 0;
/*
int dcS1_B, acS1_B = 0;
int dcS2_B, acS2_B = 0;
int dcS3_B, acS3_B = 0;
int dcS4_B, acS4_B = 0;
int dcS5_B, acS5_B = 0;
*/
bool done = false;


task main ()

{

  while(done == false){
  // Read the current non modulated signal direction
  dirDC_A = HTIRS2readDCDir(HTIRS2A);
  dirDC_B = HTIRS2readDCDir(HTIRS2B);
	//dir_A = dirDC_A;
	//dir_B = 10 - dirDC_B;
  /*
  // read the current modulated signal direction
  dirAC_A = HTIRS2readACDir(HTIRS2A);
  dirAC_B = HTIRS2readACDir(HTIRS2B);

  // These read the 5 individual sensor in IRA and IRB for AC and DC
   HTIRS2readAllDCStrength(HTIRS2A, dcS1_A, dcS2_A, dcS3_A, dcS4_A, dcS5_A);
   HTIRS2readAllACStrength(HTIRS2A, acS1_A, acS2_A, acS3_A, acS4_A, acS5_A);
   HTIRS2readAllDCStrength(HTIRS2B, dcS1_B, dcS2_B, dcS3_B, dcS4_B, dcS5_B);
   HTIRS2readAllACStrength(HTIRS2B, acS1_B, acS2_B, acS3_B, acS4_B, acS5_B);
  */

	if(10 - dirDC_B>dirDC_A) {
		turnleft(50,100);
	}
	else if (dirDC_A>10 - dirDC_B) {
		turnright(50,100);
	}
	else if (10 - dirDC_B==dirDC_A) {
		forward(50,100);
	}

	if(dirDC_B == 9 && (10 - dirDC_B) == 9){
		allstop();
		done = true;
	}
	wait1Msec(50);
}
}
