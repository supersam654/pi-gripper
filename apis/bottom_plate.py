from time import sleep

_EXTEND = 1
_RETRACT = 2
_STOP = 3

def _signal(signal):
    """Pass a signal to the linear actuator."""
    pass # HARDWARE

def retract():
    """Pull the plate horizontally away from the object."""
    # Signal the linear actuator to retract.
    # Wait a second until stopping the signal.
    _signal(_RETRACT)
    sleep(1)
    _signal(_STOP)

def insert():
    """Push the plate all the way forward."""
    # Signal the linear actuator to insert fully.
    _signal(_EXTEND)
    sleep(1)
    _signal(_STOP)
