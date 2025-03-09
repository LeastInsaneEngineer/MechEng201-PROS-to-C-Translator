# MechEng201-PROS-to-C-Translator
Hello there MechEng 201 students
This Pros to C translator was made by me during my last 1-2 weeks of labs for the VEX project in 2024.
I was running out of lab sessions to test my code, so I made a simulator to test the logic of my code.
Further developement of that led to what you see now, a near complete translator.
What you see now is at a state that it can almost completely accept closedloop controls without modifications.

##    What can the Translator do presently?
**It lets you your PROS code without the need for the robot in the lab sessions, however it does not presently have complete drop in support.
Drop in support is presently limited to closedloop encoder-controlled-driving without lcd_print() becasue lcd_print() is presently unsupported.
Ultimately, closedloop driving is what this translator was developed for.

Openloop time-based-driving has no drop in support, you will need to convert the PROS code into a simulated equivalent in C.

##    How does the translator simulate the robot?
motorPower() simulates the amount of rotation the motor will experience at a given driving voltage for a fixed time step of dT = 0.05.
dT is a consant defined in "main.h", it is the time step that the V5 brains reacts at, so the translator iterates at the same pace as the V5 brain.
Each time motorPower is called it steps forward the called motor by 0.05s, as stated before it **needs to be called over and over againt to simulate**.
This is perfect for testing closedloop controls where the motorPower() will be called repeatedly with constantly updated values, but not for openloop.

An example will be provided below.
> void main()
> {
    motorPower(leftMotor, 3); // commanding 3V
    delay(100); // for 100ms
    motorPower(leftMotor, 0); // stop
}
The above PROS code is commanding 3V to the left motor for 100ms before stopping.
An equivalent in C is provided
dT = 0.05 // This constant is defined in "main.h", it is the V5 brain's processing frequency in seconds, so the simulation runs at the same rate.
0.05 seconds = 50 milliseconds

C equivalent.
void main()
{
    float i = 0;
    while ( i < 0.1)
    {
        motorPower(leftMotor,3);
        i += dT;
    }
}

further development is going into supporting openloop time based driving, arm controls and lcd_print()
