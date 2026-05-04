#include <LiquidCrystal_I2C.h>

const byte POT = A1;

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

int lastPercent = -1;

void setup() {
  Serial.begin(9600);
  lcd1.init(); lcd1.backlight();
  lcd2.init(); lcd2.backlight();
}

void loop() {
  int raw = analogRead(POT);
  int percent = map(raw, 0, 1023, 0, 100);

  lcd1.setCursor(0, 0);
  lcd1.print("GT THO: ");
  lcd1.print(raw);
  lcd1.print("   ");

  lcd2.setCursor(0, 0);
  lcd2.print("PHAN TRAM:");
  lcd2.setCursor(0, 1);
  lcd2.print(percent);
  lcd2.print("%   ");

  if (percent != lastPercent) {
    Serial.println("-------------------");
    Serial.print("Gia tri tho: ");
    Serial.println(raw);
    Serial.print("Gia tri phan tram: ");
    Serial.print(percent);
    Serial.println("%");

    lastPercent = percent;
  }

  delay(200);
}