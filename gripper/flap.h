#ifndef FLAP_H
#define FLAP_H
#include <Servo.h>

inline Servo flapServo;
inline float _flap_initialPressure;

inline void flap_init() {
  flapServo.attach(FLAP_SERVO_PIN);
  _flap_initialPressure = analogRead(FLAP_LOAD_SENSOR_PIN) * 1.10;
}
inline boolean flap_isTouching() {
  return analogRead(FLAP_LOAD_SENSOR_PIN) > _flap_initialPressure;
}

inline int flap_getAngle() {
  return flapServo.read();
}

inline void flap_setAngle(int angle) {
  int currentAngle = flap_getAngle();
  flapServo.write(angle);
  return currentAngle - angle;
}
#endif
