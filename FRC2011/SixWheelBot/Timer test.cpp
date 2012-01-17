#if 0
#include "WPILib.h"

int main(void)
{
	int oldTime;
	int newTime;
	int oldEncoder;
	int newEncoder;
	oldTime = GetClock();
	oldEncoder = encoder.GetRaw();
	int timeChange;
	int encoderChange;
	float velocity; 
	
	
}
float GetSpeed(int oldTime, int oldEncoder)
{
	newTime = GetClock();
	newEncoder = encoder.GetRaw();
	timeChange = newTime - oldTime;
	encoderChange = newEncoder - oldEncoder;
	velocity = encoderChange / timeChange;  
	feetPerSecond = velocity * (6*3.14/12/250)* 1000;
}
#endif