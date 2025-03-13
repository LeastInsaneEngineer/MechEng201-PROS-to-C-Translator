// PROS to C Translator for UoA Mechanical / Mechatronical Engineering 201 Vex Project
// Created by: Khalif Akmaloni
// This translator is so you can emulate, compile and run functions for testing outside of MechEng201 lab sessions.
// This file serves to define the base functions.
#include "main.h"

// poorman's object
int motorCommand[] = { 0,0,0 };


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
	set_enc(encoder, 0);
}

void delay(int time)
{
	float timeStep = time / 1000.00;
	int ticks = 0;
	//printf("timeStep = %f", timeStep);

	// Right Motor
	if (motorCommand[1] > 500)
	{
		ticks = (900 * (1000.0 / 12.0) / 60.0 * (motorCommand[1] / 5000.0) * timeStep);
		set_enc(RightEncoder, get_enc(RightEncoder) + ticks);
	}
	if (motorCommand[1] <= 500)
	{
		printf("Commanded Voltage too low\n");
	}

	// Left Motor
	float gain = left_gain;
	if (motorCommand[0] > 500)
	{
		ticks = (900 * gain * (1000.0 / 12.0) / 60.0 * (motorCommand[0] / 5000.0) * timeStep);
		set_enc(LeftEncoder, get_enc(LeftEncoder) + ticks);
	}
	if (motorCommand[0] <= 500)
	{
		printf("Commanded Voltage too low\n");
	}


	// Arm Motor, not supported
	if (motorCommand[2] > 500)
	{
		// nothing
	}
	else
	{
		printf("Invalid Motor\n");
	}
	if (motorCommand[2] <= 500)
	{
		printf("Commanded Voltage too low\n");
	}
}

void motorPower(int name, int voltage)
{
	if (name == LeftMotor)
	{
		printf("_motorPower Left = %i\n", voltage);
		motorCommand[0] = voltage;
	}
	else if (name == RightMotor)
	{
		printf("_motorPower Right = %i\n", voltage);
		motorCommand[1] = voltage;
	}
	else if (name == ArmMotor)
	{
		// supported input, not calculated yet.
		motorCommand[2] = voltage;
	}
	else
	{
		printf("Invalid Motor\n");
	}
}