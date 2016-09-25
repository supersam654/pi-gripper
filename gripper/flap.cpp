#include <Servo.h>
#include "hardware.h"

static Servo flapServo;
static float initialPressure;

void flap_init() {
  flapServo.attach(FLAP_SERVO_PIN);
  initialPressure = analogRead(FLAP_LOAD_SENSOR_PIN) * 1.05;
}
boolean flap_isTouching() {
  return analogRead(FLAP_LOAD_SENSOR_PIN) > initialPressure;
}

int flap_getAngle() {
  return flapServo.read();
}

void flap_setAngle(int angle) {
  int currentAngle = flap_getAngle();
  flapServo.write(angle);
  return currentAngle - angle;
}
