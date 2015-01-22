#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S3,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     rightfront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftfront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightrear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftrear,      tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../AutonomousDirections.h"
#include "IR_reader.h"

task main()
{
StartTask(readSensor);
while(dirDC_A <= dirDC_B){
moveleft(50,300);
}
int angle1 = dirDC_A * 20;
int angle2 = dirDC_B * 20;
int angle3 = 180 - angle1 - angle2;
float fangle1 = sin(angle1);
float fangle2 = sin(angle2);
float fangle3 = sin(angle3);
float dist1 = 18 / fangle1;
float dist2 = dist1 * fangle2;
float dist3 = dist1 * fangle3;
int distance = (dist2 + dist3) / 2;
while(distance >= 6){
forward(50,300);
}
}