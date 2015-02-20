#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     RightRear,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     LeftRear,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     elevator_motor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     intake_motor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     LeftFront,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     RightFront,    tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    door,                 tServoStandard)

#include "hitechnic-irseeker-v2.h"
#include "JoystickDriver.c"
#include "AutonomousDirections.h"

task main()
{
HTIRS2_AC_DIR = HTIRS2readACDir;
if(HTIRS2_AC_DIR == 4){
	forward(100,3000);
}else{
	turnleft(100,1500);
	forward(100,2500);
	HTIRS2_AC_DIR = HTIRS2readACDir;
	if(HTIRS2_AC_DIR == 1){
	turnleft(100,2500);
	forward(100,2500);
	}else{
		while(HTIRS2_AC_DIR != 1){
		forward(100,500);
		HTIRS2_AC_DIR = HTIRS2readACDir;
	}
		while(HTIRS2_AC_DIR < 5){
		turnleft(100,500);
		HTIRS2_AC_DIR = HTIRS2readACDir;
	}
	forward(100,3000);
	}
}
}
}
