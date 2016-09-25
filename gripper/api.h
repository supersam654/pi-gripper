#ifndef API_H
#define API_H
#include <Arduino.h>

void api_positionBottomPlateOnGround();
bool api_tryGripping();
void api_finishGripping();
void api_retractClaws();
void api_dropTopFlap();
void api_liftTopFlap();
void api_insertBottomPlate();
void api_retractBottomPlate();
void api_liftArm();
#endif
