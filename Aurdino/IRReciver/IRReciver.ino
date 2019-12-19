#include<IRremote.h>
#include<pt.h>

IRrecv irrecv(11);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
    {
     Serial.println("message started");
     Serial.println(results.value);//, BIN);
     Serial.println(results.decode_type);
     Serial.println(results.rawlen);
     Serial.println(results.bits);
     Serial.println("message ended");
     irrecv.resume(); // Receive the next value
    }
}
