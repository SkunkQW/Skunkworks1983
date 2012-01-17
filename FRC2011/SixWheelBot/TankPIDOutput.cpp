#include "WPILib.h"
#include "RobotDrive.h"
#include "PIDController.h"
#include "PIDOutput.h"

class TankPIDOutput : public PIDOutput 
{
public:
	friend class RobotDrive;
	SpeedController	*m_motor1;
	SpeedController  *m_motor2;
	TankPIDOutput::TankPIDOutput(SpeedController *motor1, SpeedController *motor2, bool bInvert) 
	{
		m_motor1 = motor1;
		m_motor2 = motor2;
		m_bInvert = bInvert;
	}	
	void TankPIDOutput::PIDWrite(float output) 
	{
		m_bInvert ? m_motor1->Set(-output) : m_motor1->Set(output);
		m_bInvert ? m_motor2->Set(-output) : m_motor2->Set(output);
	}
private:
	bool m_bInvert;
};
