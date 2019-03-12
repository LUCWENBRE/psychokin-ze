//HC-12 messenger send/receive
//autor Tom Heylen tomtomheylen.com

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX
float accX=512, accY=512, accZ=512;
char Data;

const int trig=11;
const int echo=8;
float distance;

int ENA=9; //Connecté à Arduino pin 9(sortie PWM) 
int IN1=4; //Connecté à Arduino pin 4 
int IN2=5; //Connecté à Arduino pin 5

int ENB=10; //Connecté à Arduino pin 10(Sortie PWM) 
int IN3=6; //Connecté à Arduino pin 6 
int IN4=7; //Connecté à Arduino pin 7




void setup() {
  /*vitesse moniteur*/
  Serial.begin(115200);
  /*vitesse recepteur*/
  mySerial.begin(9600);
  
  pinMode(ENA,OUTPUT); // Configurer 
  pinMode(ENB,OUTPUT); // les broches 
  pinMode(IN1,OUTPUT); // comme sortie 
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner 
  digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner

  // Direction du Moteur A 
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);


  // Direction du Moteur B 
  // NB: en sens inverse du moteur A 
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW);

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
/************* Moteur avec angle X **************/

    if (accX> 355 && accX<365){
        analogWrite(ENA,0);
        analogWrite(ENB,0);
        digitalWrite(IN1,HIGH); 
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW); 
        digitalWrite(IN4,HIGH);
        }
    else if( accX >= 365 && accX<=390){
        analogWrite(ENA,accX);
        analogWrite(ENB,accX);
        digitalWrite(IN1,HIGH); 
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW); 
        digitalWrite(IN4,HIGH);
        }
    
    else if(( accX >390) && (accY >405)){
        analogWrite(ENA,0);
        analogWrite(ENB,accX/5);
         digitalWrite(IN1,LOW); 
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,HIGH); 
        digitalWrite(IN4,LOW);
    }
    else if(( accX >390) && (accY <=345)){
        analogWrite(ENA,accX/5);
        analogWrite(ENB,0);
        digitalWrite(IN1,LOW); 
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,HIGH); 
        digitalWrite(IN4,LOW);
    }
    else {

          /*sens inverse moteur A */
          digitalWrite(IN1,LOW);  
          digitalWrite(IN2,HIGH);  


          /*sens inverse moteur B */
          digitalWrite(IN3,HIGH); 
          digitalWrite(IN4,LOW);

          analogWrite(ENA,accX);
          analogWrite(ENB,accX);
    }  
}
//Serial.print("X = ");
//Serial.println(accX);       
//Serial.println(" Y = ");
//Serial.println(accY);
//Serial.print(" Z = ");
//Serial.println(accZ); 
