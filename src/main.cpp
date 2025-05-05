/* 
Hi! The name's Jim, I'm what some define "an engineer in training", I love to mess ardund with electronics
especially when it comes to Iron Man stuff. My mentors are obviously the guys from CrashWorks3D, so
if you want a 100% working code for an arduino powered helmet head to their repository. 

This one is made for fun, and if you're using it it means you're brave or desperate. This code has been
designed to work on ESP32 DEV modules, soon to be replaced by one that will work on the SuperMini's compatible 
with the boards I designed, the J.I.M. boards.

If you want to customize a little bit the code, the config.h is the only one you have to modify.

All that being said, hope you enjoy this and that nothing blows up!



Oh wait, formalities: THIS CODE IS MADE FOR RECREATIONAL PURPOSES ONLY, I AM NOT RESPONSIBLE FOR ANY DAMAGE.
USE AT YOUR OWN RISK.

There you go, now im free of any liability.

Jim
*/
 

#include <Arduino.h>
#include <functions.h>

void setup() {
  maskSetup();
  button.attachClick(toggleMask);
  button.attachDoubleClick(toggleEyes);
}

void loop() {
  button.tick();
}