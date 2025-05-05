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
    servo1.write(90);
    servo2.write(90);
    delay(80);
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
    // Effetto lampeggio occhi come in Iron Man
    for (int i = 0; i < 2; i++) {  // Esegui 5 lampeggi
      digitalWrite(RIGHT_EYE, HIGH);  // Accendi occhio destro
      digitalWrite(LEFT_EYE, HIGH);   // Accendi occhio sinistro
      delay(50);                     // Mantieni gli occhi accesi per 100ms
      digitalWrite(RIGHT_EYE, LOW);   // Spegni occhio destro
      digitalWrite(LEFT_EYE, LOW);    // Spegni occhio sinistro
      delay(50);                     // Mantieni gli occhi spenti per 100ms
    }
    delay(350);
  
    // Dopo il lampeggio, accendi gli occhi definitivamente
    digitalWrite(RIGHT_EYE, HIGH);
    digitalWrite(LEFT_EYE, HIGH);
  }
  
  void eyesFadeIn() {
    // Effetto fade in per gli occhi
    for (int i = 0; i <= 255; i++) {  // Incrementa il valore di luminosità da 0 a 255
      analogWrite(RIGHT_EYE, i);      // Imposta la luminosità dell'occhio destro
      analogWrite(LEFT_EYE, i);       // Imposta la luminosità dell'occhio sinistro
      delay(5);                     // Ritardo per un effetto di transizione più fluido
    }
    digitalWrite(RIGHT_EYE, HIGH);  // Assicurati che gli occhi siano accesi
    digitalWrite(LEFT_EYE, HIGH);   // Assicurati che gli occhi siano accesi
  }