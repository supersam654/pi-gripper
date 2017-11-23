#ifndef GRAB_H
#define GRAP_H
#include "api.h"
#include "hardware.h"

inline void grab_item() {
  delay(500);
  claws_init_sensors();
  delay(500);
  api_positionBottomPlateOnGround();
  bool looksLikeABook = api_identifyBook();
  Serial.println("Checking book");
  if (looksLikeABook) {
    Serial.println("Looks like a book");
    api_retractClaws();
    api_dropTopFlap();
  } else {
    Serial.println("Not a book.");
    api_finishGripping();
  }
  Serial.println("inserting bottom plate.");
  api_insertBottomPlate();
  api_liftArm();
}
#endif
