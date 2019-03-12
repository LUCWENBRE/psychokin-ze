//HC-12 messenger send/receive
//autor Tom Heylen tomtomheylen.com

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX
int accX=512, accY=512, accZ=512;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {

accX = analogRead(0);
accY = analogRead(1);
accZ = analogRead(2);
Serial.print("X = ");
Serial.print(accX);
Serial.print("   Y = ");
Serial.print(accY);
Serial.print("   Z = ");
Serial.println(accZ); 
 
mySerial.print("X");
mySerial.print(accX);
mySerial.print("Y");
mySerial.print(accY);
mySerial.print("Z");
mySerial.print(accZ);
  
}
