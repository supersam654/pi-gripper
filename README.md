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

The files in `/apis/` deal with low-level functions that talk directly to sensors and other hardware.

`/hardware_api.py` exposes higher-level functions that abstract away some little details of working with the hardware.

`grab.py` collects an object into the contraption.

`release.py` puts an object already in the contraption back down.
