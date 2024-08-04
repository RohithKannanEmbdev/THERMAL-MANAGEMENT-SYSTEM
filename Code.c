

#include <LiquidCrystal.h>
#include <dht.h>
#define DHT11_DPIN 8
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;

int level = A1;
int motor1relayPin = 10;
int motor2relayPin = 7;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello BMS in EV");
  delay(1000);
  lcd.clear();
  pinMode(motor1relayPin,OUTPUT);
  pinMode(motor2relayPin,OUTPUT);
  digitalWrite(motor1relayPin,HIGH);
  digitalWrite(motor2relayPin,HIGH);
}

void loop()
{
  int chk = DHT.read11(DHT11_DPIN);
  float temp = DHT.temperature;

  if (temp > 35)
  {
    int val = analogRead(level);
        if(val>=451 && val<=750)
          {
            lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temp);
lcd.print("C");

            Serial.println("WATER LEVEL HIGH");
            digitalWrite(motor1relayPin,LOW );
            Serial.println("PUMP 1 ON");
            lcd.setCursor(0, 1);
            lcd.print("PUMP 1 ON");
        int chk = DHT.read11(DHT11_DPIN);
        float temp = DHT.temperature;
          }
        else if(val>=0 && val<=450)
          {
            lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temp);
lcd.print("C");

            Serial.println("WATER LEVEL LOW");
            digitalWrite(motor1relayPin,HIGH );
            Serial.println("PUMP 1 OFF");
            lcd.setCursor(0, 1);
            lcd.print("PUMP 1 OFF");
            int chk = DHT.read11(DHT11_DPIN);
        float temp = DHT.temperature;
          }
          else
          {
            lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temp);
lcd.print("C");

          }
          

  }
         
else if (temp < 35)
  {
    int val = analogRead(level);
        if(val>=0 && val<=450)
          {
            lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(temp);
            lcd.print("C");

            Serial.println("TEMP LESS THAN 35");
            digitalWrite(motor2relayPin,LOW );
            Serial.println("PUMP 2 ON");
            lcd.setCursor(0, 1);
            lcd.print("PUMP 2 ON");
        int chk = DHT.read11(DHT11_DPIN);
        float temp = DHT.temperature;
          }
    else if(val>=451 && val<=750)
          {
           lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(temp);
            lcd.print("C");
            Serial.println("WATER LEVEL HIGH");
            digitalWrite(motor2relayPin,HIGH );
            Serial.println("PUMP 2 OFF");
            lcd.setCursor(0, 1);
            lcd.print("PUMP 2 OFF");
            int chk = DHT.read11(DHT11_DPIN);
        float temp = DHT.temperature;
          }
          else
          {
           lcd.setCursor(0, 0);
            lcd.print("Temp: ");
            lcd.print(temp);
            lcd.print("C");
          }
  }
  else
  {
  Serial.println("SYSTEM OK");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM OK");
  lcd.clear();
  }

lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temp);
lcd.print("C");

Serial.print("Temp: ");
Serial.print(temp);
Serial.println("C");
  delay(1000);
}
