#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightRear,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    Dumper,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "AutonomousDirections.h"

task main()
{
//power,rotations
//1440 is around 1 rotation
//2500 rotations turn is 90 degrees
//backward(10,10000);



			//Initialize servos
		 	servo[LeftGoal] = 0;
     	servo[RightGoal] = 230;

     	//1. Drives off Ramp
			forward(30,10000);
			allstop();
			wait1Msec(300);
			//2. Grab the goal
			servo[LeftGoal] = 230;
      servo[RightGoal] = 0;
			wait1Msec(1000);
//3. Drop the ball
			//4. Move to parking zone
			moveleft(50,3500);
			allstop();
			wait1Msec(300);
			backward(30,9500);
			allstop();
			wait1Msec(300);
			turnleft(30,3000);
			allstop();
			wait1Msec(300);
			forward(30,1000);
			allstop();



//forward(50,100000)




}
