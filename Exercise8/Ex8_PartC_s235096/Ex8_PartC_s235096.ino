int redLED = 9;
int greenLED = 10;
int blueLED = 11;

// sets the color on the LED
void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(redLED, redVal);
  analogWrite(greenLED, greenVal);
  analogWrite(blueLED, blueVal);
}

// Finds the position on the color wheel from the sensor value
void determineColor(int sensorValue) {
  float colorWheelPosition;

  if (sensorValue <= 120) {
    colorWheelPosition = 270;
  } else if (sensorValue > 120 && sensorValue <= 290) {
    colorWheelPosition = map(sensorValue, 121, 290, 270, 240);
  } else if (sensorValue > 290 && sensorValue <= 460) {
    colorWheelPosition = map(sensorValue, 291, 460, 240, 180);
  } else if (sensorValue > 460 && sensorValue <= 630) {
    colorWheelPosition = map(sensorValue, 461, 630, 180, 120);
  } else if (sensorValue > 630 && sensorValue <= 700) {
    colorWheelPosition = map(sensorValue, 631, 700, 120, 60);
  } else if (sensorValue > 700 && sensorValue <= 870) {
    colorWheelPosition = map(sensorValue, 701, 870, 60, 30);
  } else if (sensorValue > 870 && sensorValue <= 1023) {
    colorWheelPosition = map(sensorValue, 871, 1023, 30, 0);
  }

  positionToColor(colorWheelPosition);
}

// Determines the red, green and blue values from the position on the color wheel
void positionToColor(float position) {
  float transitionColor = 1 - abs(fmod(position / 60.0, 2) - 1);

  float red, green, blue;
  
  if (position >= 0 && position < 60) {
    red = 1;
    green = transitionColor;
    blue = 0;
  } else if (position >= 60 && position < 120) {
    red = transitionColor;
    green = 1;
    blue = 0;
  } else if (position >= 120 && position < 180) {
    red = 0;
    green = 1;
    blue = transitionColor;
  } else if (position >= 180 && position < 240) {
    red = 0;
    green = transitionColor;
    blue = 1;
  } else if (position >= 240 && position < 300) {
    red = transitionColor;
    green = 0;
    blue = 1;
  } else {
    red = 1;
    green = 0;
    blue = transitionColor;
  }

  int r = red * 255;
  int g = green * 255;
  int b = blue * 255;
  
  setColor(r, g, b);
}

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  determineColor(sensorValue);
  delay(1);
}

