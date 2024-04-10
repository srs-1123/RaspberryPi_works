# led.py
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
GPIO.setup(25, GPIO.OUT)

def LED(sleep_time=0.5):
    """Lチカプログラム

    Parameters
    ----------
    sleep_time : float
        LED消灯の長さ
    """
    try:
        while True:
            GPIO.output(25, GPIO.HIGH)
            sleep(sleep_time)
            GPIO.output(25, GPIO.LOW)
            sleep(sleep_time)

    except KeyboardInterrupt:
        pass
    
    GPIO.cleanup()

if __name__ == '__main__':
    LED(0.5)