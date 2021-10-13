//Aircarto

#include <Wire.h>
#include <LiquidCrystal_I2C.h>  //bibliothèque pour l'écran LCD
#include <SDS011.h>             //bibliothèque pour le capteur SDS011

LiquidCrystal_I2C lcd(0x27, 16, 2);

float p10, p25;
int error;

SDS011 my_sds;

void setup()
{
  Serial.begin(9600);
  my_sds.begin(10, 11);

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("AirCarto.fr");     //Message d'intro ligne 1
  lcd.setCursor(0, 1);
  lcd.print("Atelier capteur"); //message d'intro ligne 2
  delay(1000);
}

void loop()
{
  error = my_sds.read(&p25, &p10);
  if (! error) {
    Serial.println("P2.5: " + String(p25));
    Serial.println("P10:  " + String(p10));
    lcd.setCursor(0, 0);
    lcd.print("PM2.5: " + String(p25, 1) + " ugm3");
    lcd.setCursor(0, 1);
    lcd.print("PM10:  " + String(p10, 1) + " ugm3");
  }
  delay(2000);
}
