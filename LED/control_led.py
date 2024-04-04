# control_led.py
#----------------------------------------------------------------------------
#!/usr/bin/env python3 
# -*- coding: utf-8 -*- 
#----------------------------------------------------------------------------
# Created By  : Shirasukazushi
# Created Date: 2024/04/05
# ---------------------------------------------------------------------------
# 関数
#   LED    : LEDを点滅させる
# ---------------------------------------------------------------------------
# Imports 
# ---------------------------------------------------------------------------
import RPi.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.OUT)
GPIO.setup(25, GPIO.OUT)

def control_led(sleep_time=0.01):
    """Lチカプログラム

    Parameters
    ----------
    sleep_time : float
        LED消灯の長さ
    """
    try:
        while True:
            if GPIO.input(24) == GPIO.HIGH:
                GPIO.output(25, GPIO.HIGH)
            else:
                GPIO.output(25, GPIO.LOW)
            sleep(sleep_time)

    except KeyboardInterrupt:
        pass
    
    GPIO.cleanup()

if __name__ == '__main__':
    control_led()