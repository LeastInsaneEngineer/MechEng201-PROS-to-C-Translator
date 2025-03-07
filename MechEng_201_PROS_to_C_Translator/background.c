// PROS to C Translator for UoA Mechanical / Mechatronical Engineering 201 Vex Project
// Created by: Khalif Akmaloni
// This translator is so you can emulate, compile and run functions for testing outside of MechEng201 lab sessions.
// This file serves to define the base functions.
#include "main.h"

// Provided base functions are saturate, readSensor, and resetEncoder

double saturate(double input, double lower, double upper)
{

	if (input > upper)
	{
		return upper; // limit by upper bound
	}
	else if (input < lower)
	{
		return lower; // limit by lower bound
	}
	else
	{
		return input; // else leave unadjusted
	}
}

int readSensor(int sensor)
{
	if (sensor == 6) // left
	{
		return get_enc(LeftEncoder);
	}
	else if (sensor == 5) // right
	{
		return get_enc(RightEncoder);
	}
	else if (sensor == 9) // arm, not yet modeled.
	{
		return get_enc(ArmEncoder);
	}
	else
	{
		// nothing
	}
}

void resetEncoder(int encoder)
{
	set_enc(encoder,0);
}

void delay(int time)
{
	//does nothing lmao
}


// motorPower is emulated here
void motorPower(int name, int voltage)
{
	// old model that needs encoder array as input argument
	char names[][18] = { {"Right Motor"}, {"Left Motor"},{"Arm Motor"} };
	int ticks = (900 * (1000.0 / 12.0) / 60.0 * (voltage / 5000.0) * dT);

	float gain = left_gain;

	// new model
	int temp = 0;

	if (abs(voltage) <= 500)
	{
		// nothing happens as it's below  the minimum Voltage
		printf("%s voltage = %i\n", names[name], 0);
	}
	else
	{
		// ArmMotor is currently unmodeled, but its input exists for compatability.
		if (name == ArmMotor)
		{
			//enc[2] = enc[2] + ticks;
		}
		else if (name == LeftMotor)
		{
			// old model, needs enc array as input argument
			printf("%s voltage = %i\n", names[name], voltage);
			ticks = (900 * gain * (1000.0 / 12.0) / 60.0 * (voltage / 5000.0) * dT);
			//enc[name] = enc[name] + ticks;
			//enc[0] = enc[0] + ticks;

			// new model
			temp = get_enc(LeftEncoder);
			set_enc(LeftEncoder, temp + ticks);
		}
		else if (name == RightMotor)
		{
			// old model, needs enc array as input argument
			printf("%s voltage = %i\n", names[name], voltage);
			//enc[name] = enc[name] + ticks;
			//enc[1] = enc[1] + ticks;

			// new model
			temp = get_enc(RightEncoder);
			set_enc(RightEncoder, temp + ticks);
		}
		else
		{
			printf("invalid Motor\n");
		}
	}
}
