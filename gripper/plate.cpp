#include "hardware.h"

float initialPressure;
// https://www.firgelliauto.com/blogs/news/18090523-how-to-use-an-arduino-with-firgelli-automations-linear-actuators
void plate_init() {
  pinMode(PLATE_A, OUTPUT);
  pinMode(PLATE_B, OUTPUT);

  initialPressure = analogRead(PLATE_LOAD_SENSOR_PIN) * 1.10;
}

void plate_insert() {
  digitalWrite(PLATE_A, HIGH);
  digitalWrite(PLATE_B, LOW);
}

void plate_retract() {
  digitalWrite(PLATE_A, LOW);
  digitalWrite(PLATE_B, HIGH);
}

void plate_stop() {
  digitalWrite(PLATE_A, LOW);
  digitalWrite(PLATE_B, LOW);
}

bool plate_isTouching() {
  return initialPressure < analogRead(PLATE_LOAD_SENSOR_PIN);
}
