// HC-05 Bluetooth Module

#include <SoftwareSerial.h> 
SoftwareSerial dev(6, 7); // RX | TX (For Arduino)
const int LED =  LED_BUILTIN;

void setup() 
{   
 Serial.begin(9600);  // Serial
 dev.begin(9600);    // Bluetooth Device
 Serial.println("Connecting..."); 

 pinMode(LED, OUTPUT);
} 
void loop() 
{ 
 if (dev.available()) {
   char input = dev.read(); 
   Serial.println(input);

   if (input == 'y') 
   { 
     digitalWrite(LED, HIGH); 
     Serial.println("LED On"); 
     delay(500);
   } 
   else if (input == 'n') 
   { 
     digitalWrite(LED, LOW); 
     Serial.println("LED Off"); 
     delay(500);
   } 
  }  
}
