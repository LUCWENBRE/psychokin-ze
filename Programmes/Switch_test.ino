#include <RCSwitch.h>
#include <Wire.h>
float Acc_X, Acc_Y, Acc_Z;
const int MPU_addr =0x68;
int angle_x;
int angle_y;
RCSwitch mySwitch = RCSwitch();
String x;
String y;

int afficher(){
  return angle_x;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySwitch.enableTransmit(4);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();

}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,6,true);

  Acc_X=(Wire.read()<<8|Wire.read());
  Acc_Y=(Wire.read()<<8|Wire.read());
  Acc_Z=(Wire.read()<<8|Wire.read());

  angle_x = (atan((Acc_X) / sqrt(pow((Acc_Y),2) + pow((Acc_Z),2))) * 180/PI);
  angle_y = (atan((Acc_Y) / sqrt(pow((Acc_X),2) + pow((Acc_Z),2))) * 180/PI);

  if(angle_x>0){
    Serial.println("La voiture avance");
    }
  else{
    Serial.println("La voiture recule");
    }
  if(angle_y>0){
    Serial.println("La voiture tourne à droite");
    }
  else{
    Serial.println("La voiture tourne à gauche");
    }
    Serial.print(angle_x);
    Serial.print("        ");
    Serial.print(angle_y);
    Serial.println("      ");
  
  mySwitch.send((0 + " " + angle_x), 24);
  //mySwitch.send((1 + " " + angle_y), 24);
  //delay(250);
}
