const int button = 1;
const int led = 0;
bool light = false;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  light = digitalRead(button);

  if (light) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
