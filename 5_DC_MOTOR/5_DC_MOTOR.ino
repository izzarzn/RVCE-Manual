void setup() {
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
      digitalWrite(16,HIGH);
      digitalWrite(5,LOW);//M1
      delay(3000);
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);//M1
      delay(3000);
}
