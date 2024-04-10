# detect_edge.py
#----------------------------------------------------------------------------
#!/usr/bin/env python3 
# -*- coding: utf-8 -*- 
#----------------------------------------------------------------------------
# Created By  : Shirasukazushi
# Created Date: 2024/04/07
# ---------------------------------------------------------------------------
# クラス
#   DetectEdge    : GPIOピンのエッジ検出をする
# ---------------------------------------------------------------------------
# Imports 
# ---------------------------------------------------------------------------
import RPi.GPIO as GPIO
from time import sleep
import time
from typing import Callable

_ledState = GPIO.LOW

class DetectEdge:
    def __init__(self, channel, edge, callback: Callable, bouncetime=200):
        if edge == GPIO.RISING:
            self.trigger = GPIO.HIGH
        elif edge == GPIO.FALLING:
            self.trigger = GPIO.LOW
        else:
            raise ValueError("Invalid edge value. It should be GPIO.RISING or GPIO.FALLING.")

        self.channel = channel
        self.bouncetime = bouncetime * 0.001

        self.callback = callback

    def __call__(self):
        prev_time = time.time()

        try:
            while True:
                sleep(0.01)
                curr_time = time.time()
                if GPIO.input(self.channel) == self.trigger:
                    if curr_time - prev_time >= self.bounce_time:
                        self.callback(self.input)
                        prev_time = time.time()
                else:
                    pass

        except KeyboardInterrupt:
            pass

    def __del__(self):
        GPIO.cleanup()

if __name__ == '__main__':
    input_pin = 24
    output_pin = 25

    def my_callback(channel):
        if channel == input_pin:
            _ledState = not _ledState
            GPIO.output(output_pin, _ledState)

    GPIO.setmode(GPIO.BCM)
    GPIO.setup(input_pin, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
    GPIO.setup(output_pin, GPIO.OUT)
    DetectEdge(channel=input_pin, callback=my_callback, edge=GPIO.RISING)()