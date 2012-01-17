#define ENCON 1
#include "WPILib.h"
#include "math.h"
#include "dashboarddataformat.h"
#include "1983PIDController.h"
#include "TankPIDOutput.cpp"
#include "1983Lift.cpp"
#include "1983Defines.h"

#if 0
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
	Jaguar *liftMotor1;
	Jaguar *liftMotor2;
	Jaguar *gripMotor1;
	Jaguar *gripMotor2;
	Servo *camGimble;
	
	Joystick stickL; //Port 1
	Joystick stickR; //Port 2
	//AxisCamera &camera;
	
	DigitalInput *lsLeft;
	DigitalInput *lsMiddle;
	DigitalInput *lsRight;
	DigitalInput *compSwitch; //compressor limit switch
	AnalogChannel *ultrasonic;
	/*DigitalInput *bcd1;
	DigitalInput *bcd2;
	DigitalInput *bcd3;*/
	
	Encoder *fakeEncoderA;
	Encoder *leftEncoder;
	Encoder *fakeEncoderB;
#if ENCON
	Encoder *liftEncoder;
#endif
	Encoder *rightEncoder;
	//Encoder *fakeEncoderC;
	//Encoder *liftEncoder;
	AnalogChannel *gripPot;
	
	Relay *light;
	Relay *brake;
	Relay *shifter;
	Relay *gripOpen;
	//Relay *gripOpen2;
	Relay *gripPop;
	//Relay *gripPop2;
	Relay *compressor;
	
	DriverStation *driverStation;
	C1983_Lift *lift;
	
	PIDController *PIDDriveLeft;
	PIDController *PIDDriveRight;
	PIDController *PIDLift;
	PIDController *PIDGrip;
	
	EncoderPIDSource *leftPIDSource;
	EncoderPIDSource *rightPIDSource;
	LiftPIDSource *liftPIDSource;
	GripPIDSource *gripPIDSource;
	
	TankPIDOutput *leftPIDOutput;
	TankPIDOutput *rightPIDOutput;
	LiftPIDOutput *liftPIDOutput;
	GripPIDOutput *gripPIDOutput;
	
	float maxSpeed;
	bool lineFollowDone; //autonomous thing
	int stopCount;
	int counts;
	bool autonomous;
	

