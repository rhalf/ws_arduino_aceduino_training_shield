#include <OneWire.h>

unsigned char digit_1 = 7;
unsigned char digit_2 = 8;
unsigned char digit_3 = 10;
unsigned char red = 5;
unsigned char green = 6;
unsigned char blue = 9;
unsigned char buzzer = 4;

int DS18S20_Pin = A5; 

OneWire ds(DS18S20_Pin);  

void setup() 
{
  Serial.begin(9600);
  pinMode (DS18S20_Pin, INPUT);
  digitalWrite (DS18S20_Pin, HIGH);
  for (int x = 11; x < 19; x++)
  {
    pinMode (x, OUTPUT);
  }
  for (int x = 54; x < 59; x++)
  {
    pinMode (x, OUTPUT);
  }
  pinMode (digit_1, OUTPUT);
  pinMode (digit_2, OUTPUT);
  pinMode (digit_3, OUTPUT);  
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
}

void loop() 
{
  digitalWrite (red, LOW);
  digitalWrite (blue, LOW);
  digitalWrite (green, LOW);
  float temperature = getTemp();
  Serial.print(temperature); Serial.println (" deg Celcius");
  float fahr;
  fahr = (temperature * 9 / 5) + 32;
  Serial.print(fahr); Serial.println (" deg Fahrenheit");
  Serial.println();  
  if (temperature >= 29.6)
  {
    digitalWrite (green, LOW);
    digitalWrite (red, HIGH);
    digitalWrite (blue, LOW);
  }
  if (temperature <= 29.59 && temperature >= 25.6)
  {
    digitalWrite (green, HIGH);
    digitalWrite (red, HIGH);
    digitalWrite (blue, LOW);
  }
  if (temperature <= 25.59 && temperature >= 24.5)
  {
    digitalWrite (green, HIGH);
    digitalWrite (red, LOW);
    digitalWrite (blue, LOW);
  }
  if (temperature <= 24.49 && temperature >= 22.50)
  {
    digitalWrite (green, HIGH);
    digitalWrite (red, LOW);
    digitalWrite (blue, HIGH);
  }
  if (temperature <= 22.49)
  {
    digitalWrite (green, LOW);
    digitalWrite (red, LOW);
    digitalWrite (blue, HIGH);
  }
  int t = temperature / 10;
  int o = temperature;
  o = o % 10;
  int d = temperature * 10;
  d = d % 10;
  for (int x = 0; x < 90; x++)
  {
    
  digitalWrite (digit_3, HIGH);
  digitalWrite (digit_2, LOW);
  digitalWrite (digit_1, LOW);
  display_ (t);
  delay (10);
    
  digitalWrite (digit_3, LOW);
  digitalWrite (digit_2, HIGH);
  digitalWrite (digit_1, LOW);
  display_ (o);
  digitalWrite (18, HIGH);
  digitalWrite (58, HIGH);
  delay (10);
    
  digitalWrite (digit_3, LOW);
  digitalWrite (digit_2, LOW);
  digitalWrite (digit_1, HIGH);
  display_ (d);
  digitalWrite (18, LOW);
  delay (10);
  
  if (x % 2 == 1 && temperature >= 29.6)
    {
    tone (buzzer, 1500);
    }
  else
    {
    noTone (buzzer);
    }
  }
  
  t = fahr / 10;
  o = fahr;
  o = o % 10;
  d = fahr * 10;
  d = d % 10;
  
  for (int x = 0; x < 90; x++)
  {
    digitalWrite (digit_3, HIGH);
    digitalWrite (digit_2, LOW);
    digitalWrite (digit_1, LOW);
    display_ (t);
    delay (10);
    
    digitalWrite (digit_3, LOW);
    digitalWrite (digit_2, HIGH);
    digitalWrite (digit_1, LOW);
    display_ (o);
    digitalWrite (18, HIGH);
    digitalWrite (58, HIGH);
  
    delay (10);
    digitalWrite (digit_3, LOW);
    digitalWrite (digit_2, LOW);
    digitalWrite (digit_1, HIGH);
    display_ (d);
    digitalWrite (18, LOW);
    delay (10);
  
  if (x % 2 == 1 && temperature >= 29.6)
    {
    tone (buzzer, 1500);
    }
  else
    {
    noTone (buzzer);
    }
  }
}

float getTemp()
{
  byte data[12];
  byte addr[8];
  if (!ds.search(addr)) 
  {
      ds.reset_search();
      return -1000;
  }
  if (OneWire::crc8( addr, 7) != addr[7]) 
  {
      Serial.println("CRC is not valid!");
      return -1000;
  }
  if ( addr[0] != 0x10 && addr[0] != 0x28) 
  {
      Serial.print("Device is not recognized");
      return -1000;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); 

  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); 

  for (int i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }
  
  ds.reset_search();
  
  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); 
  float TemperatureSum = tempRead / 16;
  
  return TemperatureSum;
  
}

void display_ (unsigned char num)
{
  switch (num)
  {
    case 0:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, HIGH);
      digitalWrite (16, HIGH);
      digitalWrite (17, LOW);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, HIGH);
      digitalWrite (56, HIGH);
      digitalWrite (57, LOW);
      digitalWrite (58, LOW);
      break;
    }
    case 1:
    {
      digitalWrite (11, LOW);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, LOW);
      digitalWrite (15, LOW);
      digitalWrite (16, LOW);
      digitalWrite (17, LOW);
      digitalWrite (18, LOW);
      digitalWrite (54, LOW);
      digitalWrite (55, LOW);
      digitalWrite (56, LOW);
      digitalWrite (57, LOW);
      digitalWrite (58, LOW);
      break;
    }
    case 2:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, LOW);
      digitalWrite (14, HIGH);
      digitalWrite (15, HIGH);
      digitalWrite (16, LOW);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, HIGH);
      digitalWrite (56, LOW);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 3:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, LOW);
      digitalWrite (16, LOW);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, LOW);
      digitalWrite (56, LOW);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 4:
    {
      digitalWrite (11, LOW);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, LOW);
      digitalWrite (15, LOW);
      digitalWrite (16, HIGH);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, LOW);
      digitalWrite (55, LOW);
      digitalWrite (56, HIGH);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 5:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, LOW);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, LOW);
      digitalWrite (16, HIGH);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, LOW);
      digitalWrite (56, HIGH);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 6:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, LOW);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, HIGH);
      digitalWrite (16, HIGH);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, HIGH);
      digitalWrite (56, HIGH);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 7:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, LOW);
      digitalWrite (15, LOW);
      digitalWrite (16, LOW);
      digitalWrite (17, LOW);
      digitalWrite (18, LOW);
      digitalWrite (54, LOW);
      digitalWrite (55, LOW);
      digitalWrite (56, LOW);
      digitalWrite (57, LOW);
      digitalWrite (58, LOW);
      
      break;
    }
    case 8:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, HIGH);
      digitalWrite (16, HIGH);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, HIGH);
      digitalWrite (56, HIGH);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
    case 9:
    {
      digitalWrite (11, HIGH);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      digitalWrite (14, HIGH);
      digitalWrite (15, LOW);
      digitalWrite (16, HIGH);
      digitalWrite (17, HIGH);
      digitalWrite (18, LOW);
      digitalWrite (54, HIGH);
      digitalWrite (55, LOW);
      digitalWrite (56, HIGH);
      digitalWrite (57, HIGH);
      digitalWrite (58, LOW);
      break;
    }
  }
}



