int const green = 5;
int const yellow = 7;
int const red = 9;

void turnOnA() {
  digitalWrite(green, HIGH);
}

void turnOnB() {
  digitalWrite(yellow, HIGH);
}

void turnOnC() {
  digitalWrite(red, HIGH);
}

void turnOffAll() {
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
}

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    turnOffAll();
    char input = Serial.read();
    switch(input) {
      case 'a': 
        turnOnA();
        break;
      case 'b':
        turnOnB();
        break;
      case 'c':
        turnOnC();
        break;
      default:
        turnOffAll();
        break;
      }
  }
}
