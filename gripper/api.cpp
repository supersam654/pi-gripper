#include "api.h"
#include "hardware.h"

void api_positionBottomPlateOnGround() {
  while (!plate_isTouching()) {
    arm_signal(ARM_DOWN);
    delay(50);
  }    
}

boolean tryGrip(int claw) {
  while (!claws_isGripping(claw)) {
    claws_setPosition(claw, claws_getPosition(claw) + 1);
    delay(15);
  }

  if (claws_isTipTouching(claw) && !claws_isInsideTouching(claw)) {
    return false;
  }
  return true;
}

bool api_tryGripping() {
  // True if both claws grabbed the inside. False if either hit the tip.
  return tryGrip(LEFT_CLAW) && _tryGrip(RIGHT_CLAW);
}

void api_finishGripping() {
  tryGrip(LEFT_CLAW);
  tryGrip(RIGHT_CLAW);
}

void api_retractClaws() {
  claws_setPosition(LEFT_CLAW, 0);
  claws_setPosition(RIGHT_CLAW, 0);
  delay(1000);
}

void api_dropTopFlap() {
  while (!flap_isTouching()) {
    flap_setAngle(flap_getAngle() + 1);
    delay(15);
  }
}

void api_liftTopFlap() {
  flap_setAngle(0);
  delay(1000);
}

void api_insertBottomPlate() {
  plate_insert();
  delay(1000);
  plate_stop();
}

void api_retractBottomPlate() {
  plate_retract();
  delay(1000);
  plate_stop();
}

void api_liftArm() {
  arm_signal(ARM_UP);
  delay(2000);
}

