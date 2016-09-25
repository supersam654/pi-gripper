#ifndef CLAWS_H
#define CLAWS_H
#include <Servo.h>

const int LEFT_CLAW = 0;
const int RIGHT_CLAW = 1;

inline Servo _claws_servos[2];
inline int _claws_tipSensors[2];

inline void claws_init() {
  Servo leftClawServo;
  Servo rightClawServo;
  _claws_servos[0] = leftClawServo;
  _claws_servos[1] = rightClawServo;
  leftClawServo.attach(LEFT_CLAW_SERVO_PIN);
  rightClawServo.attach(RIGHT_CLAW_SERVO_PIN);

  _claws_tipSensors[0] = LEFT_CLAW_LOAD_SENSOR_PIN;
  _claws_tipSensors[1] = RIGHT_CLAW_LOAD_SENSOR_PIN;
}

inline Servo getServo(int claw) {
  return _claws_servos[claw];
}

inline int getTipSensor(int claw) {
  return _claws_tipSensors[claw];
}

inline bool claws_isTipTouching(int claw) {
  int tipSensor = getTipSensor(claw);
  // TODO: HARDWARE
}

inline bool claws_isInsideTouching(int claw) {
  // TODO: HARDWARE
}

inline bool claws_isGripping(int claw) {
  return claws_isTipTouching(claw) || claws_isInsideTouching(claw);
}

inline int claws_getPosition(int claw) {
  Servo servo = getServo(claw);
  return servo.read();
}

inline void claws_setPosition(int claw, int degrees) {
  Servo servo = getServo(claw);
  servo.write(degrees);
}
#endif
