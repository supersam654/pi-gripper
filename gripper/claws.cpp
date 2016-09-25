#include <Servo.h>
#include "hardware.h"

Servo servos[2];
int tipSensors[2];
float initialTipLoads[2];
int flexSensors[2];
int initialFlexLoads[2];

void claws_init() {
  Servo leftClawServo;
  Servo rightClawServo;
  servos[0] = leftClawServo;
  servos[1] = rightClawServo;
  leftClawServo.attach(LEFT_CLAW_SERVO_PIN);
  rightClawServo.attach(RIGHT_CLAW_SERVO_PIN);

  tipSensors[0] = LEFT_CLAW_LOAD_SENSOR_PIN;
  tipSensors[1] = RIGHT_CLAW_LOAD_SENSOR_PIN;

  initialTipLoads[0] = analogRead(tipSensors[0]) * 1.1;
  initialTipLoads[1] = analogRead(tipSensors[1]) * 1.1;

  flexSensors[0] = LEFT_CLAW_FLEX_SENSOR_PIN;
  flexSensors[1] = RIGHT_CLAW_FLEX_SENSOR_PIN;

  initialFlexLoads[0] = analogRead(flexSensors[0]) * 1.1;
  initialFlexLoads[1] = analogRead(flexSensors[1]) * 1.1;
}

bool claws_isTipTouching(int claw) {
  return analogRead(tipSensors[claw]) > initialTipLoads[claw];
}

bool claws_isInsideTouching(int claw) {
  return analogRead(flexSensors[claw]) > initialFlexLoads[claw];
}

bool claws_isGripping(int claw) {
  return claws_isTipTouching(claw) || claws_isInsideTouching(claw);
}

int claws_getPosition(int claw) {
  return servos[claw].read();
}

void claws_setPosition(int claw, int degrees) {
  servos[claw].write(degrees);
}
