from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient
import sys


myMQTTClient = AWSIoTMQTTClient("thing1")  #Enter your things name


myMQTTClient.configureEndpoint("a1ek9vqv3jnbud-ats.iot.us-east-1.amazonaws.com", 8883)
myMQTTClient.configureCredentials("./AmazonRootCA1.pem","./private.pem.key", "./device-certificate.pem.crt")


myMQTTClient.connect()
print("Client Connected")


msg = "Sample data from the device"
topic = "general/inbound"
myMQTTClient.publish(topic, msg, 0)  
print("Message Sent")


myMQTTClient.disconnect()
print("Client Disconnected")