#ifndef HARDWARE_H
#define HARDWARE_H
#include "pins.h"
#include "arm.h"
#include "flap.h"
#include "plate.h"
#include "claws.h"

inline void hardware_init() {
  Serial.begin(9600);
  arm_init();
  flap_init();
  plate_init();
  claws_init();
}
#endif
