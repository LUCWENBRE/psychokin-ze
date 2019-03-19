//HC-12 messenger receive

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX
int accX=512, accY=512, accZ=512;
char Data;

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
}

void loop() {
  
  if(mySerial.available()){//Read from HC-12 and send to serial monitor
    Data=mySerial.read(); 
    if(Data=='X') {
      accX=mySerial.parseInt();}
    if(Data=='Y') {
      accY=mySerial.parseInt();}
    if(Data=='Z') {
      accZ=mySerial.parseInt();}
   } 
Serial.print("X = ");
Serial.print(accX); 
Serial.print(" Y = ");
Serial.print(accY);
Serial.print(" Z = ");
Serial.println(accZ); 
}
