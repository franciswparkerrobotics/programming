#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S4,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "AutonomousDirections.h"
#include "AMPowerFormula.h"

task main()
{
//power,rotations
//2500 is around 1 rotation
//2500 rotations turn is 90 degrees

//1. Drives off Ramp
//2. Move rolling goal to parking zone
backward(50,10000);
//grab goal
turnleft(100,2500);
backward(100,2500);
moveright(100,10000);
backward(100,2500);
//release goal
moveleft(100,5000);
allstop();
//3. Score in 30cm goal

//4. Knock over Center Poll
//Need IR Beacon Stuff Here


}
