
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
#include "GyverButton.h"
#define PIN A2       // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define PIN2 A1
GButton count(PIN);
GButton butt(PIN2);
LCD_1602_RUS <LiquidCrystal_I2C> lcd(0x27, A4, A5);
int val = 0;
void setup()
{
  count.setType(HIGH_PULL);
  butt.setType(HIGH_PULL);
  butt.setType(NORM_CLOSE);
  count.setDebounce(1);        // настройка антидребезга (по умолчанию 80 мс)
  count.setClickTimeout(1);   // настройка таймаута между кликами (по умолчанию 300 мс)
  butt.setDebounce(1);        // настройка антидребезга (по умолчанию 80 мс)
  butt.setClickTimeout(1);   // настройка таймаута между кликами (по умолчанию 300 мс)
  lcd.init(); // Инициализация LCD
  // Печать сообщения на LCD
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("пров. счетчика");
  lcd.setCursor(6, 1);
  lcd.print(val, 10);
}

void loop()
{
  count.tick();
  if (count.isClick()) {
    val++;
    lcd.setCursor(6, 1);
    lcd.print(val, 10);
  }
  butt.tick();
  if (butt.isClick()) {
    val = 0;
    lcd.clear(); 
    lcd.setCursor(1, 0);
    lcd.print("пров. счетчика");
    lcd.setCursor(6, 1);
    lcd.print(val, 10);
  }
}
