#include <OneWire.h>
const uint8_t DS18S20 = A5;
OneWire ds(DS18S20);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(getTemp());
  Serial.println(" celcius");
}
float getTemp() {
  uint8_t data[12], addr[8];
  if (!ds.search(addr)) {
    Serial.println("Addr not exist!");
    ds.reset_search();
    return -1000;
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("Invalid CRC!");
    return -1000;
  }
  if (addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Unknown device.");
    return -1000;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44);
  ds.reset();
  ds.select(addr);
  ds.write(0xBE);

  for (uint8_t i = 0; i < 9; i++) 
    data[i] = ds.read();
  ds.reset_search();

  uint8_t msb = data[1], lsb = data[0];
  float v = ((msb << 8) | lsb);
  float temp = v / 16;
  return temp;
}
