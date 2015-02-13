#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     RightRear,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     LeftRear,      tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     elevator_motor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     intake_motor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     LeftFront,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     RightFront,    tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    door,                 tServoStandard)
int rotations;
task main()
{
nMotorEncoder[RightFront] = 0;
while(true){
while(nMotorEncoder[RightFront] < 1){
motor[RightFront] = 100;
rotations = nMotorEncoder[RightFront];
}
}
}
