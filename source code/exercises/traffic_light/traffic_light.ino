//Red, Green, Blue
const uint8_t PINS[] = { 5, 6, 9 };
void setup() {
  // put your setup code here, to run once:
  for (uint8_t i = 0; i < sizeof(PINS); i++)
    pinMode(PINS[i], OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:  
  analogWrite(PINS[0], 255);
  analogWrite(PINS[1], 0);
  analogWrite(PINS[2], 0);
  delay(10000);

  analogWrite(PINS[0], 0);
  analogWrite(PINS[1], 255);
  analogWrite(PINS[2], 0);
  delay(7000);

  analogWrite(PINS[0], 192);
  analogWrite(PINS[1], 64);
  analogWrite(PINS[2], 0);
  delay(3000);
}



