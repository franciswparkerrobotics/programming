#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     RightRear,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     LeftRear,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     RightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     LeftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     hwShooter,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     Feeder,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     Elevator,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    LeftGoal,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    RightGoal,            tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    Dumper60,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    Dumper30,             tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
task main()
{
while(1){
if (nNxtButtonPressed == 1){
motor[Elevator] = 50;}
else if (nNxtButtonPressed == 2) {
motor[Elevator] = -50;}
else {motor[Elevator] = 0;}

}
}
