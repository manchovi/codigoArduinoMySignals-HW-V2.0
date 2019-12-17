#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>
#include "Wire.h"
#include "SPI.h"
Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);
uint16_t graphic_x = 0;

uint16_t valRead;
uint16_t graphic_prevRead;
#define graphic_low_extrem 230
#define graphic_high_extrem 50
#define graphic_left_extrem 0
#define graphic_right_extrem 320

void setup(){
  Serial.begin(115200);
  MySignals.begin();
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_WHITE);
  tft.fillRect(0,0,320,30,ILI9341_RED);
  tft.setTextColor(ILI9341_WHITE);
  tft.drawString("Electrocardiograma",5,5,4);
}

void loop(){
  uint16_t ecg = (uint16_t)MySignals.getECG(DATA);
  ecg = map(ecg, 0,1023,1023,0);
  
  Serial.println(ecg);
  delay(2);
  float ECG = MySignals.getECG(VOLTAGE);
  Serial.print("VALOR DE ELECTROCARDIIOGRAMA : ");
  Serial.print(ECG, 2);
  Serial.println(" mV");
  // wait for a millisecond
  delay(50);
  valRead = MySignals.getECG(DATA);
  //Serial.println(valRead);
  valRead = map(valRead, 150, 600, graphic_high_extrem, graphic_low_extrem);
  printGraphic(valRead,0);
}

  
  void printGraphic(uint16_t value, uint8_t delay_time){
  if (value < graphic_high_extrem){
      value = graphic_high_extrem;
  }
  
  if (value > graphic_low_extrem){
      value = graphic_low_extrem;
  }
  
  //Pinta la linea solo a partir de que ya exista al menos 1 valor
  if (graphic_x > graphic_left_extrem + 1){
      tft.drawLine(graphic_x - 1, graphic_prevRead, graphic_x, value, ILI9341_RED);
  }
  
  //Wave refresh (barre pantalla pintando una linea)
  tft.drawLine(graphic_x + 1, graphic_high_extrem, graphic_x + 1, graphic_low_extrem, ILI9341_WHITE);
  graphic_prevRead = value;
  graphic_x++;
  delay(delay_time);
  
  if (graphic_x == graphic_right_extrem){
    graphic_x = graphic_left_extrem;
  }
  
  SPI.end();
}

