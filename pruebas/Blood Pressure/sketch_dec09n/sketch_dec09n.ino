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

#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>

#include <Wire.h>
#include "SPI.h"

Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);

void setup()
{
  Serial.begin(115200);
  MySignals.begin();
  
  MySignals.initSensorUART();
  MySignals.enableSensorUART(BLOODPRESSURE);

  tft.init();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  

  tft.drawString("Blood pressure:", 0, 0, 2);
  
}

void loop()
{
  if (MySignals.getStatusBP())
  {
    delay(1000);

    if (MySignals.getBloodPressure() == 1)
    {
      
      tft.drawString("Diastolic:", 0, 15, 2);
      tft.drawNumber(MySignals.bloodPressureData.diastolic, 100, 15, 2);
      
      tft.drawString("Systolic:", 0, 30, 2);
      tft.drawNumber(MySignals.bloodPressureData.systolic, 100, 30, 2);

      tft.drawString("Pulse/min:", 0, 45, 2);
      tft.drawNumber(MySignals.bloodPressureData.pulse, 100, 45, 2);  

    }
  }
  delay(1000);
}
    
