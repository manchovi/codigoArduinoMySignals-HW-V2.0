/*
{
// Returns airflow value in a specific format
//(VOLTAGE) - in Volts (0-5V)
//(DATA)    - in digital value (0-1023)
float getAirflow(uint8_t format);

// Returns airflow in DATA format
float getAirflow(void);

// Returns an analog value to represent the Electrocardiography (0-5V)
float getCalibratedAirflow(uint8_t samples, uint16_t delaySample, float offset, uint8_t format);

// Calculates airflow PPM
void airflowPPM(void);
}
 */

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

  float air = MySignals.getAirflow(VOLTAGE);   
  Serial.print("Airflow value :  ");
  Serial.print(air, 2);
  Serial.println(" V");
  
  delay(100); 
}
   
