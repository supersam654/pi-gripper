#include "grab.h"
#include "release.h"
#include "hardware.h"

void setup() {
  hardware_init();
}

void grip() {
  while (!claws_isInsideTouching(LEFT_CLAW)) {
    Serial.println(analogRead(LEFT_CLAW_FLEX_SENSOR_PIN));
    claws_setPosition(LEFT_CLAW, claws_getPosition(LEFT_CLAW) + 1);
    delay(10);
  }
}

void test() {
  claws_setPosition(LEFT_CLAW, 15);
  Serial.println("Moving to beginning.");
  delay(500);
  Serial.println("Gripping.");
  grip();
  Serial.println("Gripped.");
}

void loop() {
//  hardware_init(); // Reset initial states.
  test();
  Serial.println("Test finished.");
  delay(5000);
//  grab_item();
//  release_item();
//  while (true) {
//    delay(1000);
//  }
}
