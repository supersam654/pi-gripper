#include <Servo.h>
#include "hardware.h"

Servo servos[2];
int tipSensors[2];

void claws_init() {
  Servo leftClawServo;
  Servo rightClawServo;
  servos[0] = leftClawServo;
  servos[1] = rightClawServo;
  leftClawServo.attach(LEFT_CLAW_SERVO_PIN);
  rightClawServo.attach(RIGHT_CLAW_SERVO_PIN);

  tipSensors[0] = LEFT_CLAW_LOAD_SENSOR_PIN;
  tipSensors[1] = RIGHT_CLAW_LOAD_SENSOR_PIN;
}

Servo getServo(int claw) {
  return servos[claw];
}

int getTipSensor(int claw) {
  return tipSensors[claw];
}

bool claws_isTipTouching(int claw) {
  int tipSensor = getTipSensor(claw);
  // TODO: HARDWARE
}

bool claws_isInsideTouching(int claw) {
  // TODO: HARDWARE
}

bool claws_isGripping(int claw) {
  return claws_isTipTouching(claw) || claws_isInsideTouching(claw);
}

int claws_getPosition(int claw) {
  Servo servo = getServo(claw);
  return servo.read();
}

void claws_setPosition(int claw, int degrees) {
  Servo servo = getServo(claw);
  servo.write(degrees);
}
