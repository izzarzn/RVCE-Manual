void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldr_Value=analogRead(A0);
  Serial.print("LDR VALUE:");
  Serial.println(ldr_Value);
  delay(1000);
}
