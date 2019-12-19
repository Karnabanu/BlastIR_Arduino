#define rx 2
#define tx 5
#include<SoftwareSerial.h>
SoftwareSerial mySerial(rx,tx);
void setup() {
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter AT Commands:");
  mySerial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available())
    Serial.write(mySerial.read());
  if(Serial.available())
    mySerial.write(Serial.read());
}
