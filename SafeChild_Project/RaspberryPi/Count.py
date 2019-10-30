# coding:utf-8 -*-

import requests, json
import RPi. GPIO as GPIO
import time

GPIO.setmode (GPIO.BCM)
GPIO.setup(21, GPIO.IN)
GPIO.setup(20, GPIO.IN)

url "http://13.124.166.248/Count2.php"
cnt = 0

while True:

    cnt_temp = cnt
    input_state = GPIO.input (21)
    if GPIO.input(21) == False:
        print "Motion Detected 21
        time.sleep (0.3)
        if GPIO.input(20) == False:
            print "CHILD IN"
            cnt+=1
            print cnt
    elif GPIO.input (20) == False:
        print "Motion Detected 21
        time.sleep (0.3)
        if GPIO.input (21) ==False:
            print "CHILD OUT"
            cnt-=1
            if cnt <0:
                cnt =0 
            print cnt

    if cnt != cnt_temp :
        r1 = requests.post(url = url1, data = data1)
