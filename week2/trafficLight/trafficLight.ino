int const green = 5;
int const yellow = 7;
int const red = 9;

void greenState() {
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(2000);
}

void yellowState(bool showRed) {
  if (!showRed) {
    digitalWrite(red, LOW);
  }
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(2000); 
}

void redState() {
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(2000);
}

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

}

void loop() {
  redState();
  yellowState(true);
  greenState();
  yellowState(false);
}
