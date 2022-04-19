// C++ code
//
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);//LCD display port number

#define in 8 
#define out 9 
#define led 10 
//in= in sensor, out=out sensor, led=LED light

int count=0;//intially count is 0

void setup()
{
  lcd.begin(16,2);//16x2 LCD display config
  lcd.print("Visitor Counter"); // display words at beginning
  delay(2000);
  pinMode(in,INPUT);
  pinMode(out,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  int in_value= digitalRead(in);//it take value from in sensor
  int out_value= digitalRead(out);//it take value from out sensor
  if(in_value == LOW)
  {
    count++;
    lcd.clear();
    lcd.setCursor(1,0);//row,col
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  
  if(out_value == LOW)
  {
    count--;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  
  if (count==0)
  {
    lcd.clear();
    digitalWrite(led,LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light is OFF");
    delay(200);
  }
  
  else
  {
    digitalWrite(led,HIGH);//light gets on
  }
}