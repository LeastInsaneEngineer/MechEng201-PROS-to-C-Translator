# MechEng201-PROS-to-C-Translator
A Translator to compile, run, and test PROS code for MechEng201 at University of Auckland.
This translator is presently limited to driving openloop and closedloop controls.

This translator will be provided as a Visual Studio Community solution.

User Warnings:
As with the bot, if your function has no exit condition, the code will keep on running indefinitely.
Consequently the code may be labeled as a power virus as I have not built any safeguards against control systems with no exit condition.

User Instructions:
in main() there is an encoder array.
You must pass this array into every function you create as it is needed to simulate the motor controls.
