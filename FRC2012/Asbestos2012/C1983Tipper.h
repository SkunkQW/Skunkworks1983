#ifndef __C1983TIPPER_H
#define __C1983TIPPER_H
#include "1983Defines2012.h"
#include "WPILib.h"

class C1983Tipper
{
private:
	Solenoid Tipper;	

public:
	C1983Tipper();
	//Turn Tipper on
	void setSpeedL(float speed);
	
	//Set the speed of the right side
	void Tip(bool open);
	
	/*
	if(bool)
	{
		Tipper->Set(true);
	}
	else
	{
		Tipper->Set(false);
	}
	
	*/
	
	~C1983Tipper();
};
#endif