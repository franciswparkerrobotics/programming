#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     HTIRS2A,        sensorI2CCustom)
#pragma config(Sensor, S4,     HTIRS2B,        sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)

int rightp;
int leftp;
int global1;
int global2;
int lpwr(int pwr){
if(nMotorEncoder[RightRear] - 50 > nMotorEncoder[LeftRear]){
	pwr += 1;
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear] - 50){
	pwr -= 1;
}
return pwr;
}

int rpwr(int pwr){
if(nMotorEncoder[LeftRear] - 50 > nMotorEncoder[RightRear]){
	pwr += 1;
	return pwr;
}else if(nMotorEncoder[RightRear] - 50 > nMotorEncoder[LeftRear]){
	pwr -= 1;
}
return pwr;
}

void forward(int pwr,int rotations){
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
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		global1 = nMotorEncoder[RightRear];
		global2 = nMotorEncoder[LeftRear];
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);
	}
}
task main()
{
forward(30,10000);
}
