// PROS to C Translator for UoA Mechanical / Mechatronical Engineering 201 Vex Project
// Created by: Khalif Akmaloni
// This translator is so you can emulate, compile and run functions for testing outside of MechEng201 lab sessions.

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

int readSensor(int sensor, int enc[])
{
	if (sensor == 6) // left
	{
		return enc[1];
	}
	else if (sensor == 5) // right
	{
		return enc[0];
	}
	else if (sensor == 9) // arm, not yet modeled.
	{
		return enc[2];
	}
}

void resetEncoder(int encoder, int enc[])
{
	enc[encoder] = 0;
}


// motorPower is emulated here
void motorPower(int name, int voltage, int enc[])
{
	char names[][18] = { {"Right Motor"}, {"Left Motor"},{"Arm Motor"} };
	int ticks = (900 * (1000.0 / 12.0) / 60.0 * (voltage / 5000.0) * dT);

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
			enc[2] = enc[2] + ticks;
		}
		else if (name == LeftMotor)
		{
			printf("%s voltage = %i\n", names[name], voltage);
			ticks = (900 / 1.1 * (1000.0 / 12.0) / 60.0 * (voltage / 5000.0) * dT);
			enc[name] = enc[name] + ticks;
		}
		else if (name == RightMotor)
		{
			printf("%s voltage = %i\n", names[name], voltage);
			enc[name] = enc[name] + ticks;
		}
		else
		{
			printf("invalid Motor\n");
		}
	}
}
