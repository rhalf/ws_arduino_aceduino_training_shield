#include <EEPROM.h>

const uint8_t NUMBERS[10] = { 0x3f, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };


void setup() {
  // put your setup code here, to run once:                            
  Serial.begin(9600);


  for (uint8_t index = 0; index < 10; index++)
    EEPROM.write(index, NUMBERS[index]);
  
  for (uint8_t index = 0; index < 10; index++)
    Serial.print(EEPROM.read(index), HEX);
    Serial.print(" ");
}

void loop() {
  // put your main code here, to run repeatedly: 
}
