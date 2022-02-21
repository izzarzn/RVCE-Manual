void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldr=analogRead(A0);
  Serial.println(ldr);
  if(ldr>500){
    digitalWrite(13,HIGH);
    delay(1000);
  }
  digitalWrite(13,LOW);
}
