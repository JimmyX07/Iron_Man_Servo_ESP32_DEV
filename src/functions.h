#include <Arduino.h>
#include <ESP32Servo.h>
#include <OneButton.h>
#include <customization.h>

Servo servo1;
Servo servo2;

OneButton button(BUTTON_PIN, true);

bool isMaskUp;
bool areEyesOn;

void eyesActivate();
void eyesFadeIn();
void eyesSlowOnAndBlink();

void eyesOn() {
    analogWrite(RIGHT_EYE, 255);
    analogWrite(LEFT_EYE, 255);
}

void eyesOff() {
    analogWrite(RIGHT_EYE, 0);
    analogWrite(LEFT_EYE, 0);
}

void maskSetup() {
    delay(2000);
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo1.write(SERVO1_CLOSE_POS);
    servo2.write(SERVO2_CLOSE_POS);
    pinMode(RIGHT_EYE, OUTPUT);
    pinMode(LEFT_EYE, OUTPUT);
    delay(1000);
    #ifdef EYES_STARTUP_BLINK
        eyesActivate();
    #endif
    #ifdef EYES_FADE_IN
        eyesFadeIn();
    #endif
    #ifndef EYES_STARTUP_BLINK
        #ifndef EYES_FADE_IN
            eyesOn();
        #endif
    #endif
    areEyesOn = true;
    delay(1000);
    servo1.detach();
    servo2.detach();
}

void maskUp() {
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo2.write(SERVO2_OPEN_POS);
    servo1.write(SERVO1_OPEN_POS);
    eyesOff();
    delay(2000);
    areEyesOn = false;
    servo1.detach();
    servo2.detach();
}

void maskDown() {
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo2.write(SERVO2_CLOSE_POS);
    servo1.write(SERVO1_CLOSE_POS);
    delay(800);
    #ifdef EYES_CLOSE_FADE_IN
        eyesFadeIn();
    #endif
    #ifndef EYES_CLOSE_FADE_IN
        eyesOn();
    #endif
    delay(1200);
    areEyesOn = true;
    servo1.detach();
    servo2.detach();
}


void toggleMask() {
    if (isMaskUp) {
        maskDown();
    } else {
        maskUp();
    }
    isMaskUp = !isMaskUp;
}

void toggleEyes() {
    if (areEyesOn) {
        delay(200);
        eyesOff();
    } else {
        delay(200);
        eyesOn();
    }
    areEyesOn = !areEyesOn;
}

void eyesActivate() {
    for (int i = 0; i < 2; i++) {
      analogWrite(RIGHT_EYE, 80);
      analogWrite(LEFT_EYE, 80);
      delay(50);
      analogWrite(RIGHT_EYE, 0);
      analogWrite(LEFT_EYE, 0);
      delay(50);
    }
    delay(350);
  

    analogWrite(RIGHT_EYE, 255);
    analogWrite(LEFT_EYE, 255);
  }
  
  void eyesFadeIn() {
    for (int i = 0; i <= 255; i++) {
      analogWrite(RIGHT_EYE, i);
      analogWrite(LEFT_EYE, i);
      delay(5);
    }
    digitalWrite(RIGHT_EYE, HIGH);
    digitalWrite(LEFT_EYE, HIGH);
  }
