#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int angle_x;
float angle_y;
String positionValue;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    mySwitch.enableReceive(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySwitch.available()){
    int value = mySwitch.getReceivedValue();

    if (value==0){
      Serial.println("Error");
    }
    positionValue = String(mySwitch.getReceivedValue());
    if (positionValue.substring(0,1) == "0 "){
      angle_x = positionValue.substring(2,2).toInt();
      Serial.println("Déplacement selon x, l' angle est de ");
      Serial.println(angle_x); 
      }
  }
}
