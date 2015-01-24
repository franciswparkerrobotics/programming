#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     hwShooter,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    Dumper60,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    Dumper30,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "JoystickDriver.c"
#include "SyncedAutonomousDirections.h"
#include "AutonomousDirections.h"
int RR, LR, RF, LF = 0;
task showEncoders{
	while(1){
	RR = nMotorEncoder[RightRear];
	LR = nMotorEncoder[LeftRear];
  RF = nMotorEncoder[RightFront];
	LF = nMotorEncoder[LeftFront];
}
}
task main()
{
//power,rotations
//1440 is around 1 rotation
//2500 rotations turn is 90 degrees
//backward(10,10000);

StartTask(showEncoders);
//			waitForStart();
			//Initialize servos
		 	servo[LeftGoal] = 140;
     	servo[RightGoal] = 90;
     	servo[Dumper60]= 100;
     	servo[Dumper30]= 230;

     	//1. Drives off Ramp
     	//forward(25,10000);
     motor[LeftFront] = 10;
		motor[RightFront] = 10;
		motor[RightRear] = 10;
		motor[LeftRear] = 10;

    wait10Msec(200);
		allstop();
		wait10Msec(200);
    sbackward(50,5000);
			wait1Msec(300);
		//	moveleft(50,3000);
		//	wait1Msec(300);
		//	allstop();
		//	forward(30,2000);
		//	wait1Msec(300);
			turnleft(100,100);
			backward(100,100);
			for (int i = 0; i <5; i++){
				turnleft(50,30);
				sbackward(50,10);
				allstop();
				turnright(50,30);
				sbackward(50,10);
				allstop();
			}
			//sbackward(30,50);
			//wait1Msec(500);
			servo[LeftGoal] = 230;
      servo[RightGoal] = 0;
      servo[Dumper60]=0;
			wait1Msec(500);
			//sforward(50,500);
			//smoveright(50,1000);
			//wait1Msec(500);
			//sbackward(30,1000);

			//wait1Msec(300);
			//sturnleft(30,3000);

			//wait1Msec(300);
			//sbackward(30,12000);




//forward(50,100000)

//sforward(50,8000);
//forward(50,8000);
}
