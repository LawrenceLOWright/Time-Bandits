[![Codacy Badge](https://app.codacy.com/project/badge/Grade/d9b747ed2a0e443d8db014ae67ad4681)](https://app.codacy.com/gh/LawrenceLOWright/Time-Bandits/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
[![Codacy Badge](https://app.codacy.com/project/badge/Coverage/d9b747ed2a0e443d8db014ae67ad4681)](https://app.codacy.com/gh/LawrenceLOWright/Time-Bandits/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_coverage)

# Hourglass
A text-based, time looping adventure built with C++. 

## Project Description
Hourglass is a text-based game set in the town of Hourglass, a small town under the effects of a mysterious time loop. The player has to use a series of riddles to uncover the mysteries of Hourglass and save it from it's grizzly fate. However, the loops get shorter and shorter and the game goes on, forcing the player to be strategic with their resources. 

Hourglass is coded entirely in C++ with no external libraries, save for basic libraries included in the Windows system.  

## Building (Windows)
You'll need Windows and Visual Studio Code to run Hourglass. 

Once you've cloned the repository, open your powershell. Cd into the folder containing Hourglass and run these commands, in this order:
1. mkdir build
2. cmake -B build
3. cmake --build build

## Running
Open CMakeLists.txt in Visual Studio Code. Select the startup item - the big green play button on the upper right hand corner of the screen - and Hourglass will play!

## Credits
This project was written, coded, and designed by Jack Blair, Carinn Gaspar, Celeste Holt, and Lawrence Wright for the class COSC345 (software development) at the University of Otago. Coverage code was provided by Vaughan Kitchen.
