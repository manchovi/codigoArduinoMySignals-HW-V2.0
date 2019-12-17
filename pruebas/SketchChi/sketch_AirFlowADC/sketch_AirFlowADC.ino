/*
 * Pin  Function
 * C0  ADC_EMG
 * C1  ADC_ECG
 * C2  ADC_AIRFLOW
 * C3  ADC_GSR
 * C4  ADC_TEMPERATURE
 * C5  ADC_SNORE
 * C6  -
 * C7  -
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

  int read_adc_temp = MySignals.readADC(ADC_TEMPERATURE);
  Serial.print("Temperatura: ");
  Serial.println(read_adc_temp);

  //int read_adc = MySignals.readADC(ADC_AIRFLOW);
  //Serial.println(read_adc);
  
  delay(1000);
  
}

