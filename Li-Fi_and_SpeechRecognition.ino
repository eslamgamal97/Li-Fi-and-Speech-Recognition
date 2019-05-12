#include <LiquidCrystal.h>   //LCD Library

LiquidCrystal lcd(2,3,4,5,6,7);    //initialize LCD 
String voice;    //voice to store commands
char c;        // to read characters from serial monitor 

void setup() {
  Serial.begin(9600);    //initialize baud rate must be equal to baud rate of Bluetooth module
  lcd.begin(16,2);       //initialize LCD 
}   

void loop() {
  while(Serial.available())    //read the command from user
  {
    delay(10);   
    lcd.clear();
    c = Serial.read();
    voice += c;
  } 
  if(voice.length() > 0)    //print the command on LCD display
  { 
    Serial.println(voice);   //print on Serial Monitor
    if(voice == "clear")     //to clear the LCD by "clear" Command
    { 
      lcd.clear();
    }
    else                    
    {
      lcd.print(voice);      //print command on LCD
    } 
    voice = "";      //to stop sending the same command on Serial monitor without the user talking so voice.length = 0
  }
}
