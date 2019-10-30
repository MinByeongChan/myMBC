import requests, json
import RPi. GPIO as GPIO
import time

GPIO.setmode (GPI0.BCM)
GPIO.setup (6, GPIO.OUT)
GPI0.setup (26, GPIO.IN)

#Button data post to aws
url1= "http://13.124.166.248/maroon5/push notification.php"

#state val initialization
state = 0

try:
    while True:
        inputIO = GPIO.input(26)
        state = temp
        
        #Button ON
        if inputIO = True:
            GPIO.output (6, GPIO.HIGH)
            state = 1
            print "out"
            data1 = {"drive": state}
        #Button OFF
        else:
            GPIO.output (6, GPIO.LOW)
            state = 0
            print "in"
            data1 = {"drive" :state}
            
        if state !=state_temp :
            print "change "
            rl = requests.post(url=url1, data=datal)
    
        time.sleep(20)
        
except KeyboardInterrupt:
    print "Interrupt"
    #clean up registered GPIO pin 
    GPIO.Cleanup()
    