
#include "WPILib.h"
#include "math.h"
#include "dashboarddataformat.h"
#include "1983PIDController.h"
#include "TankPIDOutput.cpp"
#include "1983Lift.cpp"
#include "1983Defines.h"

#if !(COMPBOT)
class EncoderPIDSource : public PIDSource
{
public:
	EncoderPIDSource(Encoder *pSensor, float *maxSpeed) 
	{
		m_encoder = pSensor;
		m_maxSpeed = maxSpeed;
		m_ticks = m_encoder->Get();
		m_time = GetClock();
		m_nCount = 0;
	}
	
	double PIDGet() 
	{
		return m_encoder->GetRate()/ *m_maxSpeed;	
	}
	
private:
	Encoder	*m_encoder;
	double m_time;
	float *m_maxSpeed;
	int m_ticks;
	static int m_nCount;
};
int EncoderPIDSource::m_nCount=0;

class SixWheelBot : public SimpleRobot
{
	//RobotDrive myRobot; // robot drive system
	Jaguar *frontLeftMotor;
	Jaguar *rearLeftMotor;
	Jaguar *frontRightMotor;
	Jaguar *rearRightMotor;
	//Jaguar *liftMotor;
	Joystick stickL; //Port 1
	Joystick stickR; //Port 2
	AxisCamera &camera;
	DigitalInput *lsLeft;
	DigitalInput *lsMiddle;
	DigitalInput *lsRight;
	AnalogChannel *ultrasonic;
	Servo *camGimble;
	/*DigitalInput *bcd1;
	DigitalInput *bcd2;
	DigitalInput *bcd3;*/
	Encoder *fakeEncoderA;
	Encoder *leftEncoder;
	Encoder *fakeEncoderB;
	Encoder *rightEncoder;
	//Encoder *liftEncoder;
	Relay *light;
	DriverStation *driverStation;
	//C1983_Lift *lift;
	
	PIDController *PIDDriveLeft;
	PIDController *PIDDriveRight;
	//PIDController *PIDLift;
	EncoderPIDSource *leftPIDSource;
	EncoderPIDSource *rightPIDSource;
	//LiftPIDSource *liftPIDSource;
	TankPIDOutput *leftPIDOutput;
	TankPIDOutput *rightPIDOutput;
	//TankPIDOutput *liftPIDOutput;
	float maxSpeed;
	bool lineFollowDone; //autonomous thing
	int stopCount;
	int counts;
	bool autonomous;
	

public:
	SixWheelBot(void):
		//myRobot(1, 2, 3, 4),	// these must be initialized in the same order
		stickL(1), stickR(2), camera()		// as they are declared above.
	{
		//myRobot.SetExpiration(0.1);
		frontLeftMotor = new Jaguar(3);
		rearLeftMotor = new Jaguar(4);
		frontRightMotor = new Jaguar(1);
		rearRightMotor = new Jaguar(2);
		//liftMotor = new Jaguar(5);
		fakeEncoderA = new Encoder(8,9,false);
		leftEncoder = new Encoder(LEFTMOTORA, LEFTMOTORB, true);
		fakeEncoderB = new Encoder(10,11,false);
		rightEncoder = new Encoder(RIGHTMOTORA, RIGHTMOTORB, false);
		//liftEncoder = new Encoder(13, 14, false);
		//rightEncoder = new Encoder(13, 14, false);
		light = new Relay(1, light->kForwardOnly);
		driverStation = DriverStation::GetInstance();
		//lift = new C1983_Lift(liftEncoder);
		ultrasonic = new AnalogChannel(1 , 1);
		camGimble = new Servo(5);
		maxSpeed = 250;
		leftPIDSource = new EncoderPIDSource(leftEncoder, &maxSpeed);
		rightPIDSource = new EncoderPIDSource(rightEncoder, &maxSpeed);
		//liftPIDSource = new LiftPIDSource(lift);
		leftPIDOutput = new TankPIDOutput(frontLeftMotor, rearLeftMotor, false);
		rightPIDOutput = new TankPIDOutput(frontRightMotor, rearRightMotor, true);
		//liftPIDOutput = new TankPIDOutput(liftMotor, liftMotor, false);
		PIDDriveLeft = new PIDController(DRIVEPROPGAIN, DRIVEINTGAIN, DRIVEDERIVGAIN,
						leftPIDSource, leftPIDOutput);
		PIDDriveRight = new PIDController(DRIVEPROPGAIN, DRIVEINTGAIN, DRIVEDERIVGAIN,
				rightPIDSource, rightPIDOutput);
		//PIDLift = new PIDController(LIFTPROPGAIN, LIFTINTGAIN, LIFTDERIVGAIN,
				//liftPIDSource, liftPIDOutput);
		
		/*bcd1 = new DigitalInput(4);
		bcd2 = new DigitalInput(5);
		bcd3 = new DigitalInput(6);*/
	}


