// PROS to C Translator for UoA Mechanical / Mechatronical Engineering 201 Vex Project
// Created by: Khalif Akmaloni
// This translator is so you can emulate, compile and run functions for testing outside of MechEng201 lab sessions.
// This file serves as an object for the encoder data.
#include "main.h"

// Static array to hold encoder values.
static int enc[3] = {0,0,0}; // poorman's object

// getter function, allows main.c to get the value in the array.
int get_enc(int name)
{
	if (name == LeftEncoder)
	{
		return enc[0];
	}
	else if (name == RightEncoder)
	{
		return enc[1];
	}
	else if (name == ArmEncoder)
	{
		return enc[2];
	}
	else
	{
		// nothing
	}
}

// setter function, allows main.c to set values in the array.
void set_enc(int name, int tick)
{
	if (name == LeftEncoder)
	{
		enc[0] = tick;
	}
	else if (name == RightEncoder)
	{

		enc[1] = tick;
	}
	else if (name == ArmEncoder)
	{
		enc[2] = tick;
	}
	else
	{
		// nothing
	}
}