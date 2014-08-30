

/*
Author: wangeq33@gmail.com,copyright.
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

char val;
int ledpin=13;
int relaypin=12;
int sensorPin = A0; 
int sensorValue = 0;
int delaycount =0;

unsigned long time,timeDelay;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(relaypin,OUTPUT);
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  time = millis();
}
void loop()
{
  val = mySerial.read();
  if(val=='q')
  {
    setOn();
  }
  else if(val=='w')
  {
    setOff();
  }
  
  delayInfo();  
}

void setOn()
{
    digitalWrite(ledpin,HIGH);
    Serial.println("LED ON!");
    digitalWrite(relaypin,LOW);
}

void setOff()
{
    digitalWrite(ledpin,LOW);
    Serial.println("LED OFF!");
    digitalWrite(relaypin,HIGH);
}

void delayInfo()
{
  timeDelay = millis();
  
  if (timeDelay - time >= 2000)
  {
    sensorValue = analogRead(sensorPin); 
    Serial.println("TH:"+sensorValue);
    Serial.println(sensorValue);
    //mySerial.write("hello\r\n");
    mySerial.write(sensorValue);
    if (sensorValue>100)
    {
      //mySerial.write('q');
      setOn();
    }
    else
    {
      //mySerial.write('w');
      setOff();
    }
    time = timeDelay;
  }
}
