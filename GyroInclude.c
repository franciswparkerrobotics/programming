#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rightfront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftfront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightrear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftrear,      tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "GyroAuto.c"
#include "GPDProtocol.h"

void forward(int pwr,int degrees){
while( setJoysticks(pwr/100,0,0,0) != degrees){}//add ratio!!
}
void backward(int pwr,int degrees){
while( setJoysticks(-1*pwr/100,0,0,0) != degrees){}//add ratio!!
}
void turnright(int pwr,int degrees){
while( setJoysticks(0,pwr/100,0,0) != degrees){}//add ratio!!
}
void turnleft(int pwr,int degrees){
while( setJoysticks(0,0,pwr/100,0) != degrees){}//add ratio!!
}
