# MechEng201-PROS-to-C-Translator V 1.3
Hello there MechEng 201 students
This Pros to C translator was made by me during my last 1-2 weeks of labs for the VEX project in 2024.
I was running out of lab sessions to test my code, so I made a simulator to test the logic of my code.
Further developement of that led to what you see now, a rudimentary translator.
What you see now is at a state that it can almost completely accept closedloop controls without modifications.
This translator is best used for the PI controls section of the Vex project.

##    What can the Translator do presently?
It lets you run your PROS code without the need for the robot in the lab sessions, however it does not presently have complete drop in support.
Drop in support is presently limited to closedloop encoder-controlled-driving **without** lcd_print() becasue lcd_print() is presently unsupported.
Ultimately, closedloop driving is what this translator was developed for.

Openloop time-based-driving has no drop in support, you will need to convert the PROS code into a simulated equivalent in C.
Below I will explain how it simulates the bot so that you can create your own openloop equivalent calls in C to test your code.

##    How does the translator simulate the robot?
motorPower() simulates the amount of rotation the motor will experience at a given driving voltage for a fixed time step of dT = 0.05.
dT is a consant defined in "main.h", it is the time step that the V5 brains reacts at, so the translator iterates at the same pace as the V5 brain.
Each time motorPower() is called it steps forward the called motor by dT which is 0.05s, as stated before it **needs to be called over and over againt to simulate**.
This is perfect for testing closedloop controls where the motorPower() will be called repeatedly with constantly updated values, but not for openloop.

An example will be provided below.
```
void main()
{
    motorPower(leftMotor, 3); // commanding 3V
    delay(100); // for 100ms
    motorPower(leftMotor, 0); // stop
}
```
The above PROS code is commanding 3V to the left motor for 100ms before stopping.
An equivalent in C is provided
dT = 0.05 // This constant is defined in "main.h", it is the V5 brain's processing frequency in seconds, so the simulation runs at the same rate.
0.05 seconds = 50 milliseconds

C equivalent.
```
void main()
{
    float i = 0;
    while ( i < 0.1 )
    {
        motorPower(leftMotor,3);
        i += dT;
    }
    motorPower(leftMotor,0); // You do not need to specify 0V as in the translator, no call = stopped.
    // However, it is good practice for you to keep track of what's going on.
}
```
further development is going into supporting drop-in openloop time based driving, arm controls and lcd_print().
In the mean time, you will need to conver time based controls into C equivalent, replace lcd_print() with printf and skip arm controls.
