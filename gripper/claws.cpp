#include "claws.h"
#include "pins.h"

Servo leftClaw;
Servo rightClaw;

Servo claws[2] = {leftClaw, rightClaw};
int tipSensors[] = {LEFT_CLAW_LOAD_SENSOR_PIN, RIGHT_CLAW_LOAD_SENSOR_PIN};

Servo getServo(int claw) {
  return claws[claw];
}

int getTipSensor(int claw) {
  return tipSensors[claw];
}

bool claws_isTipTouching(int claw) {
  int tipSensor = getTipSensor(claw);
  // TODO: HARDWARE
}

void claws_setPosition(int claw, int degrees) {
  Servo servo = getServo(claw);
  // TODO: HARDWARE
}

