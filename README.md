# Raspberry Pi Gripper

Code for picking up a book, water bottle, or tomato.

## General Flow:

### Grabbing an item

1. Lower bottom plate so front and back of it are touching the ground.
1. Close claws around object.
1. If tips of either claw hits first:
  1. Retract both claws
  1. Bring top plate down
1. Else:
  1. Close the other claw (that didn't hit yet) until both are touching.
1. Slide bottom under
1. Lift up arm

### Releasing an item

1. Lower bottom plate so front and back are touching the ground.
1. Slide bottom plate out.
1. Lift top plate up (may already be up).
1. Retract side claws (may already be retracted).
1. Lift arm up (might be optional).

## Code Overview

All of the code is in `/gripper/`.

To adjust what devices have been plugged into various ports, modify the values in `pins.h`.

`gripper.ino` is the main point of entry. It is responsible for calling `grab_item()` from `grab.h` or `release_item()` from `release.h`.

`grab.h` and `release.h` have a basic control flow that works with a very high-level API established in `api.h` and implemented in `api.cpp`. This API creates useful, high-level functions from the underlying hardware.

All of functions for directly talking to the hardware are defined in `hardware.h` and implemented in `arm.cpp`, `claws.cpp`, `flap.cpp`, and `plate.cpp`.s
