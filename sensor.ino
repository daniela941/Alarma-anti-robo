#include <ESP32WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Dani dani";
const char* password = "Camila042001";


const char* mqtt_server = "tu_broker_mqtt";
const int mqtt_port = 1883;
const char* mqtt_user = "tu_usuario";
const char* mqtt_password = "tu_contraseña";
const char* mqtt_topic = "sensor_infrarrojo";

const int pinSensor = 2;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(pinSensor, INPUT);


}

void loop() {
  client.loop();

  int valorSensor = digitalRead(pinSensor);

  if (valorSensor == HIGH) {
    String mensaje = "Movimiento detectado";
    client.publish(mqtt_topic, mensaje.c_str());
    Serial.println(mensaje);
  }

  delay(1000);
}