#include <Servo.h>
#include "hardware.h"

static Servo flapServo;
static float initialPressure;

void flap_init() {
  flapServo.attach(FLAP_SERVO_PIN);
  initialPressure = analogRead(FLAP_LOAD_SENSOR_PIN);
}
boolean flap_isTouching() {
  float currentPressure = analogRead(FLAP_LOAD_SENSOR_PIN);
  return exceedsThreshold(initialPressure, currentPressure, LOAD_SENSOR_THRESHOLD);
}

int flap_getAngle() {
  return flapServo.read();
}

void flap_setAngle(int angle) {
  int currentAngle = flap_getAngle();
  flapServo.write(angle);
  return currentAngle - angle;
}
