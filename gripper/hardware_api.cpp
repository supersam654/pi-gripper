#include "hardware_api.h"
#include "arm.h"
#include "claws.h"
#include "top_flap.h"
#include "bottom_flap.h"

void api_positionBottomPlateOnGround() {
  while (!bottom_plate_isTouching()) {
    arm_signal(ARM_DOWN);
    delay(50);
  }    
}

boolean _tryGrip(int claw) {
  while (!claws_isGripping(claw)) {
    claws.grip(claw);
  }

  if (claws.isTipTouching(claw) && !claws.isInsideTouching(claw)) {
    return false;
  }
  return true;
}

bool api_tryGripping() {
  // True if both claws grabbed the inside. False if either hit the tip.
  return _tryGrip(LEFT_CLAW) && _tryGrip(RIGHT_CLAW);
}

void api_finishGripping() {
  _tryGrip(LEFT_CLAW);
  _tryGrip(RIGHT_CLAW);
}

void api_retractClaws() {
  claws_retract(LEFT_CLAW);
  claws_retract(RIGHT_CLAW);
}

void api_dropTopFlap() {
  top_flap_rotateDown();
}

void api_liftTopFlap() {
  top_flap_rotateUp();
}

void api_insertBottomPlate() {
  bottom_plate_signal(BOTTOM_PLATE_INSERT);
  delay(1000);
  bottom_plate_signal(BOTTOM_PLATE_STOP);
}

void api_retractBottomPlate() {
  bottom_plate_signal(BOTTOM_PLATE_RETRACT);
  delay(1000);
  bottom_plate_signal(BOTTOM_PLATE_STOP);
}

void api_liftArm() {
  arm_signal(ARM_UP);
  delay(2000);
}

