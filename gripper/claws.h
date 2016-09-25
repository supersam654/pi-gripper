#include <Servo.h>

#ifndef CLAWS_H
#define CLAWS_H

const int LEFT_CLAW = 0;
const int RIGHT_CLAW = 1;

extern Servo leftClaw;
extern Servo rightClaw;

bool claws_isTipTouching(int claw);
bool claws_isInsideTouching(int claw);
bool claws_isGripping(int claw);
void claws_setPosition(int claw, int degrees);
void claws_getPosition(int claw);
#endif
