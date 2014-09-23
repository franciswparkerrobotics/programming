#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightfront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftfront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightrear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftrear,      tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "AutonomousDirections.h"

task main()
{
//power,rotations
//1200 is around 1 rotation
forward(50,1200);
wait1Msec(2000);
turnright(50,1000);
wait1Msec(2000);
turnleft(50,1000);
wait1Msec(2000);
backward(50,3600);
}
