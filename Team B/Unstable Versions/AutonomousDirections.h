
//*!!Code automatically generated by 'R !!*//
// GOES FORWARD :)

int rightp;
int leftp;

//Left Power Forward
int lpwr(int pwr){
if(nMotorEncoder[RightRear] > nMotorEncoder[LeftRear]){
	pwr += 1;
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 1;
}
return pwr;
}

//Right Power Forward
int rpwr(int pwr){
if(nMotorEncoder[LeftRear] > nMotorEncoder[RightRear]){
	pwr += 1;
	return pwr;
}else if(nMotorEncoder[RightRear] > nMotorEncoder[LeftRear]){
	pwr -= 1;
}
return pwr;
}

//Left Power Backwards
int lpwrb(int pwr){
if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
	pwr -= 1;
	return pwr;
}else if(nMotorEncoder[RightRear] > nMotorEncoder[LeftRear]){
	pwr += 1;
}
return pwr;
}

//Right Power Backwards
int rpwrb(int pwr){
if(nMotorEncoder[LeftRear] < nMotorEncoder[RightRear]){
	pwr += 1;
	return pwr;
}else if(nMotorEncoder[RightRear] < nMotorEncoder[LeftRear]){
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
void backward(int pwr,int rotations){
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
		leftp = lpwrb(leftp);
		rightp = rpwrb(rightp);
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
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
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
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);

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
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);

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
	while(nMotorEncoder[RightFront] <= rotations && nMotorEncoder[LeftFront] <= rotations){
		leftp = lpwr(leftp);
		rightp = rpwr(rightp);
		motor[LeftFront] = leftp;
		motor[RightFront] = rightp;
		motor[RightRear] = rightp;
		motor[LeftRear] = leftp;
		wait10Msec(10);

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
