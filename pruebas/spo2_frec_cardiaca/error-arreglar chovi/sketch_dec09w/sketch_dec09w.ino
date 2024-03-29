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

Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);


int valuePulse;
int valueSPO2;
uint8_t pulsioximeter_state = 0;

void setup() 
{

  Serial.begin(19200);
  MySignals.begin();
  
  MySignals.initSensorUART();
  MySignals.enableSensorUART(PULSIOXIMETER);
  
  tft.init();   
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  
  tft.drawString("SPO2:", 0, 0, 2);
}

void loop() 
{

  pulsioximeter_state = MySignals.getPulsioximeter();
  if (pulsioximeter_state == 1)
  { 
    tft.drawNumber(MySignals.pulsioximeterData.BPM, 0, 30, 2);
    tft.drawNumber(MySignals.pulsioximeterData.O2, 0, 45, 2);
  }

  delay(1000);

}
    
