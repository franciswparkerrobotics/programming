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
//#include "James.c"
int RR, LR, RF, LF = 0;
task showEncoders{
	nMotorEncoder[RightRear]=0;
	nMotorEncoder[LeftRear]=0;
  nMotorEncoder[RightFront]=0;
	nMotorEncoder[LeftFront]=0;
	while(1){
	RR = nMotorEncoder[RightRear];
	LR = nMotorEncoder[LeftRear];
  RF = nMotorEncoder[RightFront];
	LF = nMotorEncoder[LeftFront];
}
}
//task main(){StartTask(showEncoders);Motor[RightRear]=100;Motor[LeftRear]=100;while(1){wait10Msec(100);}}
task main()
{
 waitForStart();
//power,rotations
//1440 is around 1 rotation
//2500 rotations turn is 90 degrees
//backward(10,10000);

StartTask(showEncoders);

			//Initialize servos
		 	servo[LeftGoal] = 140;
     	servo[RightGoal] = 90;
     	servo[Dumper30]= 230;
     	servo[Dumper60]=250;
      moveleft(50,6000);
     	//1. Drives off Floor
     	sbackward(100,10000);

    wait10Msec(20);
		allstop();
			wait1Msec(300);

			turnleft(100,50);
			backward(50,500);
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
      servo[Dumper30]=0;
			wait1Msec(2000);
			servo[Dumper30]= 230;
			turnright(50,6000);
			forward(50,250);
			sbackward(100,4000);
			turnright(50,700);
			sbackward(100,9000);
	//		turnleft(50,4000);
	//		backward(100,1000);
			//smoveright(50,1000);
			//wait1Msec(500);
			//sbackward(30,1000);s

			//wait1Msec(300);
			//sturnleft(30,3000);

			//wait1Msec(300);
			//sbackward(30,12000);




//forward(50,100000)

//sforward(50,8000);
//forward(50,8000);
}