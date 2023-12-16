#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,9,8,7,6,5,4,3,2);
int buzzer=2;
int trigger=13;
int echo=10;
int push=7;
int led=13;
void setup() {
lcd.begin(16,2);
lcd.clear();
pinMode(buzzer,OUTPUT);
pinMode(trigger,OUTPUT);
pinMode(echo,INPUT);
pinMode(led,OUTPUT);
pinMode(push,INPUT);

}

void loop() {
   //LCD dispaly
  lcd.setCursor(0,0);
  lcd.print("SMART WAY FOR");
  lcd.setCursor(0,1);
  lcd.print("VISUALLY IMPAIRED");

  //Ultrasonic sensor & buzzer & push button
 if(digitalRead(push)==HIGH)
 {
 digitalWrite(led,HIGH);
 long duration,distance;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration=pulseIn(echo,HIGH);
  distance=(duration/2)/29.1;
  if(distance<=30)
{
tone(buzzer,1000);
  delay(1000);
  
}
else
{
noTone(buzzer);
  delay(1000);
}
 }
 else
 {
 digitalWrite(led,LOW);
 }

}
