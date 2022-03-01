const int TrigPin = 8;
const int EchoPin = 12;

void setup() {
  // put your setup code here, to run once:
pinMode(TrigPin, OUTPUT);  // Trigger Pin
pinMode(EchoPin, INPUT);  // Echo Pin
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(TrigPin, LOW);
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

float duration = pulseIn(EchoPin, HIGH);
float distance = duration*0.034/2;
Serial.println(distance);
if(distance>=10&& distance<=20)
{//digitalWrite(13,HIGH);
tone(13,4000,50);
 //delay(5000);
}

}
