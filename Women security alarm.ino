
 #include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3 );

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,11, 4,5,6,7);
//char msg;
//int inByte=0;
int button=8;


//void ultra();
void SendMessage1();
void SendMessage2();


void setup()
{
  
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
 
 mySerial.begin(9600);
 Serial.begin(9600); 
mySerial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(5, 0);
lcd.print("SMART");
lcd.setCursor(0, 1);
lcd.print("SECURITY DEVICE");

mySerial.print("AT+CMGF=1\r");
delay(100);
mySerial.print("AT+CNMI=2,2,0,0,0\r");
delay(100);

pinMode(button,INPUT);
   
   }

void loop()
{
  
    if(digitalRead(button)==HIGH)
   {
    //Serial.println("button press");
   //void ultra();
//   lcd.begin(16, 2);
//   lcd.setCursor(1, 0);
//   lcd.print("I AM IN DANGER!");
//   lcd.print("SMART");
//lcd.setCursor(0, 1);
//lcd.print("SECURITY DEVICE");
   delay(2500);
    SendMessage1();
    SendMessage2();
    
   
    
    delay(1000);
   
     
  }
} 
   
     
 void SendMessage1()
{
   
        mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
   
      mySerial.println("AT+CMGS=\"+919014531862\"\r"); // Replace x with mobile number
     delay(1000);
     
     mySerial.println("I AM IN DANGER ,PLEASE HELP me!");// The SMS text you want to send
     delay(100);
    
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(1000);

      
}
void SendMessage2()
{
  
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     
      mySerial.println("AT+CMGS=\"+917013334127\"\r"); // Replace x with mobile number
     delay(1000);
     
     mySerial.println("I AM IN DANGER ,PLEASE HELP me!");// The SMS text you want to send
     delay(100);
    
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
    delay(1000);
  while(1){}
      
    
}
