#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 

void setup() 
{
  Serial.begin(115200);
  MySignals.begin(); 
  
  MySignals.initSensorUART();
  
  MySignals.enableSensorUART(GLUCOMETER);
  delay(1000);
  
  MySignals.enableSensorUART(BLOODPRESSURE);
  delay(1000);
  
  MySignals.enableSensorUART(PULSIOXIMETER);
  delay(1000);
  
  MySignals.enableSensorUART(SPIROMETER);
  delay(1000);
}

void loop() 
{

  
}
