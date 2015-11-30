#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(125)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
    bMotorReflected[port6] =1;
  bMotorReflected[port8] =1;
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  AuonomousCodePlaceholderForTesting();
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{

  while(true)
  {
		motor[port1] = vexRT[Ch2Xmtr2];
  	motor[port2] = vexRT[Ch3Xmtr2];
  	motor[port3] = vexRT[Ch2Xmtr2];
  	motor[port4] = vexRT[Ch3Xmtr2];
  	motor[port5] = vexRT[Ch2]; // controller 2 control for ports 5 6 7 and 8
  	motor[port6] = vexRT[Ch2];
  	motor[port7] = vexRT[Ch3];
		motor[port8] = vexRT[Ch3];
    }
	UserControlCodePlaceholderForTesting();
}
