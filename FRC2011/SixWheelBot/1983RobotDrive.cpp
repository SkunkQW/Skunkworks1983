#include "WPILib.h"

class C1983RobotDrive: public RobotDrive
{
public:
	
	C1983RobotDrive(UINT32 frontLeftMotorChannel, UINT32 rearLeftMotorChannel,
				UINT32 frontRightMotorChannel, UINT32 rearRightMotorChannel);
	void C1983RobotDrive::TankDrive(float leftValue, float rightValue);
	void C1983RobotDrive::SetLeftRightMotorOutputs(float leftOutput, float rightOutput);


};

C1983RobotDrive::C1983RobotDrive(UINT32 frontLeftMotorChannel, UINT32 rearLeftMotorChannel,
			UINT32 frontRightMotorChannel, UINT32 rearRightMotorChannel)
			: RobotDrive(frontLeftMotorChannel, rearLeftMotorChannel,
			frontRightMotorChannel, rearRightMotorChannel)
{
	return;
}

void C1983RobotDrive::TankDrive(float leftValue, float rightValue)
{
	// square the inputs (while preserving the sign) to increase fine control while permitting full power
	leftValue = Limit(leftValue);
	rightValue = Limit(rightValue);
	if (leftValue >= 0.0)
	{
		leftValue = (leftValue * leftValue);
	}
	else
	{
		leftValue = -(leftValue * leftValue);
	}
	if (rightValue >= 0.0)
	{
		rightValue = (rightValue * rightValue);
	}
	else
	{
		rightValue = -(rightValue * rightValue);
	}

	SetLeftRightMotorOutputs(leftValue, rightValue);
}

void C1983RobotDrive::SetLeftRightMotorOutputs(float leftOutput, float rightOutput)
{
	wpi_assert(m_rearLeftMotor != NULL && m_rearRightMotor != NULL);

	UINT8 syncGroup = 0x80;

	if (m_frontLeftMotor != NULL)
		m_frontLeftMotor->Set(Limit(leftOutput) * m_invertedMotors[kFrontLeftMotor] * m_maxOutput, syncGroup);
	m_rearLeftMotor->Set(Limit(leftOutput) * m_invertedMotors[kRearLeftMotor] * m_maxOutput, syncGroup);

	
	if (m_rearLeftMotor != NULL)
		m_rearLeftMotor->Set(Limit(leftOutput) * m_invertedMotors[kRearLeftMotor] * m_maxOutput, syncGroup);
	m_rearLeftMotor->Set(Limit(leftOutput) * m_invertedMotors[kRearLeftMotor] * m_maxOutput, syncGroup);

	
	if (m_frontRightMotor != NULL)
		m_frontRightMotor->Set(-Limit(rightOutput) * m_invertedMotors[kFrontRightMotor] * m_maxOutput, syncGroup);
	m_rearRightMotor->Set(-Limit(rightOutput) * m_invertedMotors[kRearRightMotor] * m_maxOutput, syncGroup);

	CANJaguar::UpdateSyncGroup(syncGroup);

	m_safetyHelper->Feed();
}


