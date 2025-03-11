# MechEng201-PROS-to-C-Translator V 1.4
Hello there MechEng 201 students
This Pros to C translator was made by me during my last 1-2 weeks of labs for the VEX project in 2024.
I was running out of lab sessions to test my code, so I made a simulator to test the logic of my code.
Further developement of that led to what you see now, a rudimentary translator.
What you see now is at a state that it can almost completely accept closedloop and openloop driving controls.

##    What can the Translator do presently?
It lets you run your PROS code without the need for the robot in the lab sessions, however it does not support arm control or lcd_print()

##    How does the translator simulate the robot?
When motorPower() is called, it stores the command to be executed later. It is then executed when the delay() function is called.
Using the delay, the simulator can then calculate the idealised rotation of the motor for the given voltage and the given time.

## User Instructions
1. Be sure to redefine the left_gain contant in main.h so that it matches the offset of your robot's motors.
2. Replace all lcd_print() functions with an equivalent in printf()
3. Comment out arm functions as they are presently not verified to work.
4. You can run your code as if it was in PROS.