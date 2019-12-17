#include <MySignals.h>
#include "Wire.h"
#include "SPI.h"
void setup()
{

  Serial.begin(19200);      //Funciona a esta velocidad
  //Serial.begin(115200);   //No funciona a esta velocidad
  MySignals.begin();

  MySignals.initSensorUART();
  MySignals.enableSensorUART(BLOODPRESSURE);
}

void loop()
{
  
  if (MySignals.getStatusBP())
  {
    delay(1000);

    if (MySignals.getBloodPressure() == 1)
    {
      MySignals.disableMuxUART();
      Serial.println();
      Serial.print("Diastolic: ");
      Serial.println(MySignals.bloodPressureData.diastolic);
      Serial.print("Systolic: ");
      Serial.println(MySignals.bloodPressureData.systolic);
      Serial.print("Pulse/min: ");
      Serial.println(MySignals.bloodPressureData.pulse);
      MySignals.enableMuxUART();

    }
  }
  Serial.flush();
  delay(1000);
  //MySignals.getStatusBP();  La idea de esta función es evitar que el sensor de tensión arterial se apague
                              //Pero no me ha funcionado. Seguire investigando al respecto.
  
}
