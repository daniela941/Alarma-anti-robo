const int pinSensor = 35;
const int umbral = 500; 

void setup() {
  Serial.begin(9066);
  pinMode(pinSensor, INPUT);
}

void loop() {
  int valorSensor = analogRead(pinSensor);
  Serial.print("Valor del sensor: ");
  Serial.println(valorSensor);

  if (valorSensor > umbral) {
    Serial.println("Se detectó una vibración");
    
  }

  delay(100);
}