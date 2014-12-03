#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     RightRear,     tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     LeftRear,      tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     elevator_motor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     intake_motor,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     LeftFront,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     RightFront,    tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C1_1,    grabber1_servo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    grabber2_servo,             tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    door,                 tServoStandard)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int globala;
int globalb;
int globalc;
int globald;

task main()
{
servo[grabber1_servo] = 0;
servo[grabber2_servo] = 255;
wait10Msec(100);
}
