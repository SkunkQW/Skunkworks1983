#if 0
#include "WPILib.h"

class EncoderBot : public SimpleRobot
{
	Encoder *rightEncoder;
	Encoder *leftEncoder;
	
public:
	EncoderBot(void)
	{
		rightEncoder = new Encoder(4, 5, false);
		leftEncoder = new Encoder(6,7,false);
	}
	void OperatorControl()
			{
				double speed = 0;
				while(IsOperatorControl())
				{
					speed = rightEncoder->GetRate();
				}
			}
};

START_ROBOT_CLASS(EncoderBot);
#endif
