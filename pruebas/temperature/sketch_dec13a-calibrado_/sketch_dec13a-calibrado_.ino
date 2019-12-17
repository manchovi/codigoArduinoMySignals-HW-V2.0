#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 
#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>


Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);

void setup()
{
  Serial.begin(115200);
  MySignals.begin();

  tft.init();   
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
 
  tft.drawString("Temperature:", 0, 0, 2);
}


void loop()
{
  //float temperature = MySignals.getCalibratedTemperature ( 1 , 10 , -2.0 ,5 );
  //float calTemperature = MySignals.getCalibratedTemperature ( 1 , 10 , 0 ,5 );
  float calTemperature = MySignals.getTemperature();
  Serial.print(F("Temperature (*C): "));       
  Serial.println(calTemperature, 2); 

  //float calTemperature = MySignals.getCalibratedTemperature ( 1 , 10 , -2.0 ,5 );
 
  tft.drawFloat(calTemperature, 2 , 0, 15, 2 );
 
  delay(1000);  // wait for a second
}
