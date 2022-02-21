#include <SoftwareSerial.h>
 SoftwareSerial mySerial(14,12); // RX(GPIO14),TX(GPIO12)
 void setup() {
  // Open serial communications and wait for port to open:
     Serial.begin(9600);
     mySerial.begin(9600);
    pinMode(15,OUTPUT);
  }
 void loop() { // run over and over
  char  val;
   if (mySerial.available()) 
    {
        val=mySerial.read();
        if(val=='1')
        digitalWrite(15,HIGH);
        if(val=='0')
        digitalWrite(15,LOW);
    }
 }






 




 
