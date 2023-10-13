import time
import paho.mqtt.client as mqtt
import ssl
import json
import _thread
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
led = 15
echo = 16
trig = 18
ldr = 7
pir_sensor = 22
buzzer = 11
delayt = .1 

GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)
GPIO.setup(buzzer,GPIO.OUT)
GPIO.setup(led,GPIO.OUT)
GPIO.setup(pir_sensor, GPIO.IN)

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))

def rc_time (ldr):
    count = 0
    GPIO.setup(ldr, GPIO.OUT)
    GPIO.output(ldr, False)
    time.sleep(delayt)
    GPIO.setup(ldr, GPIO.IN)
    while (GPIO.input(ldr) == 0):
        count += 1
        if count > 10000:
            return count
    return count

client = mqtt.Client()
client.on_connect = on_connect
client.tls_set(ca_certs='./rootCA.pem', certfile='./399b1a3e251bdcda1a6b957eeaf121fd7d96c1538373d1f7d6c505d0fb19f3f0-certificate.pem.crt', keyfile='./399b1a3e251bdcda1a6b957eeaf121fd7d96c1538373d1f7d6c505d0fb19f3f0-private.pem.key', tls_version=ssl.PROTOCOL_SSLv23)
client.tls_insecure_set(True)
client.connect("a1ek9vqv3jnbud-ats.iot.eu-west-1.amazonaws.com", 8883, 60) 


def sensors():
    while (1):
        GPIO.output(trig, True)
        time.sleep(0.00001)
        GPIO.output(trig, False)
        while GPIO.input(echo) == 0:
            pulse_start = time.time()
        while GPIO.input(echo) == 1:
            pulse_end = time.time()
        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150
        print(f'Distane: {distance:.2f} cm')
        
        if distance <= 20:
            GPIO.output(buzzer, GPIO.HIGH)
            time.sleep(1)
            GPIO.output(buzzer, GPIO.LOW)
        else:
            time.sleep(1)

        value = rc_time(ldr)
        if ( value <= 10000 ):
            print("Lights are ON")
            GPIO.output(led, False)
            value = 1
            time.sleep(1)
        else:
            print("Lights are OFF")
            GPIO.output(led, True)
            time.sleep(1)
            GPIO.output(led, False)
            value = 0


        current_state = GPIO.input(pir_sensor)
        print("PIR:",str(current_state))
        if current_state == 1:
            GPIO.output(led,True)
            GPIO.output(buzzer, GPIO.HIGH)
            time.sleep(2)
            GPIO.output(led,False)
            GPIO.output(buzzer, GPIO.LOW)
        time.sleep(1)

        if (True):
            print("Data Sent!")
            client.publish("device/data", payload=f"{distance:.2f},{current_state},{value}" , qos=0, retain=False)
        time.sleep(3)

_thread.start_new_thread(sensors,())
    
client.loop_forever()
