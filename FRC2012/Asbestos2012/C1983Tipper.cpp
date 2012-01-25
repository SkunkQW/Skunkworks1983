#include "C1983Tipper.h"
C1983Tipper::C1983Tipper()
{
	tipper = new Solenoid(TIPPERPORT);
}

/*
 * Created: January 23, 2012
 * By: Quinn Schiller
 * 
 * Last Updated: January 24, 2012
 * By: Quinn Schiller
 * 
 */

//Raises and lowers 
void C1983Tipper::tip(bool open)
{
	if(open==true)
	{
		tipper->Set(false);
		open = false;
	}
	else
	{
		tipper->Set(true);
		open = true;
	}
};

//Gets state
bool C1983Tipper::getState()
{
	return tipperState;
};

