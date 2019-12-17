#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 

void setup() {
  Serial.begin(115200);
  MySignals.begin();
}

void loop() {

  //Sensor para variable biométrica AirFlow o Flujo de Aire
  /*uint16_t air = (uint16_t)MySignals.getAirflow(DATA);   
  Serial.println("Flujo de Aire: ");
  Serial.println(air);
  delay(20);
  //delay(100);*/
  
  //Returns the corporal temperature after applying measuring filter
  //float getCalibratedTemperature(uint8_t samples, uint16_t delaySample, float offset, uint8_t format);
  //float temperature = MySignals.getCalibratedTemperature(100,10,-2,0.2);
  float temperature = MySignals.getCalibratedTemperature(100, 10, -2, 5);
  Serial.print("Temperature (ºC): ");       
  Serial.print(temperature, 2);  
  Serial.println("");
  delay(1000);
  
}
    
