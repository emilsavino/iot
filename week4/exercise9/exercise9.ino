void setup() {
  Serial.begin(9600);
}

void loop() {
  int tempReading = analogRead(A1);
  double tempK = log(10000.0 * (1024.0 / tempReading - 1));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741*tempK*tempK))*tempK);
  float tempC = tempK - 273.15;
  Serial.println(tempC);
  delay(500);
}
