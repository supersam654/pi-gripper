#include <Servo.h>
#include "hardware.h"

static Servo flapServo;
static float initialPressure;

void flap_init() {
  flapServo.attach(FLAP_SERVO_PIN);
  initialPressure = analogRead(FLAP_LOAD_SENSOR_PIN);
  flap_setAngle(0);
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
  currentAngle = max(90, currentAngle);
  flapServo.write(angle);
  return;
}
