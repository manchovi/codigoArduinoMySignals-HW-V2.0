#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 

void setup() 
{
  MySignals.begin(); 
}

void loop() 
{
  MySignals.expanderWrite(B00000000);
  delay(1000);

  MySignals.expanderWrite(B11111111);
  delay(1000);
}
    
