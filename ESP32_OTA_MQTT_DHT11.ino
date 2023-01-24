#include <Arduino.h>
#include "identification.h"
#include "arduino_secrets.h"
#include "mqtt_publisher.h"
// #include "DHT.h"

const char *SSID = SECRET_SSID;
const char *PASSWORD = SECRET_PASS;
const String topic_prefix = MQTT_TOPIC_PREFIX;
const String payload_type = MQTT_PAYLOAD_TYPE;
const String projectTitle = SENSOR_ID;
const String microcontroller = MICROCONTROLLER;
const char *mqtt_server = MQTT_SERVER;
const char *username = MQTT_USERNAME;
const char *password = MQTT_PASSWORD;

String topic = topic_prefix + projectTitle + "/" + payload_type;
String projectDesc =
  microcontroller + " room monitor: " + projectTitle + " publishing " + payload_type + " on topic: " + topic + "</p>";
int payload = 0;
const int readingdelay = 60000;  // 1 minute

// DHT
// #define DHTPIN 5       // Digital pin connected to the DHT sensor
// #define DHTTYPE DHT22  // DHT
// DHT dht(DHTPIN, DHTTYPE);
// float temperature = 0.0;
// float humidity = 0.0;

void setup() {
  Serial.begin(115200);
  Serial.println("Topic: " + topic);
  otaInit();
  mqttInit(mqtt_server);
}

void loop() {
  // float new_temperature = dht.readTemperature();
  // float new_humidity = dht.readHumidity();
  String json1;
  Serial.println("Topic: " + topic);
  // if (isnan(new_temperature)) {
  //   Serial.println("Failed to read from DHT sensor!");
  //   json1 = String("Fail");
  // } else {
  //   temperature = new_temperature;
  //   humidity = new_humidity;
  //   json1 = String("{\"payloads\":[")
  //           + "{\"Value\": \"" + temperature + "\",\"Units\": \"°C\",\"Description\": \"temperature\"},"
  //           + "{\"Value\": \"" + humidity + "\",\"Units\": \"%\",\"Description\": \"humidity\"}"
  //           + "]}";
  //   Serial.println(json1);
  //   publish(topic, (char *)json1.c_str(), username, password);
  // }
  publish(topic, "some stuff", username, password);
  delay(readingdelay);
}
