#include <Servo.h>
#include "hardware.h"

static Servo servos[2];
static int tipSensors[2];
static float initialTipLoads[2];
static int flexSensors[2];
static int initialFlexLoads[2];

void claws_init() {
  Servo leftClawServo;
  Servo rightClawServo;
  servos[0] = leftClawServo;
  servos[1] = rightClawServo;
  leftClawServo.attach(LEFT_CLAW_SERVO_PIN);
  rightClawServo.attach(RIGHT_CLAW_SERVO_PIN);

  tipSensors[0] = LEFT_CLAW_LOAD_SENSOR_PIN;
  tipSensors[1] = RIGHT_CLAW_LOAD_SENSOR_PIN;

  initialTipLoads[0] = analogRead(tipSensors[0]);
  initialTipLoads[1] = analogRead(tipSensors[1]);

  flexSensors[0] = LEFT_CLAW_FLEX_SENSOR_PIN;
  flexSensors[1] = RIGHT_CLAW_FLEX_SENSOR_PIN;

  initialFlexLoads[0] = analogRead(flexSensors[0]);
  initialFlexLoads[1] = analogRead(flexSensors[1]);
}

bool claws_isTipTouching(int claw) {
  float currentReading = analogRead(tipSensors[claw]);
  return exceedsThreshold(initialFlexLoads[claw], currentReading, LOAD_SENSOR_THRESHOLD);
}

bool claws_isInsideTouching(int claw) {
  float currentReading = analogRead(flexSensors[claw]);
  return exceedsThreshold(initialFlexLoads[claw], currentReading, FLEX_SENSOR_THRESHOLD);
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
