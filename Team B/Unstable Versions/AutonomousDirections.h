#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Motor,  mtr_S1_C2_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    door,                 tServoStandard)
#pragma config(Motor,  mtr_S1_C3_1,     elevator_motor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     intake_motor,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'R !!*//
// GOES FORWARD :)

void forward(int pwr,int rotations){
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations){
		motor[LeftFront] = pwr;
		motor[RightFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
	}
}

void backward(int pwr,int rotations){
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = false;
		while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations){
		motor[LeftFront] = pwr;
		motor[RightFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
	}
}
// TURNS RIGHT >.>
void turnright(int pwr,int rotations){
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = pwr;
		motor[RightFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
		wait10Msec(10);
	}
}
//TURNS LEFT <.<
void turnleft(int pwr,int rotations){
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = false;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = pwr;
		motor[RightFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
		wait10Msec(10);

	}
}
void allstop (void) {
		motor[RightFront] = 0;
		motor[LeftFront] = 0;
		motor [RightRear] = 0;
		motor [LeftRear] = 0;
	}
