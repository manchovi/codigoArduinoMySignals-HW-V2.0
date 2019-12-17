//No funciona este ejemplo con el sensor CHOVI. OJO

#include <MySignals.h>
#include "Wire.h"
#include "SPI.h"

int valuePulse;
int valueSPO2;
uint8_t pulsioximeter_state = 0;

void setup()
{

  Serial.begin(19200);
  MySignals.begin();
 
  MySignals.initSensorUART();
  MySignals.enableSensorUART(PULSIOXIMETER);
}

void loop()
{

  // First way of getting sensor data
  MySignals.enableSensorUART(PULSIOXIMETER);
//  Serial.println();
  pulsioximeter_state = MySignals.getPulsioximeterMini();
// Needed to be done, so that the print in the Serial monitor come without error
  MySignals.disableSensorUART();
  if (pulsioximeter_state == 1)
  {
    Serial.print(F("Pulse:"));
    Serial.print(MySignals.pulsioximeterData.BPM);
    Serial.print(F("bpm / SPO2:"));
    Serial.print(MySignals.pulsioximeterData.O2);
    Serial.println(F("%"));
  }
  else if (pulsioximeter_state == 2)
  {
    Serial.println(F("Finger out of calculating"));
  }
  else
  {
    Serial.println(F("No available data"));
  }
  delay(1000);


}
