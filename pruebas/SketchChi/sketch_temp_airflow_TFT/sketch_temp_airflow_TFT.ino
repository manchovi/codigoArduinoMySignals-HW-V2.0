#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 
Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(115200);
  MySignals.begin();
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.drawCentreString("MEGATEC-ZACATECOLUCA",0, 0, 2);
  tft.drawCentreString("HOSPITAL SANTA TERESA",0, 15, 2);
  tft.drawString("Signos Vitales de Pacientes: ", 0, 45, 2);
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
  //Serial.print("Temperature (ºC): ");       
  //Serial.print(temperature, 2);  
  //Serial.println("");
  tft.drawString("° Celcius:", 25, 65, 2);
  
  //drawNumber(long long_num,int poX, int poY, int size)
  //tft.drawNumber(temperature, 0, 75, 2); 
  
  //drawFloat(float floatNumber, int decimal, int poX, int poY, int size)
  tft.drawFloat(temperature, 2, 0, 75, 2);
  delay(1000);
  
  
}
    
