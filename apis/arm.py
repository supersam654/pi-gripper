from time import sleep

def lift():
    """Move the robotic arm up."""
    pass # HARDWARE

def _is_touching():
    """Check if the bottom plate is touching the ground."""
    # I have debated with myself at length if this function belongs in `arm.py` or `bottom_plate.py`.
    # This function's current location should serve as an indication of the current winner of the argument.
    return True # HARDWARE

def lower():
    """Lower the arm until the bottom plate is touching the ground."""
    while not _is_touching():
        # Lower the arm.
        pass # HARDWARE
        sleep(0.1)
