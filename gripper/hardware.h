#ifndef HARDWARE_H
#define HARDWARE_H
#include "Arduino.h"
#include "pins.h"

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
