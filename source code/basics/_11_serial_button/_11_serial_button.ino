void setup() {
  // put your setup code here, to run once:          
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:                
  if (digitalRead(2) == HIGH) {
    Serial.println("Button1 is pressed!");
  } else if (digitalRead(3) == HIGH) {
    Serial.println("Button2 is pressed!");
  }
}


