import time


def customCallback(client,userdata,message):
    print("callback came...")
    print(message.payload)


from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient


myMQTTClient = AWSIoTMQTTClient("thing1")
myMQTTClient.configureEndpoint("a1ek9vqv3jnbud-ats.iot.us-east-1.amazonaws.com", 8883) 
myMQTTClient.configureCredentials("./AmazonRootCA1.pem","./private.pem.key", "./device-certificate.pem.crt")


myMQTTClient.connect()
print("Client Connected")


myMQTTClient.subscribe("general/outbound", 1, customCallback)
print('waiting for the callback. Click to conntinue...')
x = input()


myMQTTClient.unsubscribe("general/outbound")
print("Client unsubscribed")


myMQTTClient.disconnect()
print("Client Disconnected")
