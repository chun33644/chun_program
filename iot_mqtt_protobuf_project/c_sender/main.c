

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sensor.pb-c.h"
#include "MQTTClient.h"



#define ADDRESS "tcp://localhost:1883"  //MQTT server (local default port)
#define CLIENTID "C_Sender"
#define TOPIC "sensor/data"
#define QOS 1
#define TIMEOUT 10000L





int main() {
    
    
    SensorData data = SENSOR_DATA__INIT; 
    data.temperature = 25.5;
    data.humidity = 65.3;

    /*------ Use protobuf to convert into byte data ------ */
    // calculate how much space after serialization and package
    size_t len = sensor_data__get_packed_size(&data);
    void *buf = malloc(len);
    sensor_data__pack(&data, buf);


    /*------ Create MQTT Client ane prepare send data -----*/
    MQTTClient client; // declare a client
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer; //init connection setting
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL); //
    MQTTClient_connect(client, &conn_opts);


    /*---------------------- MQTTsend ---------------------*/
    MQTTClient_message pubmsg = MQTTClient_message_initializer; //create a message
    pubmsg.payload = buf;
    pubmsg.payloadlen = len;
    pubmsg.qos = QOS; //set transmission level
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, TOPIC, &pubmsg, NULL);

    printf("MQTT message sent successfully!\n");


    /*------ Clean up resources and close connections -----*/
    MQTTClient_disconnect(client, TIMEOUT);
    MQTTClient_destroy(&client);
    free(buf);

    return 0;


}