public:
	SixWheelBot(void):
		//myRobot(1, 2, 3, 4),	// these must be initialized in the same order
		stickL(1), stickR(2) /*, camera()*/		// as they are declared above.
	{
		//myRobot.SetExpiration(0.1);
		frontLeftMotor = new Jaguar(FRONTLEFTMOTORPORT);
		rearLeftMotor = new Jaguar(REARLEFTMOTORPORT);
		frontRightMotor = new Jaguar(FRONTRIGHTMOTORPORT);
		rearRightMotor = new Jaguar(REARRIGHTMOTORPORT);
		liftMotor1 = new Jaguar(LIFTMOTORPORT1);
		liftMotor2 = new Jaguar(LIFTMOTORPORT2);
		gripMotor1 = new Jaguar(GRIPMOTORPORT1);
		gripMotor2 = new Jaguar(GRIPMOTORPORT2);
		
		fakeEncoderA = new Encoder(6,1,6,2,false, fakeEncoderA->k4X);
		leftEncoder = new Encoder(4, LEFTMOTORA, 4, LEFTMOTORB, true, leftEncoder->k4X);
		fakeEncoderB = new Encoder(6,3,6,4,false, fakeEncoderB->k1X);
#if ENCON
		brake = new Relay(4, BRAKEPORT, brake->kBothDirections);
		liftEncoder = new Encoder(4, LIFTMOTORA, 4, LIFTMOTORB, false, liftEncoder->k4X);
		liftPIDSource = new LiftPIDSource(lift);
		liftPIDOutput = new LiftPIDOutput(liftMotor1, liftMotor2);
		PIDLift = new PIDController(LIFTPROPGAIN, LIFTINTGAIN, LIFTDERIVGAIN,
						liftPIDSource, liftPIDOutput);
		lift = new C1983_Lift(liftEncoder, brake);
#endif
		rightEncoder = new Encoder(4, RIGHTMOTORA, 4, RIGHTMOTORB, false, rightEncoder->k4X);
		//fakeEncoderC = new Encoder(6,5,6,6,false, fakeEncoderC->k1X);
		//liftEncoder = new Encoder(4, LIFTMOTORA, 4, LIFTMOTORB, false, liftEncoder->k1X);
		gripPot = new AnalogChannel(1, GRIPPOTPORT);
		compSwitch = new DigitalInput(4, COMPRESSORSWITCH);
		
		light = new Relay(4, LIGHTPORT, light->kForwardOnly);
		//light = new Relay(6, 8);
		shifter = new Relay(4, SHIFTERPORT, shifter->kBothDirections);
		gripOpen = new Relay(4, GRIPOPENPORT1, gripOpen->kBothDirections);
		//gripOpen2 = new Relay(GRIPOPENPORT2, gripOpen2->kForwardOnly);
		gripPop = new Relay(4, GRIPPOPPORT1, gripPop->kBothDirections);
		//gripPop2 = new Relay(GRIPPOPPORT2, gripPop2->kForwardOnly);
		compressor = new Relay(4, COMPRESSORPORT, compressor->kBothDirections);
		
		
		driverStation = DriverStation::GetInstance();
		
		ultrasonic = new AnalogChannel(1, ULTRASOUNDPORT);
		camGimble = new Servo(CAMERAYSERVOPORT);
		maxSpeed = 250;
		
		leftPIDSource = new EncoderPIDSource(leftEncoder, &maxSpeed);
		rightPIDSource = new EncoderPIDSource(rightEncoder, &maxSpeed);
		gripPIDSource = new GripPIDSource(gripPot);
		
		leftPIDOutput = new TankPIDOutput(frontLeftMotor, rearLeftMotor, false);
		rightPIDOutput = new TankPIDOutput(frontRightMotor, rearRightMotor, true);
		gripPIDOutput = new GripPIDOutput(gripMotor1, gripMotor2);
		
		PIDDriveLeft = new PIDController(DRIVEPROPGAIN, DRIVEINTGAIN, DRIVEDERIVGAIN,
						leftPIDSource, leftPIDOutput);
		PIDDriveRight = new PIDController(DRIVEPROPGAIN, DRIVEINTGAIN, DRIVEDERIVGAIN,
				rightPIDSource, rightPIDOutput);
		PIDGrip = new PIDController(GRIPPROPGAIN, GRIPINTGAIN, GRIPDERIVGAIN,
				gripPIDSource, gripPIDOutput);

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
		return ultrasonic->GetVoltage()*(503.0/5.0) - 4.625;
	}
	
	/**
	 * Drive left & right motors for 2 seconds then stop
	 */

	void Autonomous(void)
	{
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
	}


		
	void OperatorControl(void)
	{
		autonomous = false;
		//myRobot.SetSafetyEnabled(false);
		//myRobot.SetInvertedMotor(kFrontLeftMotor, true);
		//	myRobot.SetInvertedMotor(3, true);
		//variables for great pid
		double rightSpeed,leftSpeed;
		float rightSP, leftSP, liftSP, gripSP, tempLeftSP, tempRightSP;
		bool lightOn = false;
		//AxisCamera &camera = AxisCamera::GetInstance();
		rightEncoder->Start();
		leftEncoder->Start();
		rightEncoder->Reset();
		leftEncoder->Reset();
		bool fastest = false; //transmission mode
		float reduction = 3; //gear reduction from 
		float maxSpeed = 500;
		float liftPower = 0;
		int count = 0;
		int popCount = 0;
		int popStage = 0;
		bool shiftHigh = false;
		leftEncoder->SetDistancePerPulse((6 * PI / 500)/reduction); //6-inch wheels, 500 raw counts per revolution,
		rightEncoder->SetDistancePerPulse((6 * PI / 500)/reduction); //about 3:1 gear ratio
		DriverStationEnhancedIO &myEIO = driverStation->GetEnhancedIO();
		
		if(fastest) {
			maxSpeed = 250;
		}
		else
		{
			maxSpeed = 250;
		}

		PIDDriveLeft->SetOutputRange(-1, 1);
		PIDDriveRight->SetOutputRange(-1, 1);
		//PIDDriveLeft->SetInputRange(-244,244);
		//PIDDriveRight->SetInputRange(-244,244);
		PIDDriveLeft->SetTolerance(0.075);
		PIDDriveRight->SetTolerance(0.075);
		PIDDriveLeft->SetContinuous(false);
		PIDDriveRight->SetContinuous(false);
		PIDDriveLeft->Enable();
		PIDDriveRight->Enable();
		
#if ENCON
		liftSP = 0;
		PIDLift->SetTolerance(0.05);
		PIDLift->SetContinuous(false);
		PIDLift->SetOutputRange(-1, 1);
#endif
		gripSP = 0;
		PIDGrip->SetOutputRange(-1, 1);
		PIDGrip->SetTolerance(0.03);

		while (IsOperatorControl())
		{
			count++;
			if(fabs(stickL.GetY()) <= 0.075 )
			{
				leftSP = 0;
			}
			else leftSP = -stickL.GetY() * stickL.GetY() * (stickL.GetY()/fabs(stickL.GetY())); //set points for pid control
			if(fabs(stickR.GetY()) <= 0.075)
			{
				rightSP = 0;
			}
			else rightSP = -stickR.GetY() * stickR.GetY() * (stickR.GetY()/fabs(stickR.GetY()));
			
			if (BACKWARDBUTTON)
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
			if(PIDRESETBUTTON)
			{
				//PIDDriveRight->SetPID(stickR.GetThrottle()+1,DRIVEINTGAIN, DRIVEDERIVGAIN); 
				//PIDDriveLeft->SetPID(stickR.GetThrottle()+1,DRIVEINTGAIN, DRIVEDERIVGAIN);
				PIDDriveLeft->Reset();
				PIDDriveRight->Reset();
				PIDDriveLeft->Enable();
				PIDDriveRight->Enable();
			}
			
			if(SHIFTBUTTON && !shiftHigh)
			{
				shifter->Set(shifter->kForward);
				shiftHigh = true;
			}
			else if(!SHIFTBUTTON && shiftHigh)
			{
				shifter->Set(shifter->kReverse);
				shiftHigh = false;
			}

			sendIOPortData();
			
			if(LIGHTBUTTON) lightOn = true;
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
#if ENCON	
			if(!MODESWITCH)
			{
				if(LIFTLOW1BUTTON) liftSP = LIFTLOW1;
				if(LIFTLOW2BUTTON) liftSP = LIFTLOW2;
				if(LIFTMID1BUTTON) liftSP = LIFTMID1;
				if(LIFTMID2BUTTON) liftSP = LIFTMID2;
				if(LIFTHIGH1BUTTON) liftSP = LIFTHIGH1;
				if(LIFTHIGH2BUTTON) liftSP = LIFTHIGH2;
				
				PIDLift->SetSetpoint(liftSP);
				if(PIDLift->OnTarget() && PIDLift->IsEnabled())
				{
					PIDLift->Reset();
					liftMotor1->Set(LIFTNEUTRALPOWER);
					liftMotor2->Set(LIFTNEUTRALPOWER);
					Wait(0.05);
					lift->brakeOn();
					Wait(0.05);
					liftMotor1->Set(0.0);
					liftMotor2->Set(0.0);
				}
				if(!PIDLift->OnTarget() && !PIDLift->IsEnabled())
				{
					liftMotor1->Set(1);
					liftMotor2->Set(1);
					Wait(0.05);
					lift->brakeOff();
					Wait(0.05);
					PIDLift->Enable();
				}
			}
			
			if(MODESWITCH)
			{
				if(PIDLift->IsEnabled()) PIDLift->Reset();				
				liftPower = .8*pow(2*((log(LIFTSLIDER + 0.003/.0208116511)/log(17.61093344)) + 0.116), 2);
				if(fabs(liftPower) > 1) liftPower /= fabs(liftPower);
				if(count%50) printf("Slider: %f", liftPower);
				if(fabs(liftPower) >= 0.075 && lift->getPosition() <= 1.0 && lift->getPosition() >= 0.0)
				{
					if(lift->isBraking())
					{
						liftMotor1->Set(1);
						liftMotor2->Set(1);
						Wait(0.05);
						lift->brakeOff();
					}
					liftMotor1->Set(liftPower);
					liftMotor2->Set(liftPower);
				}
				else if (!lift->isBraking())
				{
					liftMotor1->Set(LIFTNEUTRALPOWER);
					liftMotor2->Set(LIFTNEUTRALPOWER);
					Wait(0.05);
					lift->brakeOn();
					Wait(0.05);
					liftMotor1->Set(0.0);
					liftMotor2->Set(0.0);
				}
			}
			if(count%50)
			{
				printf("Lift pos: %f Lift error: %f \n", liftEncoder->GetDistance(), PIDLift->GetError());
			}
#endif
			if(GRIPPERPOSUP && !GRIPPERPOSDOWN) gripSP = 0;
			else if(GRIPPERPOSDOWN && !GRIPPERPOSUP) gripSP = 1;
			else if(GRIPPERPOSDOWN && GRIPPERPOSUP) gripSP = 0.5;
			/*
			PIDGrip->SetSetpoint(gripSP);
			
			if(!PIDGrip->OnTarget() && !PIDGrip->IsEnabled()) PIDGrip->Enable();
			if(PIDGrip->OnTarget() && PIDGrip->IsEnabled()) PIDGrip->Reset();
			*/
			if(count%50) printf("Gripper pos: %f", gripPot->GetVoltage());
			
			if(GRIPPEROPEN) gripOpen->Set(gripOpen->kForward);
			if(GRIPPERCLOSE) gripOpen->Set(gripOpen->kReverse);
			
			if(GRIPPERPOP && !popStage) popStage = 1; 
			if(popStage == 1)
			{
				popCount = count;
				popStage++;
			}
			if(popStage == 2)
			{
				gripOpen->Set(gripOpen->kForward);
				popStage++;
			}
			if(popStage == 3 && (count - popCount) > 5)
			{
				gripPop->Set(gripPop->kForward);
				popStage++;
			}
			if(popStage == 4 && (count - popCount) > 10)
			{
				gripPop->Set(gripPop->kReverse);
				popStage++;
			}
			if(popStage == 5 && (count - popCount) > 15)	popStage = 0;
			
			
			if(!compSwitch->Get()) compressor->Set(compressor->kReverse);
			else compressor->Set(compressor->kForward);
			/*
			if(stickR.GetRawButton(1)) compressor->Set(compressor->kReverse);
			else compressor->Set(compressor->kForward);
			*/
			Wait(0.05);				// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(SixWheelBot);

#endif
