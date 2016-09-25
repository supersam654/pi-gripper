#include <Servo.h>
#include "hardware.h"
Servo flapServo;
float _flap_initialPressure;

void flap_init() {
  flapServo.attach(FLAP_SERVO_PIN);
  _flap_initialPressure = analogRead(FLAP_LOAD_SENSOR_PIN) * 1.10;
}
boolean flap_isTouching() {
  return analogRead(FLAP_LOAD_SENSOR_PIN) > _flap_initialPressure;
}

int flap_getAngle() {
  return flapServo.read();
}

void flap_setAngle(int angle) {
  int currentAngle = flap_getAngle();
  flapServo.write(angle);
  return currentAngle - angle;
}
