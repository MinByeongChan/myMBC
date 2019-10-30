#-*- coding:uft-8 -*-

import serial
import pynmea2
import requests, json
import time

url1 = "http://13.124.166.248/GPS.php"

def parseGPS(str) :
    #GPS형식을 GGA 형식으로 가져옴
    if str.find('GGA') > 0:
        msg = pynmea2.parse(str)
        #GGA형식이기 때문에 lat, lon 데이터는 도분 형식으로 출력
        print ("Timestamp: %s -- Lat: %s %s -- Lon: %s %s"%(msg.timestamp, msg.lat, msg.lat_dir, msg.lon, msg.lon_dir))
        
        data1 = {"lat" : msg.lat,
                "lon" : msg.lon
        }
        
        #센서 특성상 위경도 값이 안잡히면 ""값을 출력함
        #위경도값이 측정이 안되면 POST하지 않는다
        if msg.lat != "" and msg != "" :
            r1 = requests.post(url=url1, data=data1)
            
#시리얼 포트에 연결된 데이터를 가져옴
#라즈베리파이 시리얼 설정을 한 후, 포트 설정을 ttyAMA0로 변경함
#timeout은 포트를 읽어오는 주기
serialPort = serial.Serial("/dev/ttyAMA0", 9600, timeout=0.5)

while True:
    #시리얼 포트에서 읽어온 string 형식의 데이터를 str에 저장
    str = serialPort.readline()
    
    parseGPS(str)