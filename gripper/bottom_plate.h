#ifndef BOTTOM_PLATE_H
#define BOTTOM_PLATE_H
BOTTOM_PLATE_INSERT = 1;
BOTTOM_PLATE_STOP = 0;
BOTTOM_PLATE_RETRACT = 2;
void bottom_plate_signal(int signal) {
  // TODO: HARDWARE
  // Just feed the signal to the linear actuator to make it insert or remove the plate.
}
#endif BOTTOM_PLATE_H
