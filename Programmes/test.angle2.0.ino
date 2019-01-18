#include <Servo.h>
Servo servo1;
float anglemicro;
int angle;
//int pot = 0;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(4);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //servo1.writeMicroseconds(90);
  //Serial.println(angle);
  //angle = analogRead(pot);
  //angle = map(angle, 0, 1023, 0, 179);
  for (int i=0; i<160; i++){
    servo1.write(i);
    delay(5);
  }
  delay(100);
  //int limit =0;
  for (int i=160; i>0; i--){
    servo1.write(i);
    delay(5);
  }
  
}
