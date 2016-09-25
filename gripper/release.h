#ifndef RELEASE_H
#define RELEASE_H
#include "api.h"

inline void release_item() {
  api_positionBottomPlateOnGround();
  api_retractBottomPlate();
  api_liftTopFlap();
  api_retractClaws();
  api_liftArm();
}
#endif
