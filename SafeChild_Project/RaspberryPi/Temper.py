#-*- coding:utf-8 -*-

import requests, json
import RPi. GPIO as GPIO
import time
import Adafruit DHT

temper sensor-Adafruit DHT.DHT11
temper pin=16

url1 = "http://13.124.166.248/tem1.php"
url2 = "http://13.124.166.248/maroon5/push_temper.php"

data2 = {"signal":"1"}

while True:

    #Adafruit 라이브러리 적용해서 온습도 데이터 불러옴
    humi, temper-Adafruit DHT. read_retry(tempen sensor, temper_pin)
    
    #post할 온도, 습도 데이터
    data1 = {"temper": temper,
            "hum": humi,
            "ID","1111 "
    }

    r1 = requests.post(url=url1, data=data1)

    print "Temp={0:0.1f) C Humidity={1:0.1f)%".format (temper, humi)

    #29도 이상이면 경고메세지
    if temper >= 29:
        print "if tem high, data transmition"
        r2 = requests.post(url=url2, data=data2)

    #온도는 30초마다 측정
    #온도가 높다는 신호가 전송되면 php에서 FCM 전송메세지 생성
    time.sleep(30)
