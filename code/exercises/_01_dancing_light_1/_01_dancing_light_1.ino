uint8_t ledArray[8] = {
  11,12,13,14,15,16,17,18};
uint16_t delay_master = 100;

void setup()
{
  for (int i=0; i<8; i++)
  {
    pinMode(ledArray[i], OUTPUT);
  }
}
  
void ledArray_blink()
{
  int j;
  for (int i=0; i<=3; i++)
  {
    j = (7 - i);
    digitalWrite(ledArray[i], HIGH);
    digitalWrite(ledArray[j], HIGH);
    delay(delay_master);
  } 
  for (int i=4; i<=7; i++)
  {
    j = (7 - i);
    digitalWrite(ledArray[i], LOW);
    digitalWrite(ledArray[j], LOW);
    delay(delay_master);
  } 
}

void loop()
{
  ledArray_blink();
}




