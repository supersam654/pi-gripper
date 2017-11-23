#include "api.h"
#include "hardware.h"

const int EXTRA_GRIP_DEGREES = 10;

void api_positionBottomPlateOnGround() {
  // Plate will manually be positioned flush to the ground.
  return;
//  while (!plate_isTouching()) {
//    arm_signal(ARM_DOWN);
//    delay(50);
//  }    
}

//boolean tryGripRight() {
//  int claw = RIGHT_CLAW;
//  // Keep trying to grip unless the claw is very rotated in which case give up.
//  while (!claws_isGripping(claw) && claws_getPosition(claw) < MAX_SERVO_ROTATION) {
//    claws_setPosition(claw, claws_getPosition(claw) + 1);
//    delay(15);
//  }
//
//  if (claws_getPosition(claw) >= MAX_SERVO_ROTATION) {
//    // We never hit anything.
//    return false;
//  }
//
//  if (claws_isTipTouching(claw) && !claws_isInsideTouching(claw)) {
//    return false;
//  }
//  return true;
//}

boolean tryGripLeft() {
  int claw = LEFT_CLAW;
  Serial.println("Try gripping");
  // Keep trying to grip unless the claw is very rotated in which case give up.
  while (!claws_isTipTouching(LEFT_CLAW) && claws_getPosition(LEFT_CLAW) > MIN_SERVO_ROTATION) {
    claws_setPosition(claw, claws_getPosition(claw) - 1);
    delay(50);
  }
  Serial.println(claws_isTipTouching(LEFT_CLAW));
  Serial.println(claws_getPosition(claw));

  if (claws_getPosition(claw) <= MIN_SERVO_ROTATION) {
    // We never hit anything.
    return false;
  }

//  if (claws_isTipTouching(claw) && !claws_isInsideTouching(claw)) {
//    return true;
//  }
  return true;
}

boolean api_identifyBook() {
  // Note that this function will leave the claws in an inconsistent wait.
//  tryGripLeft();
//  return claws_getPosition(LEFT_CLAW) > BOOK_ROTATION_THRESHOLD;
  return false;
}

bool api_tryGripping() {
  // True if both claws grabbed the inside. False if either hit the tip.
  return tryGripLeft();
}

void api_finishGripping() {
//  tryGripLeft();
//  // In a tradgic time-related accident, the right claw never acquired sensors.
//  claws_setPosition(RIGHT_CLAW, 180 - claws_getPosition(LEFT_CLAW));
////  tryGripRight();
//  // For a little extra security, tighen both claws a bit.
//  claws_setPosition(LEFT_CLAW, claws_getPosition(LEFT_CLAW) - EXTRA_GRIP_DEGREES);
//  claws_setPosition(RIGHT_CLAW, claws_getPosition(RIGHT_CLAW) + EXTRA_GRIP_DEGREES);
  claws_setPosition(RIGHT_CLAW, 130);
  claws_setPosition(LEFT_CLAW, 50);
  delay(1000);
}

void api_retractClaws() {
  claws_setPosition(LEFT_CLAW, MAX_SERVO_ROTATION);
  claws_setPosition(RIGHT_CLAW, 0);
  delay(1000);
}

void api_dropTopFlap() {
//  while (!flap_isTouching()) {
//    flap_setAngle(flap_getAngle() + 1);
//    delay(15);
//  }
  return false;

  // Clamp the flap a bit more.
  flap_setAngle(flap_getAngle() + 10);
  delay(500);
}

void api_liftTopFlap() {
  flap_setAngle(0);
  delay(1000);
}

void api_insertBottomPlate() {
  // Latest code blocks until motor has fully extended.
  plate_insert();
//  delay(1000);
//  plate_stop();
}

void api_retractBottomPlate() {
  // Latest code blocks until motor has fully retracted.
  plate_retract();
//  delay(1000);
//  plate_stop();
}

void api_liftArm() {
  arm_signal(ARM_UP);
  delay(2000);
}

