//PWM - Pulse Width Modulation
//UNO - pins 3, 5, 6, 9, 10, and 11
//MEGA - pins 2 - 13 and 44 - 46
const uint8_t PINS[] = { 5, 6, 9 };
void setup() {
  // put your setup code here, to run once:
  for (uint8_t i = 0; i < sizeof(PINS); i++)
    pinMode(PINS[i], OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:  
  for (uint8_t i = 0; i < sizeof(PINS); i++) {
    for (uint8_t v = 0; v < 255; v++) {
      analogWrite(PINS[i], v);
      delay(3);
    }
    for (uint8_t v = 0; v < 255; v++) {
      analogWrite(PINS[i], 255 - v);
      delay(3);
    }
    analogWrite(PINS[i], 0);
  }
}



