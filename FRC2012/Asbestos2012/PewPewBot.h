#include "WPILib.h"
#include "1983Defines2012.h"
#include "C1983Drive.h"

class PewPewBot : public SimpleRobot
{
public:
	C1983Drive *drive;
	/*
	C1983Collector collector;
	C1983Shooter shooter;
	C1983Tipper tipper;
	C1983Camera camera;
	*/
	
	//Controls
	Joystick *lStick;
	Joystick *rStick;
	
	PewPewBot();
	void Autonomous();
	void OperatorControl();
	void Disabled();
	~PewPewBot();
};
