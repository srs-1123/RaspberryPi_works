# main.py
#----------------------------------------------------------------------------
#!/usr/bin/env python3 
# -*- coding: utf-8 -*- 
#----------------------------------------------------------------------------
# Created By  : Shirasukazushi
# Created Date: 2024/04/10
# ---------------------------------------------------------------------------
# 関数
# readadc: ADコンバーターの値を読む
# ---------------------------------------------------------------------------
# Imports 
# ---------------------------------------------------------------------------
import RPi.GPIO as GPIO
from time import sleep

# MCP3208からSPI通信で12ビットのデジタル値を取得。0から7の8チャンネル使用可
def readadc(abcnum, clockpin, mosipin, misopin, cspin):
    if abcnum > 7 or abcnum < 0:
        return -1
    GPIO.output(cspin, GPIO.HIGH)
    GPIO.output(clockpin, GPIO.LOW)
    GPIO.output(cspin, GPIO.LOW)

    commandout = abcnum
    commandout |= 0x18 # スタートビット+シングルエンドビット
    commandout <<=3 # LSBから8ビット目を送信するようにする
    for i in range(5):
        # LSBから数えて8ビット目から4ビット目までを送信
        if commandout & 0x80:
            GPIO.output(mosipin, GPIO.HIGH)
        else:
            GPIO.output(mosipin, GPIO.LOW)
        commandout <<= 1
        GPIO.output(clockpin, GPIO.HIGH)
        GPIO.output(clockpin, GPIO.LOW)
    adcout = 0
    # 13ビット読む（ヌルビット+12ビットデータ)
    for i in range(13):
        GPIO.output(clockpin, GPIO.HIGH)
        GPIO.output(clockpin, GPIO.LOW)
        adcout <<= 1
        if i > 0 and GPIO.input(misopin)==GPIO.HIGH:
            adcout |= 0x1
    GPIO.output(cspin, GPIO.HIGH)
    return adcout

GPIO.setmode(GPIO.BCM)
# ピンの名前を変数として定義
SPICLK = 11
SPIMOSI = 10
SPIMISO = 9
SPICS = 8
# SPI通信用の入出力を定義
GPIO.setup(SPICLK, GPIO.OUT)
GPIO.setup(SPIMOSI, GPIO.OUT)
GPIO.setup(SPIMISO, GPIO.IN)
GPIO.setup(SPICS, GPIO.OUT)

LED = 25
GPIO.setup(LED, GPIO.OUT)

try:
    while True:
        inputVal0 = readadc(0, SPICLK, SPIMOSI, SPIMISO, SPICS)

        # 暗いときだけLEDを点滅
        if inputVal0 < 2000 and inputVal0 >= 200:
            GPIO.output(LED, GPIO.HIGH)
            sleep(0.5)
            GPIO.output(LED, GPIO.LOW)
            sleep(0.5)
        elif inputVal0 < 200:
            GPIO.output(LED, GPIO.HIGH)
            sleep(0.2)
            GPIO.output(LED, GPIO.LOW)
            sleep(0.2)
        else:
            GPIO.output(LED, GPIO.LOW)
            sleep(0.2)
        # print(inputVal0)

except KeyboardInterrupt:
    pass

GPIO.cleanup()