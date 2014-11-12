#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S4,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)
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
task main()
{
forward(10,5000);
}
