int led = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  // Converting from 0-1023 to 0-5 Volt
  float voltage = sensorValue * (5.0 / 1023.0);
  // Print the value with 3 decimals
  Serial.println(voltage, 3);
  // Write the voltage to the led, divide by 4 as analogWrite takes max 255
  analogWrite(led, sensorValue/4);

  delay(1);
}
