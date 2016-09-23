# TODO: Figure out how to handle two different claws.
LEFT_CLAW = 1
RIGHT_CLAW = 2

def is_tip_touching(claw):
    """True if the tip of the given claw is touching something."""
    # NEED: Pressure sensor on tip of each claw.
    pass # TODO: Implement

def is_inside_touching(claw):
    """True if an inside digit is touching the object."""
    # NEED: At least one pressure sensor on the inside of each claw.
    pass # TODO: Implement

def retract(claw):
    """Move the claw all the way back from the object."""
    # NEED: Motor to rotate the claw outward.
    pass # TODO: Implement

def grip(claw):
    """Move the claw closer to the object."""
    # NEED: Motor to rotate the claw inward.
    pass # TODO: Implement

def is_gripping(claw):
    """True if the inside or the tip of the claw is touching something."""
    return is_tip_touching(claw) or is_inside_touching(claw)
