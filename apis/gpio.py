# This file makes interesting objects that wrap hardware calls.
from time import sleep

try:
    import RPi.GPIO as GPIO
except RuntimeError:
    print("If you're not on a Pi, use one. Otherwise, run `sudo !!`

GPIO.setmode(GPIO.BOARD)

class Hardware(object):
    def __init__(self, channel):
        self.channel = channel

    def signal(self, signal, post_delay):

    def get(self):
        return GPIO.input(self.channel)
