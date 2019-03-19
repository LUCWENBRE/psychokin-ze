#include <Wire.h>
#include <LiquidCrystal.h>
float Acc_X, Acc_Y, Acc_Z;
LiquidCrystal lcd(3,4,5,6,7,8);
const int MPU_addr =0x68;
float angle_x;
float angle_y;
const int LED = 3;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
  lcd.begin(16, 2); // initialiser le nombre de colonnes et de lignes
  lcd.print("Bonjour");
  lcd.setCursor(0, 1); //le curseur se positionne à la 1ère colonne, 2ième ligne
  lcd.print("je suis en PeiP2");  
  delay(2000);
  lcd.clear();
}

void loop() {
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
    digitalWrite(LED,1);
    Serial.println("La voiture recule");
    }
    if(angle_y>0){
    digitalWrite(LED,0);
    Serial.println("La voiture tourne à droite");
    }
  else{
    digitalWrite(LED,1);
    Serial.println("La voiture tourne à gauche");
    }
    Serial.print(angle_x);
    Serial.print("        ");
    Serial.print(angle_y);
    Serial.println("      ");}
