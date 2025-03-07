# MechEng201-PROS-to-C-Translator
A Translator to compile, run, and test PROS code for MechEng201 at University of Auckland.
This translator is presently limited to driving openloop and closedloop controls.
saturate(), readSensor(), resetEncoder(), and motorPower(), are the only given functions.

This translator will be provided as a Visual Studio Community solution.

User Warnings:
As with the bot, if your function has no exit condition, the code will keep on running indefinitely.
Consequently the code may be labeled as a power virus as I have not built any safeguards against control systems with no exit condition.
You can force-stop an non exiting code in Visual Studio Community or simply learn to write better code.

User Instructions:
This translator is designed for you to be able to drop in your code and run, but right now it has some limitations, limitations will be discussed in the limitations section.

1.  General User Instructions:
    As a student, you will be writing your code in "main.c". You can leave "main.h" and "background.c" alone.
    
    Above the main() function you can initialise your own functions.
    "main.c" holds the main() function where you will be running your robot commands.
    Below the main() you can define your own functions.

2.  Limitations:
   2.1. lcd_print() is as of yet unmodeled. You will simply have to comment it out, or replace it with a printf() equivalent.
   2.2. There is a given encoder[] array in main(). You need to pass this as an input into all of your functions as it is required for motorPower()
