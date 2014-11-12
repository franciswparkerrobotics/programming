#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S4,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'R !!*//
// GOES FORWARD :)

int lpwr(int pwr){
if(nMotorEncoder[RightRear] > nMotorEncoder[LeftRear]){
	pwr += 1;
//	checkSync(pwr,rotations);
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 1;
}
return pwr;
}

int rpwr(int pwr){
if(nMotorEncoder[LeftRear] > nMotorEncoder[RightRear]){
	pwr += 1;
//	checkSync(pwr,rotations);
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 1;
}
return pwr;
}

void getRotations(int rpwr, int lpwr){
if(rpwr < lpwr){
nMotorEncoder[RightRear] = nMotorEncoder[LeftRear];
}else if(lpwr < rpwr){
nMotorEncoder[LeftRear] = nMotorEncoder[RightRear];
}else{

}
}

void forward(int pwr,int rotations){
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations){
		getRotations(rpwr(pwr),lpwr(pwr));
		motor[LeftFront] = lpwr(pwr);
		motor[RightFront] = rpwr(pwr);
		motor[RightRear] = rpwr(pwr);
		motor[LeftRear] = lpwr(pwr);
	}
}
// GOES BACKWARD (:
void backward(int pwr,int rotations){
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = false;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations){
		motor[RightFront] = pwr;
		motor[LeftFront] = pwr;
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
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations){
		motor[RightFront] = pwr;
		motor[LeftFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
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
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations){
		motor[RightFront] = pwr;
		motor[LeftFront] = pwr;
		motor[RightRear] = pwr;
		motor[LeftRear] = pwr;
	}
}
//movesright

void moveright (int pwr, int rotations) {
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = true;
	bMotorReflected[LeftFront] = true;
	bMotorReflected[RightRear] = false;
	bMotorReflected[LeftRear] = false;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations) {
		motor[RightFront] = pwr;
		motor[LeftFront] = pwr;
		motor [RightRear] = pwr;
		motor [LeftRear] = pwr;
	}
}

void moveleft (int pwr, int rotations) {
	nMotorEncoder[RightRear] = 0;
	nMotorEncoder[LeftFront] = 0;
	nMotorEncoder[RightFront] = 0;
	nMotorEncoder[LeftRear] = 0;
	bMotorReflected[RightFront] = false;
	bMotorReflected[LeftFront] = false;
	bMotorReflected[RightRear] = true;
	bMotorReflected[LeftRear] = true;
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftRear] <= rotations && nMotorEncoder[LeftFront] <= rotations && nMotorEncoder[RightRear] <= rotations) {
		motor[RightFront] = pwr;
		motor[LeftFront] = pwr;
		motor [RightRear] = pwr;
		motor [LeftRear] = pwr;
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
