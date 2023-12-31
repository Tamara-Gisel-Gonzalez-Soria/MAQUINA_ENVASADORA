//****************** MÁQUINA ENVASADORA PARA BOTELLAS *********************//
//******************INSTITUTO TECNOLÓGICO DE IZTAPALAPA ********************//
//**************BY: TAMARA GONZALEZ, JOHANA LÓPEZ & FREDY HERNÁNDEZ ********************//
//************************ INGENIERIA MECATRÓNICA *********************************//

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int stepPin = 3; 
const int dirPin = 4;
int sensor1 = 7;
int sensor2 = 8;
int sensor3 = 9;
int led = A1;
int w_pump = 12;
int a_pump = 2;
int cap_m = 5;
int conv = 6;
int buzzer = 10;
int startt = 11;

void setup() 
{
  lcd.begin();
 lcd.backlight();
 lcd.clear();
   lcd.setCursor(0,0); 
  lcd.print("MAQUINA ENVASADORA"); 
   lcd.setCursor(0,1); 
  lcd.print("*** INICIAR *** ");

  

pinMode(startt, INPUT_PULLUP);
 pinMode (buzzer,OUTPUT);
 pinMode (sensor1, INPUT);
 pinMode (sensor2, INPUT);
 pinMode (sensor3, INPUT);
 pinMode (w_pump,OUTPUT);
 pinMode (a_pump,OUTPUT);
 pinMode (cap_m,OUTPUT);
  pinMode (conv,OUTPUT);
 pinMode (led,OUTPUT);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

    while(digitalRead(sensor1) == HIGH) 
  {
   digitalWrite(dirPin,LOW); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000);

    
 if(digitalRead(sensor1) == LOW)
 break;
}
}

void loop()
{
 if (digitalRead (startt) == HIGH)
 {
    while(1)
{
  
  lcd.setCursor(0,1); 
  lcd.print("                    "); 
  lcd.setCursor(0,2); 
  lcd.print("                    "); 
  
 
    while(digitalRead(sensor1) == HIGH) 
  {
  digitalWrite(dirPin,LOW); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000);

 if(digitalRead(sensor1) == LOW)
 break;
  }

  digitalWrite(led,HIGH); 
  tone(buzzer, 1000);
  delay(500);
  noTone(buzzer);
  digitalWrite(led,LOW);
 digitalWrite(conv,HIGH); 
 delay(1000);
 digitalWrite(conv,LOW);
 delay(100);

 digitalWrite(dirPin,LOW); 
  for(int x = 0; x < 45; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2500);
  }

if(digitalRead(sensor2) == LOW)
   {
  digitalWrite(led,HIGH); 
  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);
  digitalWrite(led,LOW);
   lcd.setCursor(0,1); 
  lcd.print("      LLENANDO...    "); 
  
   digitalWrite(w_pump,HIGH); 
   delay(2200);   //============================================FIN DE LLENADO===================//
   digitalWrite(w_pump,LOW);
     digitalWrite(led,HIGH); 
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
  digitalWrite(led,LOW);
  delay(1000);
     lcd.setCursor(0,1); 
  lcd.print("      ENRROSCANDO...    "); 

    digitalWrite(dirPin,LOW); 
  for(int x = 0; x < 185; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2500);
  }
   digitalWrite(cap_m,HIGH);
    
  digitalWrite(led,HIGH); 
  tone(buzzer, 1000);
  delay(300);
  noTone(buzzer);
  digitalWrite(led,LOW);

   digitalWrite(a_pump,HIGH);
   delay(1500);
   digitalWrite(a_pump,LOW);
    delay(1000);
  digitalWrite(cap_m,LOW); 

     lcd.setCursor(0,1); 
  lcd.print("                    "); 

      digitalWrite(dirPin,LOW);
  for(int x = 0; x < 45; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2500);
  }
if(digitalRead(sensor3) == LOW)
   {
    delay(500);
   }
else
{
   lcd.setCursor(0,1); 
  lcd.print("       ERROR!       "); 
   lcd.setCursor(0,2); 
  lcd.print("  SIN TAPA   "); 
  
  digitalWrite(led,HIGH); 
  tone(buzzer, 1500);
  delay(2000);
  noTone(buzzer);
  digitalWrite(led,LOW);


  lcd.print("       ERROR!       "); 
   lcd.setCursor(0,2); 
  lcd.print("POR FAVOR REMOVER B");
   
  digitalWrite(dirPin,LOW);
  for(int x = 0; x < 30; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2500);
  } 

   break;
}

    while(digitalRead(sensor1) == HIGH) 
  {
  digitalWrite(dirPin,LOW); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2000);

    
 if(digitalRead(sensor1) == LOW)
 break;
  
   } 
 }
else
{
   lcd.setCursor(0,1); 
  lcd.print("       ERROR!       "); 
   lcd.setCursor(0,2); 
  lcd.print(" SIN BOTELLA "); 
  
  digitalWrite(led,HIGH); 
  tone(buzzer, 1500);
  delay(1000);
  noTone(buzzer);
  digitalWrite(led,LOW);
  digitalWrite(dirPin,HIGH); 
  for(int x = 0; x < 45; x++) 
  {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(2500); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(2500);
  } 
  break;
}
}
}
}