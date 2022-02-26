#include "SoftwareSerial.h"



SoftwareSerial device(5,6);   // RX-TX
char c;                       // input...
const int inputPin1  = 10;    // Pin 15 of L293D IC
const int inputPin2  = 11;    // Pin 10 of L293D IC
//Motor B- right(n=2)
const int inputPin3  = 9;   // Pin  7 of L293D IC
const int inputPin4  = 8;   // Pin  2 of L293D IC

// control speeds using enable pinss....!
// put connecting wires across en pins
void setup() 
{
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    Serial.begin(9600);
    device.begin(9600);   // Check baud rate
    
    
}

void loop() 
{
    //forward(0);
   // /*
    if (device.available())
  {
    c=device.read();   // char inputs
    Serial.println(c);
    if (c=='F')
    forward(0);
    else if (c=='B')
    backward(0);
    else if (c=='L'|c=='G')
    left_f();
    else if (c=='R'|c=='I')
    right_f();
    else if (c=='H')
    left_b();
    else if (c=='J')
    right_b();
    //else if (c=='S')    // Should I?
    //no_motion();
  }

  else 
  //Serial.println("@NO input blue");
   
    delay(100);
//  */
}

void forward(int n) // clockwise...
{
  if (n==1)     // left
  {
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);
  
      
  }
  if (n==2)     // right
  {
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
  
  
  }
    
  if (n==0)   // both
  {
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);
  
  }
  
}

void backward(int n) // anti-clockwise...
{
  if (n==1)     // left
  {
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);
  
      
  }
  if (n==2)     // right
  {
    digitalWrite(inputPin4, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
  
  
  }
    
  if (n==0)   // both
  {
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin4, HIGH);
    digitalWrite(inputPin3, LOW);
  
  }
  
}

void no_motion()    // Actually a better option might be to add a delay()...
{
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin4, LOW);
    digitalWrite(inputPin3, LOW);
   
}

// No point is defining speeds with your driver

// void left() is simply forward(1)

void left_f()   // or simply left()
{
  forward(1);
}

void right_f()
{
  forward(2);
}

void left_b()
{
  backward(1);
}

void right_b()
{
  backward(2);
}

void input(char c)
{
    // Add if's here
    //Serial.println(c);
    

    
    // s for stop...

  
  
}

// Add for ultrasonic sensor