	void followLine()
	{
		float turnMod;
		bool leftValue = lsLeft->Get();
		bool middleValue = lsMiddle->Get();
		bool rightValue = lsRight->Get();
		if(leftValue && middleValue && rightValue){
			stopCount++;
			if(getDistance() < 9999999 && stopCount >= 10)
			{
				frontLeftMotor->Set(0.0);
				rearLeftMotor->Set(0.0);
				frontRightMotor->Set(0.0);
				rearRightMotor->Set(0.0);
				lineFollowDone = true;
			}
		}else if(lineFollowDone){
			if(counts % 100 == 0){printf("Stopping because lineFollowDone == true (followLine())\n");}
			frontLeftMotor->Set(0.0);
			rearLeftMotor->Set(0.0);
			frontRightMotor->Set(0.0);
			rearRightMotor->Set(0.0);
		}else{
			if(counts % 100 == 0){printf("Following the line \n");}
			stopCount = 0;
			if (middleValue){
				turnMod = 0;
			}
			else if (leftValue < rightValue)
			{
				turnMod = .1;
			}
			else if (leftValue > rightValue)
			{
				turnMod = -.1;
			}
			else
			{
				if(counts%100 == 0){printf("No line, going straight\n");}
				turnMod = 0;
			}
			//myRobot.SetLeftRightMotorOutputs(.5 - turnMod, .5 + turnMod);
			frontLeftMotor->Set(.4 + turnMod);
			rearLeftMotor->Set(.4 + turnMod);
			frontRightMotor->Set(-.4 + turnMod);
			rearRightMotor->Set(-.4 + turnMod);
		}
	}
	
	//const double fUltrasonicCalibration = 503.0/5.0;
	//const double fUltrasonicVoltageBaseline = 4.625;
	
	//Returns distance in inches
	float getDistance()
	{
		static float distance = 0.;
		distance = distance*.75 + (ultrasonic->GetVoltage()*(503.0/5.0) - .375)*.25;
		return distance;
	}
	
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */

