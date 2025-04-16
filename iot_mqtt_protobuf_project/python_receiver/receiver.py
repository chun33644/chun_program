

import paho.mqtt.client as mqtt
from proto import sensor_pb2

def on_message(client, userdata, msg):
    data = sensor_pb2.SensorData()
    data.ParseFromString(msg.payload)
    print(f"Temperature: {data.temperature: .1f}°C, Humidity: {data.humidity: .1f}%")


client = mqtt.Client()
client.on_message = on_message
client.connect("localhost", 1883, 60)

client.subscribe("sensor/data")
print("Waiting for data.....")

client.loop_forever()

