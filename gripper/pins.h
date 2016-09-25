#ifndef PINS_H
#define PINS_H
// For now, digital pins are 0x0* and analog pins are 0x1*.

const int LEFT_CLAW_SERVO_PIN = 0x01;
const int LEFT_CLAW_FLEX_SENSOR_PIN = 0x10;
const int LEFT_CLAW_LOAD_SENSOR_PIN = 0x02;


const int RIGHT_CLAW_SERVO_PIN = 4;
const int RIGHT_CLAW_FLEX_SENSOR_PIN = 5;
const int RIGHT_CLAW_LOAD_SENSOR_PIN = 6;

const int FLAP_SERVO_PIN= 7;
const int FLAP_LOAD_SENSOR_PIN = 9;

const int PLATE_A = 10;
const int PLATE_B = 11;
const int PLATE_LOAD_SENSOR_PIN = 12;

const int ARM_Z_PIN = 13;
const int ARM_SIGNAL_PIN = 14;
#endif
