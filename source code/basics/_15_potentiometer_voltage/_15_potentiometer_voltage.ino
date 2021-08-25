const uint8_t GND = A0, DAT = A2, VIN = A4;
void setup() {
  // put your setup code here, to run once:                
  pinMode(GND, OUTPUT);
  pinMode(DAT, INPUT);
  pinMode(VIN, OUTPUT);
  digitalWrite(VIN, HIGH);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:                      
  float volt = (analogRead(DAT) / 1024.0) * 5;
  Serial.print(volt);
  Serial.println(" volts");
  delay(250);
}