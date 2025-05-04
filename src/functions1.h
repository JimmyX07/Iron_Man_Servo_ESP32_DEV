#include <Arduino.h>
#include <ESP32Servo.h>
#include <OneButton.h>
#include <configuration.h>

Servo servo1;
Servo servo2;

OneButton button(BUTTON_PIN, true);

bool isMaskUp;
bool areEyesOn;

void eyesOn() {
    digitalWrite(RIGHT_EYE, HIGH);
    digitalWrite(LEFT_EYE, HIGH);
}

void eyesOff() {
    digitalWrite(RIGHT_EYE, LOW);
    digitalWrite(LEFT_EYE, LOW);
}

void maskSetup() {
    servo1.attach(SERVO1_PIN, PWM_LOW, PWM_HIGH);
    servo2.attach(SERVO2_PIN, PWM_LOW, PWM_HIGH);
    servo1.write(SERVO1_CLOSE_POS);
    servo2.write(SERVO2_CLOSE_POS);
    pinMode(RIGHT_EYE, OUTPUT);
    pinMode(LEFT_EYE, OUTPUT);
    eyesOn();
    areEyesOn = true;
    delay(3000);
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
    eyesOn();
    delay(2000);
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