int a = 7; 
int b = 6; 
int c = 5; 
int d = 11; 
int e = 10; 
int f = 8; 
int g = 9; 
int h = 4; 

void display1() {  
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
} 

void display2() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}  

void display3() { 
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(g, HIGH);
} 

void display4() {  
  digitalWrite(f, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
} 

void display5() { 
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
} 

void display6() { 
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  
  digitalWrite(e, HIGH);  
} 

void display7() {   
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}  

void display8() { 
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  
  digitalWrite(e, HIGH);  
  digitalWrite(f, HIGH);  
} 

void clearDisplay() { 
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);  
  digitalWrite(e, LOW);  
  digitalWrite(f, LOW);  
} 

void display9() { 
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  
  digitalWrite(f, HIGH);  
} 

void display0() { 
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  
  digitalWrite(e, HIGH);  
  digitalWrite(f, HIGH);  
} 

void determineNumber(int sensorValue) {
  if (sensorValue <= 102) {
    clearDisplay();
    display0();
  } else if (sensorValue > 102 && sensorValue <= 204) {
    clearDisplay();
    display1();
  } else if (sensorValue > 204 && sensorValue <= 306) {
    clearDisplay();
    display2();
  } else if (sensorValue > 306 && sensorValue <= 408) {
    clearDisplay();
    display3();
  } else if (sensorValue > 408 && sensorValue <= 510) {
    clearDisplay();
    display4();
  } else if (sensorValue > 510 && sensorValue <= 612) {
    clearDisplay();
    display5();
  } else if (sensorValue > 612 && sensorValue <= 714) {
    clearDisplay();
    display6();
  } else if (sensorValue > 714 && sensorValue <= 816) {
    clearDisplay();
    display7();
  } else if (sensorValue > 816 && sensorValue <= 918) {
    clearDisplay();
    display8();
  } else if (sensorValue > 918) {
    clearDisplay();
    display9();
  }
}

void setup() {
  for(int i = 4; i < 12; i++) {
    pinMode(i, OUTPUT);
  }      
} 

void loop() {     
  int sensorValue = analogRead(A0);
  determineNumber(sensorValue);
  delay(1);
}
