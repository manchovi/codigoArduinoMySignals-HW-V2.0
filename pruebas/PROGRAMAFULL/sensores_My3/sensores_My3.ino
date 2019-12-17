#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 
Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);
int valuePulse;
int valueSPO2;
uint8_t pulsioximeter_state = 0;

//! It stores the current value of the MySignals. 
uint16_t valRead;

void setup(){
  //Serial.begin(19200);   //Funciona bien a esta velocidad
  Serial.begin(115200);
  MySignals.begin();
  tft.init();
  
  MySignals.initSensorUART();
  
  MySignals.enableSensorUART(PULSIOXIMETER);
  delay(1000);
  
  MySignals.enableSensorUART(BLOODPRESSURE);
  delay(1000);
  
  //Enable ADC SPI -> bit4: 1
  //bitSet(MySignals.expanderState, EXP_ADC_CS);   
  //MySignals.expanderWrite(MySignals.expanderState);
  //MySignals.expanderWrite (B10010001);

  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.drawCentreString("MEGATEC-ZACATECOLUCA",0, 0, 2);
  tft.drawCentreString("HOSPITAL SANTA TERESA",0, 15, 2);
  tft.drawString("SENSOR - SPO2:", 0, 45, 2);
  //tft.drawString("Saturacion Parcial del Oxigeno:", 0, 0, 2);
}

void loop(){
  /*
  pulsioximeter_state = MySignals.getPulsioximeter();
  if (pulsioximeter_state == 1)
  {
  tft.drawNumber(MySignals.pulsioximeterData.BPM, 0, 30, 2);
  tft.drawNumber(MySignals.pulsioximeterData.O2, 0, 45, 2);
  }
  delay(1000);
  */
  //MySignals.initSensorUART();
  //MySignals.enableSensorUART(PULSIOXIMETER);
if (MySignals.spo2_micro_detected == 0 && MySignals.spo2_mini_detected == 0){
  uint8_t statusPulsioximeter = MySignals.getStatusPulsioximeterGeneral();
  
  if (statusPulsioximeter == 1){
      MySignals.spo2_mini_detected = 0;
      MySignals.spo2_micro_detected = 1;
      //tft.drawString("Micro detected", 0, 100, 2);            //Mi conector de sensores....
    }else if (statusPulsioximeter == 2){
      MySignals.spo2_mini_detected = 1;
      MySignals.spo2_micro_detected = 0;
      //tft.drawString("Mini detected", 0, 100, 2);
    }else{
      MySignals.spo2_micro_detected = 0;
      MySignals.spo2_mini_detected = 0;
    }
  }

  if(MySignals.spo2_micro_detected == 1){
    MySignals.enableSensorUART(PULSIOXIMETER_MICRO);
    delay(10);
    uint8_t getPulsioximeterMicro_state = MySignals.getPulsioximeterMicro();
    if (getPulsioximeterMicro_state == 1){
        tft.drawNumber(MySignals.pulsioximeterData.BPM, 0, 60, 2);
        tft.drawString("PRbpm", 25, 65, 2); 
        tft.drawNumber(MySignals.pulsioximeterData.O2, 0, 75, 2);
        tft.drawString("%SpO2", 25, 80, 2); 
      }else if (getPulsioximeterMicro_state == 2){
        //Serial.println(F("Finger out or calculating"));
      }else{
        MySignals.spo2_micro_detected = 0;
        //Serial.println(F("SPO2 Micro lost connection"));
      }
    }

      delay(5000);
    /*if (MySignals.spo2_mini_detected == 1){
      MySignals.enableSensorUART(PULSIOXIMETER);
      uint8_t getPulsioximeterMini_state = MySignals.getPulsioximeterMini();
      if (getPulsioximeterMini_state == 1){
        tft.drawNumber(MySignals.pulsioximeterData.BPM, 0, 30, 2);
        tft.drawNumber(MySignals.pulsioximeterData.O2, 0, 45, 2);
      }else if (getPulsioximeterMini_state == 2){
        //Serial.println(F("Finger out or calculating"));
      }else if (getPulsioximeterMini_state == 0){
        MySignals.spo2_mini_detected = 0;
        //Serial.println(F("SPO2 Mini lost connection"));
      }
    }*/

    //Fin de las lecturas del sensor SPO2. Funcionable en su totalidad.


 
  /*valRead = (uint16_t)MySignals.getAirflow(DATA);
  valRead = map(valRead, 0, 1023, 230, 30);
  
  tft.drawString("SENSOR - FRECUENCIA RESPIRATORIA", 0, 100, 2);           
  tft.drawNumber(valRead, 0, 115, 2);*/

  //MySignals.disableMuxUART();
  MySignals.initSensorUART();
  MySignals.enableSensorUART(BLOODPRESSURE);

  if (MySignals.getStatusBP())
  {
    delay(1000);

    if (MySignals.getBloodPressure() == 1)
    {
      
      tft.drawString("Diastolic:", 0, 115, 2);
      tft.drawNumber(MySignals.bloodPressureData.diastolic, 100, 15, 2);
      
      tft.drawString("Systolic:", 0, 130, 2);
      tft.drawNumber(MySignals.bloodPressureData.systolic, 100, 30, 2);

      tft.drawString("Pulse/min:", 0, 145, 2);
      tft.drawNumber(MySignals.bloodPressureData.pulse, 100, 45, 2);  

    }
  }


  

  delay(5000);
  
}
