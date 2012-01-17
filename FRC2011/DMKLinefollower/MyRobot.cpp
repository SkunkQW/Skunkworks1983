#include "WPILib.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class SixWheelBot : public SimpleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick stickL; //Port 1
	Joystick stickR; //Port 2
	DigitalInput *left;			// digital inputs for line tracking sensors
	DigitalInput *middle;
	DigitalInput *right;

public:
	SixWheelBot(void):
		//BUGBUG This probably won't work right now--don't run it
		myRobot(1, 2, 3, 4),	// these must be initialized in the same order
		stickL(1), stickR(2)		// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
		left = new DigitalInput(1);
		middle = new DigitalInput(2);
		right = new DigitalInput(3);
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

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl(void)
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl())
		{
			myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			Wait(0.005);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(DMKLineFollower);

