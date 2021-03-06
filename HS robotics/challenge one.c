#pragma config(Sensor, in1,    Shedinja,            sensorPotentiometer)
#pragma config(Sensor, in3,    Miltank,             sensorQuadEncoder, int3)
#pragma config(Sensor, in4,    Golem,               sensorQuadEncoder, int4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() // starts program
{
  bMotorReflected[port6] =1;
  bMotorReflected[port8] =1;

  int d = 1457;// to wall
  int s = -314;// to line up with fbs
  int turn = 347;// turn
  int k = 332;// drive to 1st fb
  int shelby = 270;// drive to 2nd fb
  int david = 270;// " 3rd fb
  int kevin = 270;// " 4th fb
  int matt = 270;// " 5th fb
  int daniel = 0;// " wall

    SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;


  while(SensorValue[Golem] < d)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] > s)
  {
    motor[port1] = 37;
    motor[port2] = -43;
    motor[port3] = 37;
    motor[port4] = -43;
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < turn)
  {
    motor[port1] = 43;
    motor[port2] = 53;
    motor[port3] = 43;
    motor[port4] = 53;
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < k)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
    wait1Msec(2000);
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < shelby)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
    wait1Msec(2000);
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < david)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
    wait1Msec(2000);
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < kevin)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
    wait1Msec(2000);
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < matt)
  {
    motor[port1] = -37;
    motor[port2] = 43;
    motor[port3] = -37;
    motor[port4] = 43;
  }

  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
    wait1Msec(2000);
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;

  while(SensorValue[Golem] < daniel)
  {
    motor[port1] = 0;
    motor[port2] = 0;
    motor[port3] = 0;
    motor[port4] = 0;
  }

  SensorValue[Miltank] = 0;
  SensorValue[Golem] = 0;



  bVexAutonomousMode = false;// robot will go into user control, allowing us to control robot with controller,
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
}
