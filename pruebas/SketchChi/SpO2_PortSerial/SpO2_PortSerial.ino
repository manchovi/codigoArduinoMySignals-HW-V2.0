/*
 * especificaciones técnicas del Oxímetro de pulso (BLE):
 * 1.SpO2
 * Rango de medición: 35-100%
 * Precisión: + -2% (80-100%); + -3% (70-79%)

 * 2. Tasa de pulso:
 * Rango de medición: 25-250bpm
 * Precisión: + -2bpm
*/


#include <MySignals.h>
#include "Wire.h"
#include "SPI.h" 
int valuePulse;
int valueSPO2;
uint8_t pulsioximeter_state = 0;

//! It stores the current value of the MySignals. 
uint16_t valRead;

void setup(){
  //Serial.begin(19200);   //No funciona a esta velocidad 
  Serial.begin(115200);    //Funciona a esta velocidad
 
  MySignals.begin();
  MySignals.initSensorUART();
  MySignals.enableSensorUART(PULSIOXIMETER);
  
  //Enable ADC SPI -> bit4: 1
  //bitSet(MySignals.expanderState, EXP_ADC_CS);   
  //MySignals.expanderWrite(MySignals.expanderState);
  
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
        MySignals.disableMuxUART();
        Serial.println();
        Serial.print(MySignals.pulsioximeterData.BPM);
        Serial.print(" PRbpm ----------"); 
        Serial.print(MySignals.pulsioximeterData.O2);
        Serial.println(" %SpO2"); 
        MySignals.enableMuxUART();
      }else if (getPulsioximeterMicro_state == 2){
        //Serial.println(F("Finger out or calculating"));
      }else{
        MySignals.spo2_micro_detected = 0;
        //Serial.println(F("SPO2 Micro lost connection"));
      }
    }

      
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

    //Fin de las lecturas del sensor SPO2. Funcionable en su totalidad

  delay(1000);
  Serial.flush();
  
}
