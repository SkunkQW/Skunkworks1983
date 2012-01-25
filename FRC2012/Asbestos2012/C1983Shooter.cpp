#include "C1983Shooter.h"
#include "Jaguar.h"

void C1983Shooter::shoot()
{

}

void C1983Shooter::setVelocity(float velocity)
{

}

float C1983Shooter::getVelocity()
{

}

bool C1983Shooter::isReady()
{
	float diff = getVelocity() - TARGET_SHOOT_VELOCITY;
	return diff >= -SHOOT_VELOCITY_TOLERANCE && diff<=SHOOT_VELOCITY_TOLERANCE;
}

void C1983Shooter::run()
{
	if (isRunning())
	{
		//Get some stuff up to speed!
	}
}

bool C1983Shooter::isRunning()
{
	return isRunning;
}

void C1983Shooter::setIsRunning(bool state)
{
	isRunning = state;
}