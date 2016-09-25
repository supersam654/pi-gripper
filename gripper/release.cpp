#include "hardware_api.h"

void release_item() {
  api_positionBottomPlateOnGround();
  api_retractBottomPlate();
  api_liftTopFlap();
  api_retractClaws();
  api_liftArm();
}

