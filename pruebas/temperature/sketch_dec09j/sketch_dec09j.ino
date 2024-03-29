/*

    Copyright (C) 2016 Libelium Comunicaciones Distribuidas S.L.
   http://www.libelium.com

    By using it you accept the MySignals Terms and Conditions.
    You can find them at: http://libelium.com/legal

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Version:           0.1
    Design:            David Gascon
    Implementation:    Luis Martin / Victor Boria
*/

//Este ejemplo debe funcionar con el sensor de temperatura.
//float calTemperature = MySignals.getCalibratedTemperature (100, 10, -2.0, 5);

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
  float temperature = MySignals.getCalibratedTemperature(100,10,-2,0.2);
  //float temperature = MySignals.getCalibratedTemperature(100, 10, -2, 5);

  Serial.print("Temperature (ºC): ");       
  Serial.print(temperature, 2);  
  Serial.println(""); 

  delay(1000);  // wait for a second 
}
    
