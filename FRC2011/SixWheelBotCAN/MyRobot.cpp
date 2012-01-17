#if 0
#include "math.h"
#include "WPILib.h"

class SixWheelBot : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stickL; //Port 1
	Joystick stickR; //Port 2

public:
	SixWheelBot(void):
		//BUGBUG This probably won't work right now--don't run it
		myRobot(3, 4, 1, 2),	// these must be initialized in the same order
		stickL(1), stickR(2)		// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	*/
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
		float leftSpeed,rightSpeed;
		while (IsOperatorControl())
		{
//			myRobot.Drive (0.25, 0.0);
			leftSpeed = stickL.GetY() * stickL.GetY() * (stickL.GetY()/fabs(stickL.GetY()));
			rightSpeed = stickR.GetY() * stickR.GetY() * (stickR.GetY()/fabs(stickR.GetY()));
			myRobot.TankDrive(leftSpeed,rightSpeed); // drive with tank drive with squared inputs
			Wait(0.01);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(SixWheelBot);
#endif
