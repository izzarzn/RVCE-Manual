int buttonstate = 0;
void setup() {
  pinMode(15,OUTPUT);  // LED
  pinMode(16,INPUT);  //Toggle Switch
}

void loop() {
  buttonstate=digitalRead(16);
  if(buttonstate == 1)
   {
    digitalWrite(15,HIGH); // Make LED ON
   }
   else
   {
   digitalWrite(15,LOW);  // Make LED OFF
   }  
}
