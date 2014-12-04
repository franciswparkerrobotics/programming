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
float rightp;
float leftp;

//Left Power Forward
float lpwr(float pwr){
if(nMotorEncoder[RightRear] - 50 > nMotorEncoder[LeftRear]){
	pwr += 0.5;
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear] - 50){
	pwr -= 0.5;
}
return pwr;
}

//Right Power Forward
float rpwr(float pwr){
if(nMotorEncoder[LeftRear] - 50 > nMotorEncoder[RightRear]){
	pwr += 0.5;
	return pwr;
}else if(nMotorEncoder[RightRear] - 50 > nMotorEncoder[LeftRear]){
	pwr -= 0.5;
}
return pwr;
}

//Left Power Backwards
float lpwrb(float pwr){
if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 0.5;
	return pwr;
}else if(nMotorEncoder[RightRear] > nMotorEncoder[LeftRear]){
	pwr += 0.5;
}
return pwr;
}

//Right Power Backwards
float rpwrb(float pwr){
if(nMotorEncoder[LeftRear] < nMotorEncoder[RightRear]){
	pwr += 0.5;
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 0.5;
}
return pwr;
}

void forward(float pwr,int rotations){
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightRear] <= rotations && nMotorEncoder[LeftRear] <= rotations){
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);
	}
}
int globalA;
int globalB;
// GOES BACKWARD (:
void backward(float pwr,int rotations){
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = false;
		while(nMotorEncoder[RightRear] <= rotations && nMotorEncoder[LeftRear] <= rotations){
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		globalA = nMotorEncoder[RightFront];
		globalB = nMotorEncoder[LeftFront];
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);
}
	}
// TURNS RIGHT >.>
void turnright(float pwr,int rotations){
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;

	}
}
//TURNS LEFT <.<
void turnleft(float pwr,int rotations){
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = false;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;

	}
}
//movesright

void moveright (float pwr, int rotations) {
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = false;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
	}
}

void moveleft (float pwr, int rotations) {
	rightp = pwr;
	leftp = pwr;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;

	}
}
void allstop (void) {
		motor[RightFront] = 0;
		motor[LeftFront] = 0;
		motor [RightRear] = 0;
		motor [LeftRear] = 0;
	}
	//THIS MAY NOT WORK
void offramp (void) {
forward(100,2400);
turnright(100,1200);
}
