void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  // Converting from 0-1023 to 0-5 Volt
  float voltage = sensorValue * (5.0 / 1023.0);
  // Print the value with 3 decimals
  Serial.println(voltage, 3);

  delay(1);
}