	void Autonomous(void)
	{
		double time;
		int count = 0;
		while(IsAutonomous())
		{
			count++;
			if(!(count%10))
			{
				time = getDistance();
				printf("Rofldist: %f \n", time);
			}
			Wait(0.025);
		}
#if 0
		/*int autoMode = 0;
		autoMode |= bcd1->Get();
		autoMode <<= 1;
		autoMode |= bcd2->Get();
		autoMode <<= 1;
		autoMode |= bcd3->Get()
		;*/
		stopCount = 0;
		int autoMode = 1;
		float reduction;
		int counter = 0;
		leftEncoder->Start();
		rightEncoder->Start();
		leftEncoder->Reset();
		rightEncoder->Reset();
		leftEncoder->SetDistancePerPulse((6 * PI / 500)/reduction);
		rightEncoder->SetDistancePerPulse((6 * PI / 500)/reduction);
		lsRight = new DigitalInput(1); //light sensors
		lsMiddle = new DigitalInput(2);
		lsLeft = new DigitalInput(3);
		double avgEncoderCount;
		short int lsL,lsM,lsR;
		lineFollowDone = false;
		counts = 0;
		int x = 1;
		for(int i = 0;i < 500;i++){
			if(i % 50 == 0){
				frontLeftMotor->Set(x++ * .05);
				frontRightMotor->Set(x * -.05);
				rearLeftMotor->Set(x * .05);
				rearRightMotor->Set(x * -.05);
			}
		}
		
		while(IsAutonomous())
		{
			counts++;
			//avgEncoderCount = (leftEncoder->Get() + rightEncoder->Get())/2;
			//myRobot.SetLeftRightMotorOutputs(.2,.2);
			
			//All three/five autonomous programs will do the same thing up until the second break distance
#if 0
			if (avgEncoderCount <= FIRSTBREAKDISTANCE)
			{
				followLine();
			}else if(avgEncoderCount <= FIRSTBREAKDISTANCE + 50)
			{
				frontLeftMotor->Set(.2);
				rearLeftMotor->Set(.2);
				frontRightMotor->Set(-.2);
				rearRightMotor->Set(-.2);

			}else if (avgEncoderCount >= FIRSTBREAKDISTANCE + 50 && avgEncoderCount <= SECONDBREAKDISTANCE)
			{
				followLine();
			}
#endif
			
			if (counts % 100 == 0){//TESTING
				if(lsLeft->Get()){
					lsL = 1;
				}else{
					lsL = 0;
				}
				if(lsRight->Get()){
					lsR = 1;
				}else{
					lsR = 0;
				}
				if(lsMiddle->Get()){
					lsM = 1;
				}else{
					lsM = 0;
				}
				//printf("Encoder: %2.2f \n", (float)avgEncoderCount);
				printf("Distance: %2.2f SensorL:%1d SensorM:%1d SensorR:%1d\n",getDistance(),lsL,lsM,lsR);//TESTING
			}
			
			if(lineFollowDone && counts % 100 == 0){
				printf("DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			}
			if (getDistance() >= 0){//(avgEncoderCount <= SECONDBREAKDISTANCE){
				followLine();
			}else{
				if(counter % 100 == 0) {printf("DISTANCE: %2.2f\n",getDistance());}
				switch(autoMode)//Include actual BCD thingy later
				{
				case STRAIGHTLINEMODE: //Straight line. Scores on middle column of left or right grid.
					if(!lineFollowDone)
					{
						followLine();					//score here
					}else{
						if(counts % 100 == 0){printf("Stopping because lineFollowDone == true\n");}
						frontLeftMotor->Set(0.0);
						rearLeftMotor->Set(0.0);
						frontRightMotor->Set(0.0);
						rearRightMotor->Set(0.0);
					}
					//myRobot.SetLeftRightMotorOutputs(0,0);
					break;
				case FORKLEFTMODE: //Fork turn left. Scores on far right column of left grid.
					if(rightEncoder->Get() <= leftEncoder->Get() + 50)
					{
						printf("TURNING\n");
						frontLeftMotor->Set(0.0);
						rearLeftMotor->Set(0.0);
						frontRightMotor->Set(-.2);
						rearRightMotor->Set(-.2);
					}
					else if(getDistance() <= SCOREDISTANCE) 
					{
						followLine();
					}else{
						frontLeftMotor->Set(0.0);
						rearLeftMotor->Set(0.0);
						frontRightMotor->Set(0.0);
						rearRightMotor->Set(0.0);
						if(counts%100 == 0){printf("Done");}
					}
					//score here				
					//myRobot.SetLeftRightMotorOutputs(0,0);
					break;
				case FORKRIGHTMODE://Fork turn right. Scores on far left column of right grid.
					if(leftEncoder->GetDistance() <= rightEncoder->GetDistance() + 6)
					{
						frontLeftMotor->Set(.2);
						rearLeftMotor->Set(.2);
						frontRightMotor->Set(0);
						rearRightMotor->Set(0);
					}
					else if(getDistance() >= SCOREDISTANCE) 
					{
						followLine();
					}
					//score here				
					//myRobot.SetLeftRightMotorOutputs(0,0);
					break;
				case OUTLEFTMODE: //Go straight and turn off the line to the left. Scores on the farthest left peg.
					break;
				case OUTRIGHTMODE: //Go straight and turn off the line to the right. Scores on the farthest right column.
					break;
				}
			}
		}
		/*frontRightMotor->Set(0);
		rearRightMotor->Set(0);
		frontLeftMotor->Set(0);
		rearLeftMotor->Set(0);*/
#endif
	}

		
	void OperatorControl(void)
	{
		autonomous = false;
		rearLeftMotor->Set(0);
		frontLeftMotor->Set(0);
		rearRightMotor->Set(0);
		frontRightMotor->Set(0);
		//myRobot.SetSafetyEnabled(false);
		//myRobot.SetInvertedMotor(kFrontLeftMotor, true);
		//	myRobot.SetInvertedMotor(3, true);
		//variables for great pid
		double rightSpeed,leftSpeed;
		float rightSP, leftSP, tempLeftSP, tempRightSP;
		bool lightOn = false;
		AxisCamera &camera = AxisCamera::GetInstance();
		rightEncoder->Start();
		leftEncoder->Start();
		rightEncoder->Reset();
		leftEncoder->Reset();
		bool fastest = false; //transmission mode
		float reduction = 3; //gear reduction from 
		float maxSpeed = 500;
		float liftPower = 0;
		int count = 0;
		int i = 1;
		leftEncoder->SetDistancePerPulse((6 * PI / 500)/reduction); //6-inch wheels, 500 raw counts per revolution,
		rightEncoder->SetDistancePerPulse((6 * PI / 500)/reduction); //about 3:1 gear ratio
		//DriverStationEnhancedIO &myEIO = driverStation->GetEnhancedIO();
		
		if(fastest) {
			maxSpeed = 250;
		}
		else
		{
			maxSpeed = 250;
		}

		//PIDDriveLeft->SetOutputRange(-1, 1);
		//PIDDriveRight->SetOutputRange(-1, 1);
		//PIDDriveLeft->SetInputRange(-244,244);
		//PIDDriveRight->SetInputRange(-244,244);
		PIDDriveLeft->SetTolerance(0.075);
		PIDDriveRight->SetTolerance(0.075);
		PIDDriveLeft->SetContinuous(false);
		PIDDriveRight->SetContinuous(false);
		PIDDriveLeft->Enable();
		PIDDriveRight->Enable();

		while (IsOperatorControl())
		{
			if(fabs(stickL.GetY()) <= 0.075 )
			{
				leftSP = 0;
				PIDDriveLeft->Reset();
				PIDDriveLeft->Enable();
			}
			else leftSP = -stickL.GetY() * stickL.GetY() * (stickL.GetY()/fabs(stickL.GetY())); //set points for pid control
			if(fabs(stickR.GetY()) <= 0.075)
			{
				rightSP = 0;
				PIDDriveRight->Reset();
				PIDDriveRight->Enable();
			}
			else rightSP = -stickR.GetY() * stickR.GetY() * (stickR.GetY()/fabs(stickR.GetY()));
			
			if (stickL.GetRawButton(4))
			{
				tempRightSP = rightSP;
				tempLeftSP = leftSP;
				rightSP = -tempLeftSP;
				leftSP = -tempRightSP; //This line and above line sets opposite values for the controller. ...Theoretically.
			}
			if(!stickL.GetRawButton(1))
			{
				if(!PIDDriveLeft->IsEnabled() || !PIDDriveRight->IsEnabled())
				{
					PIDDriveLeft->Enable();
					PIDDriveRight->Enable();
				}
				PIDDriveLeft->SetSetpoint(leftSP);
				PIDDriveRight->SetSetpoint(rightSP);
			}
			leftSpeed = leftEncoder->GetRate();
			rightSpeed = rightEncoder->GetRate();
			if(count++ % 50)
			{
			printf("rate L: %2.2f R: %2.2f SP %2.4f %2.4f ERR %2.2f %2.2f\n", 
					leftSpeed, rightSpeed, leftSP, rightSP,
					PIDDriveLeft->GetError(), PIDDriveRight->GetError());
			//printf("Throttle value: %f", stickR.GetThrottle());
			if(PIDDriveRight->OnTarget()) printf("Right on");
			if(PIDDriveLeft->OnTarget()) printf("Left on");
			}
			//fakeSpeed = fakeEncoder->GetRate();
			//setSpeeds(leftSpeed, rightSpeed, maxSpeed);
			if(stickR.GetRawButton(4))
			{
				//PIDDriveRight->SetPID(stickR.GetThrottle()+1,DRIVEINTGAIN, DRIVEDERIVGAIN); 
				//PIDDriveLeft->SetPID(stickR.GetThrottle()+1,DRIVEINTGAIN, DRIVEDERIVGAIN);
				PIDDriveLeft->Reset();
				PIDDriveRight->Reset();
				PIDDriveLeft->Enable();
				PIDDriveRight->Enable();
			}

			sendIOPortData();
			
			if(stickR.GetRawButton(1)) lightOn = true;
			else lightOn = false;
			if(!lightOn) light->Set(light->kOff);
			if(lightOn) light->Set(light->kOn);
			
			if(stickL.GetRawButton(1))
			{
				if(PIDDriveLeft->IsEnabled() || PIDDriveRight->IsEnabled())
				{
					PIDDriveLeft->Disable();
					PIDDriveRight->Disable();
				}
				//PIDDriveLeft->SetSetpoint(0.5);
				//PIDDriveRight->SetSetpoint(0.5);
				
				if(count%50)
				{
					printf("Left encoder counts: %i %i", leftEncoder->Get(), leftEncoder->GetRaw());
				}
			}
			
			if(count%50) printf("Potentiometer: %f", ultrasonic->GetVoltage());
			/*if(MODESWITCH)
			{
				liftPower = (log(LIFTSLIDER + 0.003/.0208116511)/log(17.61093344)) + 0.116;
				if(count%50) printf("Slider: %f", liftPower);
			}
			while(i <= 16)
			{
				if(myEIO.GetDigital(i)&&count%50) printf("Button %i", i);
				i++;
			}
			if(i > 16) i = 1;*/
			Wait(0.05);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(SixWheelBot);

#endif
