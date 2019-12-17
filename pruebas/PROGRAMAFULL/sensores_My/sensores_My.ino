#include <Adafruit_GFX_AS.h>
#include <Adafruit_ILI9341_AS.h>
#include <MySignals.h>
Adafruit_ILI9341_AS tft = Adafruit_ILI9341_AS(TFT_CS, TFT_DC);
int valuePulse;
int valueSPO2;
uint8_t pulsioximeter_state = 0;

void setup(){
  Serial.begin(19200);
  MySignals.begin();
  MySignals.initSensorUART();
  MySignals.enableSensorUART(PULSIOXIMETER);
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.drawCentreString("MEGATEC-ZACATECOLUCA",0, 0, 2);
  tft.drawCentreString("HOSPITAL SANTA TERESA",0, 15, 2);
  tft.drawString("SENSOR SPO2:", 0, 45, 2);
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
if (MySignals.spo2_micro_detected == 0 && MySignals.spo2_mini_detected == 0){
  uint8_t statusPulsioximeter = MySignals.getStatusPulsioximeterGeneral();
  
  if (statusPulsioximeter == 1){
      MySignals.spo2_mini_detected = 0;
      MySignals.spo2_micro_detected = 1;
      tft.drawString("Micro detected", 0, 100, 2);            //Mi conector de sensores....
    }else if (statusPulsioximeter == 2){
      MySignals.spo2_mini_detected = 1;
      MySignals.spo2_micro_detected = 0;
      tft.drawString("Mini detected", 0, 100, 2);
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

    


    
    
  delay(1000);
  
}