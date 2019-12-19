/* Copyright (c) 2011, Jan Clement
 * licenced under the GPL
 *
 * Author: Jan Clement <jan.clement@audiokits.de>
 * 
 * Example code to demonstrate the use of protothreads 
 * in an arduino sketch. It toggles an LED  using two 
 * independent protothreads. One pt toggles every 
 * 1000ms, the other one every 900ms. The result is an 
 * erratic blinking pattern.
 */
#include<IRremote.h>
#include <Thread.h>
Thread ledThread=Thread();


IRrecv irrecv(11);
IRsend irsend;
decode_results results[10];
int i=0;


void sendCode(){
  //irsend.sendNEC(551485695,32);
  //delay(10);
  irsend.sendRC5(2080,12);
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  ledThread.onRun(sendCode);
}

void loop(){
  //if(ledThread.shouldRun())
    //ledThread.run();
  //Serial.println("main");
  //sendCode();
  //delay(100);
  if(i==10){
    Serial.println("Transmission Started");
    for(int j=0;j<=i;j++)
    {
      switch(results[j].decode_type){
        case -1:
          Serial.println("UNKNOWN Droped");
          break;
        case 0:
          Serial.println("UNUSED Droped");
          break;
         case 1:
          irsend.sendRC5(results[j].value,results[j].bits);
          Serial.print("RC5 Sent ");
          Serial.println(results[j].value);
          break;
         case 2:
          Serial.println("RC6 Droped");
         case 3:
          irsend.sendNEC(results[j].value,results[j].bits);
          Serial.print("NEC Sent ");
          Serial.println(results[j].value);
          defalut:
            Serial.println("Other Droped");
           
      }
      delay(10);
    }
    Serial.println("Transmission Ended");
    IRrecv irrecv(11);
    irrecv.enableIRIn();
    i=0;
  }
  if (irrecv.decode(&(results[i])))
  {
     Serial.print(results[i].value);//, BIN);
     Serial.print(" ");
     if(results[i].decode_type==-1)
      Serial.print("UNKNOWN");
     else if(results[i].decode_type==0)
      Serial.print("UNUSED");
     else if(results[i].decode_type==1){
      Serial.print("RC5");
     }
      else if(results[i].decode_type==2)
      Serial.print("RC6");
      else if(results[i].decode_type==3){
        Serial.print("NEC");
      }
      else{
        Serial.print("OTHER(");
        Serial.print(results[i].decode_type);
        Serial.print(")");
      }
      Serial.print(" ");
      Serial.print(results[i].rawlen);
      Serial.print(" ");
      Serial.println(results[i].bits);
      irrecv.resume(); // Receive the next value
      i++;
    }
    
}

