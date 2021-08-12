#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define led01 2
#define led02 3
#define led03 4

#define btn01 5
#define btn02 6
#define btn03 7

LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
  Serial.begin(9600);

  pinMode(led01, OUTPUT);
  pinMode(led02, OUTPUT);
  pinMode(led03, OUTPUT);

  pinMode(btn01, INPUT);
  pinMode(btn02, INPUT);
  pinMode(btn03, INPUT);

  digitalWrite(led01, HIGH);
  digitalWrite(led02, HIGH);
  digitalWrite(led03, HIGH);

  lcd.init();
  Wire.begin();
  lcd.backlight();

  lcd.setCursor(4, 0);
  lcd.print("DinhNT");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Test I2C-Ardiuno");
  lcd.setCursor(1, 1);
  lcd.print("L1:");
  lcd.setCursor(6, 1);
  lcd.print("L2:");
  lcd.setCursor(11, 1);
  lcd.print("L3:");
}

void loop()
{

  if (digitalRead(btn01) == LOW) {
    digitalWrite(led01, LOW);
    Serial.println("LED1 is ON");
    lcd.setCursor(4, 1);
    lcd.print("1");
  }
  else {
    digitalWrite(led01, HIGH);
    Serial.println("LED1 is OFF");
    lcd.setCursor(4, 1);
    lcd.print("0");
  }

  if (digitalRead(btn02) == LOW) {
    digitalWrite(led02, LOW);
    Serial.println("LED2 is ON");
    lcd.setCursor(9, 1);
    lcd.print("1");
  }
  else {
    digitalWrite(led02, HIGH);
    Serial.println("LED2 is OFF");
    lcd.setCursor(9, 1);
    lcd.print("0");
  }

  if (digitalRead(btn03) == LOW) {
    digitalWrite(led03, LOW);
    Serial.println("LED3 is ON");
    lcd.setCursor(14, 1);
    lcd.print("1");
  }
  else {
    digitalWrite(led03, HIGH);
    Serial.println("LED3 is OFF");
    lcd.setCursor(14, 1);
    lcd.print("0");
  }
}
