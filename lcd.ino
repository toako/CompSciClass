#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int red = 6;
int spkr = 7;
int second;
int prevSecond;
int beepInterval = 1;

void setup()
{
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bomb detonates:");

  
}

void loop()
{
  digitalWrite(red, HIGH);
  second = 20 - (millis()/1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bomb detonates:");
  lcd.setCursor(0,1);
  lcd.print(second);
  tone(spkr, 1000 + ((20 - second) * 10), 50);
  delay(50);
  digitalWrite(red, LOW);
  delay(950);

}
