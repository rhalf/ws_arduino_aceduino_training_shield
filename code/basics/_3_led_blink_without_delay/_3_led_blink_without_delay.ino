uint32_t c1 = 0, c2 = 0, c3 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - c1 == 500) {
    digitalWrite(11, !digitalRead(11));
    c1 = millis();
  }
  if (millis() - c2 == 300) {
    digitalWrite(13, !digitalRead(13));
    c2 = millis();
  }
  if (millis() - c3 == 100) {
    digitalWrite(15, !digitalRead(15));
    c3 = millis();
  }
}
