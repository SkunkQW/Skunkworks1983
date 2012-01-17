/*
#include "WPILib.h"

class SixWheelBot : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick

public:
	SixWheelBot(void):
		myRobot(1, 2, 3, 4),	// these must be initialized in the same order
		stick(1)		// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 (end comment here)
	void Autonomous(void)
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(false);
		//myRobot.SetInvertedMotor(kFrontLeftMotor, true);
		//	myRobot.SetInvertedMotor(3, true);
		while (IsOperatorControl())
		{
//			myRobot.Drive (0.25, 0.0);
			//myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			myRobot.m_frontLeftMotor->Set(0.5);
			Wait(2.0);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(SixWheelBot);

*/