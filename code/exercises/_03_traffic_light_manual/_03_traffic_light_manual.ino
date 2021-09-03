int red = 5;
int green = 6;

int button1 = 2;

boolean isActivated = false; 

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(button1,INPUT);
}

void loop() {
  if (digitalRead(button1)==HIGH) {
    isActivated = true;
  }
  if (isActivated) {
    analogWrite(red,255);
    analogWrite(green,0);
    delay(2000);
    analogWrite(red,0);
    analogWrite(green,255);
    delay(2000);
    analogWrite(red,255);
    analogWrite(green,100);
    delay(1000);
  }
}


