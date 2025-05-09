/*
This tab is the one you use to customize the behavior of the motors and the connections if you wish to modify them.

If you're using a J.I.M. board that I gave you you don't need to modify the "PINS" section.
*/


// SERVOS OPEN AND CLOSE POSITION
#define SERVO1_OPEN_POS 160
#define SERVO1_CLOSE_POS 20
#define SERVO2_OPEN_POS 20
#define SERVO2_CLOSE_POS 160

// PINS
#define BUTTON_PIN 4
#define RIGHT_EYE 2
#define LEFT_EYE 15
#define SERVO1_PIN 21
#define SERVO2_PIN 19

// SERVO PWM VALUES, modify them according to the specs of the servos you are using
#define PWM_LOW 500
#define PWM_HIGH 2500

// EYES STARTUP EFFECTS, this will be updated but basically uncomment the line for the feature you want to use, one at a time.
// Comment both to have the eyes on without any effect at startup.
#define EYES_STARTUP_BLINK
// #define EYES_FADE_IN

// EYES CLOSE EFFECT, uncomment the line if you want the eyes to fade in when the mask closes.
// #define EYES_CLOSE_FADE_IN