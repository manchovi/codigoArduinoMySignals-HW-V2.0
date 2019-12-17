//Funciona a la perfección este código con el sensor de temperatura.
//Variable de Medición: Temperatura Corporal.
//float calTemperature = MySignals.getCalibratedTemperature (100, 10, -2.0, 5);

/*EXPLICACIÓN:
 * float getCalibratedTemperature(uint8_t samples, uint16_t delaySample, float offset, uint8_t format);
 * samples: number of samples
 * delaySample: delay between samples
 * offset: it will do (temperature = temperature - offset)
 * format: 5 returns temperature, 3 returns voltage and another value returns resistance.
   You can find more information going to getCalibratedTemperature funtion in the MySignals library.
 */

#include <MySignals.h>

#include "Wire.h"
#include "SPI.h" 


void setup() 
{
  Serial.begin(115200);   
  MySignals.begin();
}


void loop() 
{
  //Returns the corporal temperature after applying measuring filter
  //float getCalibratedTemperature(uint8_t samples, uint16_t delaySample, float offset, uint8_t format);
  //float temperature = MySignals.getCalibratedTemperature(100,10,-2,0.2);
  float temperature = MySignals.getCalibratedTemperature(100, 10, -2, 5);

  Serial.print("Temperature (ºC): ");       
  Serial.print(temperature, 2);  
  Serial.println(""); 

  delay(1000);  // wait for a second 
}
    
