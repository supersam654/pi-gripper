#ifndef HARDWARE_H
#define HARDWARE_H
#include "Arduino.h"
#include "pins.h"

// Ideally, a servo goes from 0 to 180.
// However, I honestly don't trust our hardware to be that perfect.
const int MIN_SERVO_ROTATION = 20;
const int MAX_SERVO_ROTATION = 150;

// Fudge factor for various sensors:
const float LOAD_SENSOR_THRESHOLD = 0.1;
const float FLEX_SENSOR_THRESHOLD = 0.1;

// How many steps the stepper takes to do a full rotation.
const int STEPS_PER_REVOLUTION = 200;

inline bool exceedsThreshold(float initialReading, float currentReading, float threshold) {
  float difference = initialReading - currentReading;
  float percentDifference = abs(difference) / initialReading;
  return percentDifference > threshold;
}

const int ARM_UP = 1;
const int ARM_DOWN = 0;
void arm_init();
void arm_signal(int signal);

void flap_init();
bool flap_isTouching();
int flap_getAngle();
void flap_setAngle(int angle);

void plate_init();
void plate_insert();
void plate_retract();
void plate_stop();
bool plate_isTouching();

const int LEFT_CLAW = 0;
const int RIGHT_CLAW = 1;
void claws_init();
bool claws_isTipTouching(int claw);
bool claws_isInsideTouching(int claw);
bool claws_isGripping(int claw);
int claws_getPosition(int claw);
void claws_setPosition(int claw, int degrees);

inline void hardware_init() {
  Serial.begin(9600);
  arm_init();
  flap_init();
  plate_init();
  claws_init();
}
#endif
