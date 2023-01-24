#include "mqtt_publisher.h"

void reconnect(const char *username, const char *password) {
  // Loop until we're reconnected
  while (!client.connected()) {
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    Serial.print(clientId + " attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(clientId.c_str(), username, password)) {
      Serial.println("connected with");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(500);
    }
  }
}

void publishMQTT(String topicString, char *payload) {
  unsigned int length = topicString.length() + 1;
  char topic[length];
  topicString.toCharArray(topic, length);
  client.publish(topic, payload);
}

void publish(String topic, char *payload, const char *username, const char *password) {
  if (!client.connected()) {
    reconnect(username, password);
  }
  client.loop();
  // Publish the temperature to the MQTT broker
  publishMQTT(topic, payload);
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
}

void mqttInit(const char *mqtt_server) {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
