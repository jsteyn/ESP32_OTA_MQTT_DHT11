#ifndef MQTT_PUBLISHER_H
#define MQTT_PUBLISHER_H
#include <PubSubClient.h>
#include <WiFi.h>


WiFiClient espClient;
PubSubClient client(espClient);
extern const char *mqtt_server;

void publish(String topic, char* payload, const char *username, const char *password);
void callback(char *topic, byte *message, unsigned int length);
void mqttInit(const char *mqtt_server);

#endif