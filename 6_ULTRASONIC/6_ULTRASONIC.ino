#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define TRIGGER_PIN 12 //GPIO12
#define ECHO_PIN 14    //GPIO14
#define MAX_DISTANCE 200
int lcdColumns = 16;
int lcdRows = 2;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
void setup() { 
  Serial.begin(9600);
  // initialize LCD
    lcd.init();
    // turn on LCD backlight                      
    lcd.backlight();
}
void loop() {
  delay(1000);
  unsigned int uS = sonar.ping_cm();
  Serial.print("Length :"); 
  Serial.print(uS); 
  Serial.println("cm");
  lcd.setCursor(0, 0);
  lcd.print("Length :");
  lcd.print(uS); 
  lcd.print("cm");
  delay(500);
  lcd.clear();
}
