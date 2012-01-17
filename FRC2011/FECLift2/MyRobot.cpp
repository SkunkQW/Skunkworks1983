#include "WPILib.h"

#define JAGNUM 2
#define TICKS 250 
//ticks per revolution
#define MAXVOLT 12.0 
//max output voltage
#define UNITSPERMETER 879 
//units for Set() per meter

class FECLift : public SimpleRobot{
public:
	CANJaguar *theJag;
	DriverStation *driverStation;
	
	FECLift()
	{
		//initialized the jag
		theJag = new CANJaguar(JAGNUM,CANJaguar::kPosition);
		theJag->ConfigEncoderCodesPerRev(TICKS);
		theJag->ConfigMaxOutputVoltage(MAXVOLT);
		theJag->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		theJag->SetPositionReference(CANJaguar::kPosRef_QuadEncoder);
		
		GetWatchdog().SetExpiration(.3);
	}
	
	void Autonomous()
	{
	}
	
#define SETPOINT_METERS 0.5
	
	void OperatorControl()
	{	
		//setup watchdog	
		GetWatchdog().SetEnabled(true);
		GetWatchdog().SetExpiration(0.3);
		
		while (IsOperatorControl())
		{	
			printf("Entering main loop\n");
			theJag->Set(SETPOINT_METERS * UNITSPERMETER);
			GetWatchdog().Feed();
		}
	}	
};


START_ROBOT_CLASS(FECLift);

