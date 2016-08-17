# SumoProject

This is mostly an experiment working with Arduino over Raspberry Pi ~~(Hating it already)~~ (Growing warmer to it). 

## Features
  * Motor Handler Library, for use with a typical L298N Motor Controller. (See more details below)
  * Ultra Sonic Handler Library, for use with a HC-SR04 Ultrasonic Module. (See below for details)

## WIP
  * Component parts are roughly modeled and will be available mostly to gauge where holes should be located on a model and the general size of it. They will *not* be so complex that they will have correct pins or modeled electrical circuit for more complex modeling project. It's beyond the scope of this project, and to be fair, if you're wanting that, you'll probably skilled enough to create them on your own :) 
  **(But if someone did want them, feel free to make a ticket for them)**
  * Infrared LED handler class, it looks like the LEDs I own are for more advanced IR stuff, like actual channel control and movement. I'm not sure if I'll use them and try to do some beam detection seeing as sending out created packets and decrypting is really pointless and a waste of computation power...
  * Actual logic of the robot, this is on hold until the base is 3D printed and I'm able to do tests. 

## Motor Handler Library
The Motor Handler class can be used in your project if you want! Very basic to use, you'll need to copy both MotorHandler.h and MotorHandler.cpp to your project and simply include it in your code. To see what the MotorHandler can do, please read MotorHandler.h for a basic description of the functions and read MotorHandler.cpp for a more advanced description.

## Ultrasonic Handler Library
The Ultrasonic handler class is also available to be ripped out of this project. Essentially, follow the same description as Motor Handler. If you want to do more advanced stuff with the calculations of the distance, just use the getRawDistance() method and do whatever extra math you'll like after with that value.

Questions/issues with this project? Make a ticket and I'll respond ASAP!