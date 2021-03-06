#pragma config(Sensor, in3,    Pot,                 sensorPotentiometer)
#pragma config(Sensor, in4,    RightEncoder,        sensorQuadEncoder, int4)
#pragma config(Sensor, in5,    LeftEncoder,         sensorQuadEncoder, int3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void GO(int go)
{
	motor[port3] = -go;
	motor[port2] = go;
	motor[port7] = go;
	motor[port8] = -go;
}

void BACK(int back)
{
	motor[port3] = back;
	motor[port2] = -back;
	motor[port7] = -back;
	motor[port8] = back;
}

void TURNRIGHT(int turn)
{
  motor[port3] = -turn;
	motor[port2] = -turn;
	motor[port7] = -turn;
	motor[port8] = -turn;
}

void TURNLEFT(int turn)
{
	motor[port3] = turn;
	motor[port2] = turn;
	motor[port7] = turn;
	motor[port8] = turn;
}

void GRAB(int grab)
{
	motor[port1] = grab;
	motor[port5] = grab;
}

void LIFTUP(int liftup)
{
	motor[port4] = -liftup;
	motor[port6] = -liftup;
}

void LIFTDOWN(int liftdown)
{
	motor[port4] = liftdown;
	motor[port6] = liftdown;
}


task main()
{
  bMotorFlippedMode[port6] = 1;
  bMotorFlippedMode[port1] = 1;
  wait1Msec(2000);

  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

  while(SensorValue[RightEncoder] > -1500 )
  {
  	if(SensorValue[RightEncoder] > -1490 )
  	{
  		GO(122);
  	}
  	else
  	{
  		GO(0);
  	}
  }
  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

  while(SensorValue[RightEncoder] > -355 )
  {
  	if(SensorValue[RightEncoder] > -350 )
  	{
  		TURNLEFT(127);
  	}
  	else
  	{
  		GO(0);
  	}
  }
  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

  while(SensorValue[Pot] > 460  )
  {
  	if(SensorValue[Pot] > 450 )
  	{
  		LIFTUP(127);
  	}
  }

  LIFTUP(0);
	wait1Msec(1000);


  while(SensorValue[RightEncoder] > -135 )
  {
  	if(SensorValue[RightEncoder] > -130 )
  	{
  		GO(71);
  	}
  	else
  	{
  		GO(0);
  	}
  }
  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

  LIFTUP(0);
	wait1Msec(1000);

  GRAB(127);
	wait1Msec(1000);

	GRAB(0);
	wait1Msec(2000);

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	while(SensorValue[RightEncoder] < 410 )
	{
		if(SensorValue[RightEncoder] < 405 )
		{
			BACK(87);
		}
		else
		{
			GO(0);
		}
	}

	while (SensorValue[Pot] < 625 )
	{
		if(SensorValue[Pot] < 620 )
		{
			LIFTDOWN(105);
		}
	}

	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

  while(SensorValue[RightEncoder] < 285 )
	{
		if(SensorValue[RightEncoder] < 280 )
		{
		  TURNRIGHT(57);
		}
		else
		{
			GO(0);
		}
	}
	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	while (SensorValue[Pot] > 500 )
	{
		if(SensorValue[Pot] > 500 )
		{
			LIFTUP(103);
		}
	}

  {
	  LIFTDOWN(0);
	  wait1Msec(1000);
	}


	while(SensorValue[RightEncoder] > -435 )
	{
		if(SensorValue[RightEncoder] > -430 )
		{
			GO(58);
		}
		else
		{
			GO(0);
		}
	}
	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	LIFTDOWN(0);
	wait1Msec(1000);

	GRAB(127);
	wait1Msec(1000);

	GRAB(0);
	wait1Msec(2000);

	while(SensorValue[RightEncoder] < 385 )
	{
		if(SensorValue[RightEncoder] < 380 )
		{
			BACK(127);
		}
		else
		{
			GO(0);
		}
	}
	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	while(SensorValue[RightEncoder] < 405 )
	{
		if(SensorValue[RightEncoder] < 400 )
		{
			TURNRIGHT(127);
		}
		else
		{
			GO(0);
		}
	}
	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	while(SensorValue[RightEncoder] > -1095 )
	{
		if(SensorValue[RightEncoder] > -1090 )
		{
			GO(127);
		}
		else
		{
			GO(0);
		}
	}
	SensorValue[LeftEncoder] = 0;
	SensorValue[RightEncoder] = 0;

	while(SensorValue[RightEncoder] > -300 )
  {
  	if(SensorValue[RightEncoder] > -295 )
  	{
  		TURNLEFT(127);
  	}
  	else
  	{
  		GO(0);
  	}
  }
  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

  while(SensorValue[RightEncoder] > -335 )
  {
  	if(SensorValue[RightEncoder] > -330 )
  	{
  		GO(58);
  	}
  	else
  	{
  		GO(0);
  	}
  }
  SensorValue[LeftEncoder] = 0;
  SensorValue[RightEncoder] = 0;

	bVexAutonomousMode = false;

	while(true)
	{
		motor[port1] = vexRT[Ch5];
		motor[port2] = vexRT[Ch1] + vexRT[Ch2];
		motor[port3] = vexRT[Ch1] - vexRT[Ch2];
		motor[port4] = vexRT[Ch3];
		motor[port5] = vexRT[Ch5];
		motor[port6] = vexRT[Ch3];
		motor[port7] = vexRT[Ch1] + vexRT[Ch2];
		motor[port8] = vexRT[Ch1] - vexRT[Ch2];
	}
}
