#include <SoftwareSerial.h>

/*The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)*/
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  mySerial.begin(9600);
  mySerial.println("Hello, world?");

}

void loop() {
  // put your main code here, to run repeatedly:
  mySerial.println("Ya entre....");
  Serial.println("Ya entre....");

  mySerial.println(F("Micro detected"));
  Serial.println(F("Micro detected"));

  mySerial.println(F("FINAL LOOP"));
  Serial.println(F("FINAL LOOP"));

  delay(1000);
  
}
