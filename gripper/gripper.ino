#include "grab.h"
#include "release.h"
#include "hardware.h"

void setup() {
  hardware_init();
}

void test() {
  
}

void loop() {
  test();
  // grab_item();
  // release_item();
  // put your main code here, to run repeatedly:
  while (true) {
    delay(1000);
  }
}
