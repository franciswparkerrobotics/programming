#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     RightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     RightRear,     tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
task leftj(){
   // update buttons and joysticks
		getJoystickSettings(joystick);
	  //Left Joystick
	  if (joystick.joy1_y1 < 15 && joystick.joy1_y1 > -15){
	  	joystick.joy1_y1 = 0;
	  }
	  if (joystick.joy1_x1 < 15 && joystick.joy1_x1 > -15){
	  	joystick.joy1_x1 = 0;
	  }
	  float rfdrive = joystick.joy1_y1 + joystick.joy1_x1;
	  motor[RightFront] = rfdrive;  // motorB's powerlevel is set to the left stick's current x-value

	  float lfdrive = joystick.joy1_y1 - joystick.joy1_x1;
	  motor[LeftFront] = lfdrive;

	  float rrdrive = joystick.joy1_y1 - joystick.joy1_x1;
	  motor[RightRear] = rrdrive;  // motorB's powerlevel is set to the left stick's current x-value

	  float lrdrive = joystick.joy1_y1 + joystick.joy1_x1;
	  motor[LeftRear] = lrdrive;
}
task rightj(){
	//Right Joystick
	  getJoystickSettings(joystick);
	  if (joystick.joy2_x2 < 15 && joystick.joy2_x2 > -15){
	  	joystick.joy2_x2 = 0;
	  }
	  float rpower = joystick.joy2_x2;
	  float lpower = abs(joystick.joy2_x2);

	  motor[RightFront] = rpower;
	  motor[LeftFront] = lpower;
	  motor[RightRear] = rpower;
	  motor[LeftRear] = lpower;
}

task main()
{
  initializeRobot();
  waitForStart();   // wait for start of tele-op phase
  bFloatDuringInactiveMotorPWM = false;
  StartTask(leftj);
  StartTask(rightj);
  while(true){
  wait1Msec(10);
  }
}
