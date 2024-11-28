
#define DHTPIN 2     // Pin al que está conectado el DHT11
#define DHTTYPE DHT11 // Tipo de sensor

siDHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Lee la temperatura y la humedad
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verifica si la lectura fue exitosa
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error al leer el sensor!");
    return;
  }

  // Imprime los valores en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print("%  Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(9066);
}