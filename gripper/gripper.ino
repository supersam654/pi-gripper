#include "grab.cpp"
#include "release.cpp"
#include "pins.h"
#include "hardware.h"

void setup() {
  Serial.begin(9600);

  leftClawServo.attach(LEFT_CLAW_SERVO_PIN);
  rightClawServo.attach(RIGHT_CLAW_SERVO_PIN);
  topFlapperServo.attach(TOP_FLAPPER_SERVO_PIN);
  bottomPlateActuator.attach(BOTTOM_PLATE_ACTUATOR_PIN);
}

void loop() {
  // grab_item();
  // release_item();
  // put your main code here, to run repeatedly:
  while (true) {
    delay(1000);
  }
}
