#include "grab.h"
#include "release.h"
#include "hardware.h"

void setup() {
  hardware_init();
}

void initSensors() {
  hardware_init();
}

//void grip() {
//  while (!claws_isInsideTouching(LEFT_CLAW)) {
//    Serial.println(analogRead(LEFT_CLAW_FLEX_SENSOR_PIN));
//    claws_setPosition(LEFT_CLAW, claws_getPosition(LEFT_CLAW) + 1);
//    delay(10);
//  }
//}
//
void test() {
  claws_setPosition(LEFT_CLAW, MIN_SERVO_ROTATION);
  Serial.println("Retracting.");
  delay(1000);
  claws_setPosition(LEFT_CLAW, MAX_SERVO_ROTATION);
  Serial.println("Extending.");
  delay(1000);
}

void loop() {
//  test();
//  return;
  pinMode(MANUAL_PIN, INPUT);
  while (true) {
    delay(1000);
    if (digitalRead(MANUAL_PIN)) {
      initSensors();
      grab_item();
      break;
    }
  }
  while (true) {
    delay(1000);
    if (digitalRead(MANUAL_PIN)) {
      release_item();
      break;
    }
  }
}
