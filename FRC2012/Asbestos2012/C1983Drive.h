#ifndef __C1983DRIVE_H
#define __C1983DRIVE_H
#include "1983Defines2012.h"
#include "WPILib.h"


class C1983Drive
{
private:
	Jaguar *leftJag1;
	Jaguar *leftJag2;
	Jaguar *rightJag1;
	Jaguar *rightJag2;
	
	/*
	Encoder *FakeEncoder1;
	Encoder *encoderLeft;
	Encoder *FakeEncoder2;
	Encoder *encoderRight;
	*/
	
public:
	C1983Drive();
	//Set the speed of the left side -1 to 1
	void setSpeedL(float speed);
	
	//Set the speed of the right side
	void setSpeedR(float speed);
	
	/*
	//Get the speed of the left side
	float getSpeedL();
	
	//Get the speed of the right side
	float getSpeedR();
	
	//Get the current angle of the robot
	float getAngle();
	
	//Reset the Gyro
	float resetGyro();
	
	//Reset the PID's I term
	float resetI();
	
	//Move a certain distance
	void move(float distance);
	*/
	~C1983Drive();
};
#endif
