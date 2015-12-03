#pragma config(Sensor, in1,    Shedinja,            sensorPotentiometer)
#pragma config(Sensor, in3,    Miltank,             sensorQuadEncoder, int3)
#pragma config(Sensor, in4,    Golem,               sensorQuadEncoder, int4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() // starts program
{
  bMotorReflected[port6] =1;
  bMotorReflected[port8] =1;

SensorValue[Golem] = 0;
SensorValue[Miltank] = 0;


int Dump = 400;      // dump using dump :D :D :D
int Charzard = -1470; // drive back for charzard clicks
int Blastoise = 465; // drive forward for blastoise clicks
int Venusaur = 0;  // drive back for venusaur clicks
int FFX = 0;      // drive forward for FFX clicks
int FFXIII = 0;    // drive forward for FFXIII clicks
int Yblehs = 0;    // drive back for yblehs clicks
int DDT = 0;         // drive forward for DDT clicks
int turn = 0;        // turn for turn clicks
int Nate = 0;        // drive forward for nate clicks
int Metagross = 0;   // drive back for metagross clicks
int Ludicolo = 0;    // drive forward for ludicolo clicks
int Charmander = 0;  // drive forward for charmander clicks
int Ike = 0;         // drive back for ike clicks
int Marth = 0;       // drive forward for marth clicks
int FofX = 0;        // drive forward for FofX clicks
int GofX = 0;        // drive back for GofX clicks

SensorValue[Golem] = 0;
SensorValue[Miltank] = 0;

while(SensorValue[Golem] > Charzard)
{
  motor[port1] = 75;
  motor[port2] = -75;
  motor[port3] = 75;
  motor[port4] = -75;
}

{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}

{
  motor[port7] = -127;
  motor[port8] = -127;
  wait1Msec(500);
}



while(SensorValue[Shedinja] < 480)
{
  motor[port5] = 127;
  motor[port6] = 127;
}

{
  motor[port5] = 0;
  motor[port6] = 0;
}

while(SensorValue[Shedinja] > 5)
{
  motor[port5] = -127;
  motor[port6] = -127;
}

{
  motor[port5] = 0;
  motor[port6] = 0;
}

SensorValue[Golem] = 0;



while(SensorValue[Golem] < Blastoise)
{
  motor[port1] = -70;
  motor[port2] = 75;
  motor[port3] = -70;
  motor[port4] = 75;
}

while(SensorValue[Golem] < Venusaur)
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}

while(SensorValue[Golem] < FFX)
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}

while(SensorValue[Golem] < FFXIII)
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}

while(SensorValue[Golem] < Yblehs)
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}

while(SensorValue[Golem] < DDT)
{
  motor[port1] = 0;
  motor[port2] = 0;
  motor[port3] = 0;
  motor[port4] = 0;
}




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