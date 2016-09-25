#ifndef GRAB_H
#define GRAP_H
#include "api.h"

inline void grab_item() {
  api_positionBottomPlateOnGround();
  bool hitInsideFirst = api_tryGripping();
  if (!hitInsideFirst) {
    api_retractClaws();
    api_dropTopFlap();
  } else {
    api_finishGripping();
  }
  api_insertBottomPlate();
  api_liftArm();
}
#endif
