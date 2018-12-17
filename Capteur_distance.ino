const int trig=9;
const int echo=8;
float distance;
const int led_rouge=3;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
distance = pulseIn(echo, HIGH)/58.00; 
if (distance < 10){
  digitalWrite(3,HIGH);}
else { digitalWrite(3,LOW);}
Serial.print(distance);
Serial.print("cm");
Serial.println();// lecture de la longueur temporelle de l'impulsion Echo
}
