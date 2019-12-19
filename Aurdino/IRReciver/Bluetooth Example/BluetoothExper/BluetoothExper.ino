//#include<SoftwareSerial.h>
//SoftwareSerial mySerial(10,11);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  //pinMode(9,OUTPUT);
  //digitalWrite(9,HIGH);
  Serial.println("Enter AT Commands:");
  //mySerial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
/*if(mySerial.available())
  Serial.write(mySerial.read());
if(Serial.available())
  mySerial.write(Serial.read());*/
  if(Serial.available())
    Serial.write(Serial.read());
}

 
/*char val;
int ledpin=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //digitalWrite(1,HIGH);
  Serial.println("working");
  //
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(Serial.available());
  if(Serial.available()>0)
    val=Serial.read();
  if(val=='1'){
    //Serial.println("Changed");
    digitalWrite(ledpin,HIGH);
  }
  delay(1000);
}*/
/*#define BUFFERSIZE 127
uint8_t inBuffer[BUFFERSIZE];
int inLength; // length of data in the buffer
int numLoop = 0; // number of times we looped
int ledPin = 13;
void setup() { 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
} 
void loop() {
  // read string if available
  if (Serial.available()) {
    inLength =  0;
    while (Serial.available()) {
      inBuffer[ inLength] = Serial.read();
      inLength++;
      if (inLength >= BUFFERSIZE)
         break;
    }
  
    Serial.print("Arduino received: ");
    Serial.write(inBuffer ,inLength);
    Serial.println();
  }
  // blink the led and send a number
  digitalWrite(ledPin, HIGH); // set the LED on
  delay(100); // wait a bit
  Serial.println(numLoop);
  digitalWrite(ledPin, LOW); // set the LED off
  delay(1000);
  numLoop++;
}*/
