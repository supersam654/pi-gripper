from time import sleep

# Claws work on servos
# Move x degrees and check what degrees I'm at.
# Or move all the way out.

# Load sensors on tips.
# Flex sensor on the inside.

# QUESTION: Figure out how to handle two different claws.
LEFT_CLAW = 1
RIGHT_CLAW = 2

def is_tip_touching(claw):
    """True if the tip of the given claw is touching something."""
    # Check if load sensor on tip is active.
    return True # HARDWARE

def is_inside_touching(claw):
    """True if an inside digit is touching the object."""
    # Check if flex sensor is touching.
    return True # HARDWARE

def retract(claw):
    """Move the claw all the way back from the object."""
    # Move servo to maximum out position.
    pass # HARDWARE

def _get_position(claw):
    # Get the current position of the claw (as calculated by the appropriate servo motor).
    return 0 # HARDWARE

def _set_position(claw, position):
    # Set the position of the claw (as calculated by the appropriate servo motor).
    pass # HARDWARE

def grip(claw):
    """Move the claw closer to the object."""
    while !is_gripping(claw):
        _set_position(claw, _get_position(claw) + 0.1)
        sleep(0.1)

def is_gripping(claw):
    """True if the inside or the tip of the claw is touching something."""
    return is_tip_touching(claw) or is_inside_touching(claw)
