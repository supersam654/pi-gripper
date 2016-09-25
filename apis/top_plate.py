
# Current sensor and flexible hing
# When there's a spike in current draw, stop
# Also have a pressure sensor as a fallback to make sure we hit it.

def rotate_up():
    """Rotate plate away from the object."""
    # Rotate servo to maximum position.
    pass # HARDWARE

def rotate_down():
    """Rotate the plate down until it's touching the object."""
    # Check for current spike or pressure sensor hits.
    while not is_touching():
        # Lower a bit.
        pass # TODO: HARDWARE
        sleep(0.1)

def is_touching():
    """True if the plate is touching the object."""
    # NEED: Pressure sensor on the top plate or current thing.
    return True # HARDWARE
