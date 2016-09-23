# This file exposes a high-level API for the contraption to use.

import apis.claws as _claws
import apis.top_plate as _top_plate
import apis.bottom_plate as _bottom_plate
import apis.arm as _arm

def position_bottom_plate_on_ground():
    _bottom_plate.rotate_up()
    while not _bottom_plate.is_back_touching():
        _bottom_plate.lower()
    _bottom_plate.rotate_down()

def try_gripping():
    while not _claws.is_gripping(_claws.LEFT_CLAW):
        _claws.grip(_claws.LEFT_CLAW)
    if _claws.is_tip_touching(_claws.LEFT_CLAW) and not _claws.is_inside_touching(_claws.LEFT_CLAW):
        return False

    while not _claws.is_gripping(_claws.RIGHT_CLAW):
        _claws.grip(_claws.RIGHT__CLAW)
    if _claws.is_tip_touching(_claws.RIGHT_CLAW) and not _claws.is_inside_touching(_claws.RIGHT_CLAW):
        return False
    # Both insides of the claws are touching.
    return True

# TODO: This function might not be needed because of how `try_grip` is implemented.
def finish_gripping():
    while not _claws.is_gripping(_claws.LEFT_CLAW):
        _claws.grip(_claws.LEFT_CLAW)
    while not _claws.is_gripping(_claws.RIGHT_CLAW):
        _claws.grip(_claws.RIGHT_CLAW)

def retract_claws():
    _claws.retract(_claws.LEFT_CLAW)
    _claws.retract(_claws.RIGHT_CLAW)

def drop_top_plate():
    _top_plate.rotate_down()

def insert_bottom_plate():
    _bottom_plate.insert()

def retract_bottom_plate():
    _bottom_plate.retract()

def retract_top_plate():
    _top_plate.rotate_up()

def lift_arm():
    _arm.lift()
