#include "hardware.h"
#include <AFMotor.h>

static float initialPressure;
static AF_Stepper stepper(STEPS_PER_REVOLUTION, PLATE_MOTOR_PORT);
static bool isRetracted = true;
void plate_init() {
  stepper.setSpeed(60); // 60 RPMs.
  // Release torque in the event it needs to be manually positioned in the correct place.
  stepper.release();
}

void plate_insert() {
//  if (!isRetracted) {
//    return;
//  }
//  isRetracted = false;
  // 100 is a percent of a full revolution.
  // Double is for maximum torque.
  stepper.step(100, FORWARD, DOUBLE);
}

void plate_retract() {
//  if (isRetracted) {
//    return;
//  }
//  isRetracted = true;
  // 100 is a percent of a full revolution.
  // Double is for maximum torque.
  stepper.step(100, BACKWARD, DOUBLE);
}

void plate_stop() {
  // Do nothing because there is no need to stop the stepper motor.
}

bool plate_isTouching() {
  // Plate will be manually positioned to always be touching the ground.
  return true;
//  float currentPressure = analogRead(PLATE_LOAD_SENSOR_PIN);
//  return exceedsThreshold(initialPressure, currentPressure, LOAD_SENSOR_THRESHOLD);
}
