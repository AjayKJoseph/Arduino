#include <Wire.h>
//long x; 
void setup() 
{
  Serial.begin(115200);
  Wire.begin();
  setupMAX1202();
}

void loop() 
{
  setupMAX1202();
  
}

 long setupMAX1202()
 {
  // Initate a write at the sensor address 
    Wire.beginTransmission(0b1110000); // A 7-bit address of DEC 112
    Wire.write(0b1010001); //Write to the address DEC 81
    Wire.endTransmission();

    delay(70);
    
    Wire.requestFrom(112, 2);
    if (2 <= Wire.available())
    {
     long x = Wire.read();
      x = x << 8;
      x  |= Wire.read();
      Serial.println(x);
      return x;
    }

 }

