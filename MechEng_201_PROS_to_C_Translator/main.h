// PROS to C Translator for UoA Mechanical / Mechatronical Engineering 201 Vex Project
// Created by: Khalif Akmaloni
// This translator is so you can emulate, compile and run functions for testing outside of MechEng201 lab sessions.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//time step of 50ms to match the Vex V5 brain
#define dT 0.05 // dT is in seconds. 0.05 = 50ms.

// Encoders
#define RightMotor 0
#define LeftMotor 1
#define ArmMotor 2
#define RightEncoder 5
#define LeftEncoder 6
#define ArmEncoder 9

// LCD
#define LCDLine1        0   //line 1 of LCD (SHOWS BATTERY LEVEL)
#define LCDLine2        1   //line 2 of LCD
#define LCDLine3        2   //line 3 of LCD
#define LCDLine4        3   //line 4 of LCD
#define LCDLine5        4   //line 5 of LCD
#define LCDLine6        5   //line 6 of LCD
#define LCDLine7        6   //line 7 of LCD
#define LCDLine8        7   //line 8 of LCD

// math
#define PI 3.14159265359 // Redundancy as PI from math.h sometimes does not work.

// Initiliase Base Functions
double saturate(double input, double lower, double upper);
int readSensor(int sensor, int enc[]);
void resetEncoder(int encoder, int enc[]);

// Initialise motor emulator
void motorPower(int name, int voltage, int enc[]);
