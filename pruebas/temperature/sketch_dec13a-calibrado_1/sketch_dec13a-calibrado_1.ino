#include <MySignals.h>

void setup()
{
  Serial.begin(115200);
  MySignals.begin();
}


void loop()
{
  float calTemperature = MySignals.getCalibratedTemperature ( 1 , 10 , -2.0 ,5 );
  Serial.print(F("Temperature (*C): "));       
  Serial.println(calTemperature, 2); 
  delay(1000);  // wait for a second
}
