# This file should get a signal from the arm to either pick up an item or drop it.

def should_pickup():
    return True # HARDWARE

def main():
    if should_pickup():
        grab.grab_item()
    else:
        release.release_item()
