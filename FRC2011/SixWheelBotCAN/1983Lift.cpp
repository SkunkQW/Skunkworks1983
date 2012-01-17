#include "WPILib.h"
#include "1983Defines.h"

class C1983_Lift
{
private:
	Encoder *m_liftSensor;
	Relay *m_brake;
	bool m_bIsBraking;
	
public:
	C1983_Lift(Encoder *liftSensorChannel, Relay *brake)
	{
		m_liftSensor = liftSensorChannel;
		m_brake = brake;
		m_bIsBraking = true;
		
		m_brake->SetDirection(m_brake->kBothDirections);
		m_liftSensor->SetDistancePerPulse((float)LIFTDISTPERPULSE);
	}
	
	//returns position from 0 (all the way at the bottom) to 1 (all the way at the top)
	double getPosition()
	{
		return m_liftSensor->GetDistance()/LIFTHEIGHT;
	}
	bool isBraking()
	{
		return m_bIsBraking;
	}
	void toggleBrake()
	{
		if(isBraking())
		{
			m_brake->Set(m_brake->kForward);
			m_bIsBraking = false;
		}
		else
		{
			m_brake->Set(m_brake->kReverse);
			m_bIsBraking = true;
		}
	}
	void brakeOn()
	{
		m_brake->Set(m_brake->kReverse);
		m_bIsBraking = true;
	}
	void brakeOff()
	{
		m_brake->Set(m_brake->kForward);
		m_bIsBraking = false;
	}
};

class LiftPIDSource	: public PIDSource
{
public:
	LiftPIDSource(C1983_Lift *lift)
	{
		m_lift = lift;
		
	}
	
	double PIDGet()
	{
		return m_lift->getPosition();
	}
private:
	C1983_Lift *m_lift;
};

class LiftPIDOutput : public PIDOutput 
{	
public:
	friend class RobotDrive;
	SpeedController	*m_liftMotor1;
	SpeedController *m_liftMotor2;
	
	LiftPIDOutput::LiftPIDOutput(SpeedController *liftMotor1, SpeedController *liftMotor2) 
	{
		m_liftMotor1 = liftMotor1;
		m_liftMotor2 = liftMotor2;
	}	
	void LiftPIDOutput::PIDWrite(float output) 
	{
		m_liftMotor1->Set(output + LIFTNEUTRALPOWER);
		m_liftMotor2->Set(output + LIFTNEUTRALPOWER);
	}
};

class GripPIDSource : public PIDSource
{
private:
	AnalogChannel *m_potentiometer;
public:
	GripPIDSource::GripPIDSource(AnalogChannel *potentiometer)
	{
		m_potentiometer = potentiometer;
	}
	double GripPIDSource::PIDGet()
	{
		return (m_potentiometer->GetVoltage() - 0.33)/1.7;
	}
};

class GripPIDOutput : public PIDOutput
{
private:
	SpeedController *m_motor1;
	//SpeedController *m_motor2;
public:
	GripPIDOutput::GripPIDOutput(SpeedController *motor1/*, SpeedController *motor2*/)
	{
		m_motor1 = motor1;
		//m_motor2 = motor2;
	}
	void GripPIDOutput::PIDWrite(float output)
	{
		m_motor1->Set(output);
		//m_motor2->Set(-output);
	}
};
