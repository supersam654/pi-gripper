def rotate_up():
    """Rotate the plate so the tip is higher up."""
    # QUESTION: How do we know when the plate is high enough to be out of the way?
    pass # TODO: Implement

def rotate_down():
    """Rotate the plate so the tip is lower."""
    # QUESTION: How do we know when the front edge hits the ground?
    pass # TODO: Implement

def lower():
    """Lower the plate so the back of it is touching the ground."""
    # QUESTION: Is this part of the larger arm or a separate motor?
    while not is_back_touching():
        pass # TODO: Implement.

def retract():
    """Pull the plate horizontally away from the object."""
    # QUESTION: How do we know the plate is fully retracted (or retracted enough)?
    pass # TODO: Implement.

def insert():
    """Push the plate all the way forward."""
    # QUESTION: How do we know the plate is fully extended (or extended enough)?
    pass # TODO: Implement.

def is_back_touching():
    """True if the back side of the plate is touching the ground."""
    # NEED: Pressure sensor on the back side of the plate.
    return True # TODO: Implement.
