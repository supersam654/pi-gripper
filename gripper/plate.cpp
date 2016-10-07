#include "hardware.h"
#include <Stepper.h>

static float initialPressure;
static Stepper stepper(STEPS_PER_REVOLUTION, PLATE_PIN_A, PLATE_PIN_B, PLATE_PIN_C, PLATE_PIN_D);
void plate_init() {
  stepper.setSpeed(60); // 60 RPMs.
}

void plate_insert() {
  stepper.step(STEPS_PER_REVOLUTION);
}

void plate_retract() {
  stepper.step(-STEPS_PER_REVOLUTION);
}

void plate_stop() {
  // Do nothing because there is no need to stop the stepper motor.
}

bool plate_isTouching() {
  float currentPressure = analogRead(PLATE_LOAD_SENSOR_PIN);
  return exceedsThreshold(initialPressure, currentPressure, LOAD_SENSOR_THRESHOLD);
}
