from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import time
import json

def customCallback(client, userdata, message):
    print("Callback came...")
    print("Topic: " + message.topic)
    payload = message.payload.decode()
    print("Message: " + payload)
    
    save_to_json(payload)

def save_to_json(data):
    try:
        with open('received_data.txt', 'a') as txt_file:
            txt_file.write(data)
            txt_file.write('\n')
        print("Data saved to received_data.txt")
    except Exception as e:
        print("Error saving data to text file:", str(e))


myMQTTClient = AWSIoTMQTTClient("device")
myMQTTClient.configureEndpoint("a1ek9vqv3jnbud-ats.iot.eu-west-1.amazonaws.com", 8883)

myMQTTClient.configureCredentials("./rootCA.pem", "./399b1a3e251bdcda1a6b957eeaf121fd7d96c1538373d1f7d6c505d0fb19f3f0-private.pem.key", "./399b1a3e251bdcda1a6b957eeaf121fd7d96c1538373d1f7d6c505d0fb19f3f0-certificate.pem.crt")

myMQTTClient.connect()
print("Client Connected")

# Subscribe to the analytics_topic with QoS 1
myMQTTClient.subscribe("device/data", 1, customCallback)
print('Waiting for the callback. Press Enter to continue...')

# Wait for user input before unsubscribing
x = input()

# Unsubscribe from the analytics_topic
myMQTTClient.unsubscribe("device/data")
print("Client unsubscribed")

# Disconnect from AWS IoT Core
myMQTTClient.disconnect()
print("Client Disconnected")