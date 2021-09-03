const uint8_t GND = A0, DAT = A2, VIN = A4;
const uint8_t AN = 6, CA = 7;
void setup() {
  // put your setup code here, to run once:                
  pinMode(GND, OUTPUT);
  pinMode(DAT, INPUT);
  pinMode(VIN, OUTPUT);
  pinMode(AN, OUTPUT);
  pinMode(CA, OUTPUT);
  digitalWrite(VIN, HIGH);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly: 
  //pwm 8bit or 256 | adc 10bit or 1024
  uint16_t a = analogRead(DAT);                   
  uint8_t v = (uint8_t) map(a, 0, 1023 , 0, 255);
  analogWrite(AN, v);
}

