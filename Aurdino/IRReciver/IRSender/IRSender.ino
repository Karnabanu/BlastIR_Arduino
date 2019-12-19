#include <IRremote.h>
#define rx 2
#define tx 5
#include<SoftwareSerial.h>
SoftwareSerial mySerial(rx,tx);
IRrecv irrecv(11);
decode_results results;
IRsend irsend;
int toggle=0;
int v;
char prevVal='Z';
void sendCode(char val);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(38400);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  /*// put your main code here, to run repeatedly:
  /*toggle = 1 - toggle;
  irsend.sendNEC(551485695,32);
  v=2083;
  delay(20);
  v=v&~(1 << (12 - 1));
  v = v | (toggle << (12 - 1));
  //irsend.sendRC5(2080,12);
  irsend.sendRC5(v,12);
  Serial.print("toggel ");
  Serial.println(toggle);
  delay(2000);
  /*irsend.sendNEC(551485695,32);
  delay(20);
  irsend.sendRC5(2081,12);
  delay(2000);*/
  /*irsend.sendNEC(551520375,32);
  delay(10);
  irsend.sendRC5(15,12);
  delay(2000);
  v=2082;
  v=v&~(1 << (12 - 1));
  v = v | (toggle << (12 - 1));
  irsend.sendRC5(v,12);
  delay(1000);
  toggle = 1 - toggle;
  /*if (irrecv.decode(&results))
    {
     Serial.println("message started");
     Serial.println(results.value);//, BIN);
     Serial.println(results.decode_type);
     Serial.printl.,mnnnnnvvvvvvvcn(results.rawlen);
     Serial.println(results.bits);
     Serial.println("message ended");
     irrecv.resume(); // Receive the next value
    }
    delay(3000);*/


  if( mySerial.available())       // if data is available to read
  {
    //Serial.write(mySerial.read());
    sendCode(mySerial.read());         // read it and store it in 'val'
  }
    
}

void sendCode(char val){
  Serial.println(val);
  int code;
  if(val==prevVal)
    toggle=1-toggle;
  else
    toggle=0;
  prevVal=val;
  switch(val){
    case 'a':
      code=2049;//1
      break;
    case 'b':
      code=2050;//2
      break;
    case 'c':
      code=2051;//3
      break;
    case 'd':
      code=2052;//4
      break;
    case 'e':
      code=2053;//5
      break;
    case 'f':
      code=2054;//6
      break;
    case 'g':
      code=2055;//7
      break;
    case 'h':
      code=2056;//8
      break;
    case 'i':
      code=2057;//9
      break;
    case 'j':
      code=2062;//0
      break;
    case 'k':
      code=2060;//power
      break;
    case 'l':
      code=2061;//mute
      break;
    case 'm':
      code=2063;//list
      break;
    case 'n':
      code=2064;//vol+
      break;
    case 'o':
      code=2065;//vol-
      break;
    case 'p':
      code=2066;//eye
      break;
    case 'q':
      code=2067;//equilizer
      break;
    case 'r':
      code=2070;//green mode
      break;
    case 't':
      code=2080;//ch+
      break;
    case 'u':
      code=2081;//ch--
      break;
    case 'v':
      code=2082; //Q-view
      break;
    case 'w':
      code=2084; //xds
      break;
    case 'x':
      code=2085;//ok
      break;
    case 'y':
      code=2086;//timer
      break;
    case 'z':
       code=2099;//screen view
       break;
    case 'A':
       code=2103;//white Speakers
       break;
    case 'B':
       code=2104;//tv/av
       break;
    case 'C':
       code=2107;//menu
       break;
    default:
       return;   
  }
  code=code&~(1 << (12 - 1));
  code = code | (toggle << (12 - 1));
  irsend.sendRC5(code,12);
}

